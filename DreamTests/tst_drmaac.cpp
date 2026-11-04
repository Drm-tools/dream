#include <QtTest>
#include <cmath>
#include <vector>
#include "../src/GlobalDefinitions.h"
#include "../src/sourcedecoders/fdk_aac_enc_codec.h"
#include "../src/sourcedecoders/fdk_aac_codec.h"

using namespace std;

/* DRM AAC encoder (vendored fdk-aac) against the DRM decoder of the system fdk-aac,
   both through Dream's codec classes. A frame is [CRC byte][data]. */
class DrmAacTest : public QObject
{
    Q_OBJECT
private slots:
    void roundTrip_data();
    void roundTrip();
    void corruptedCrc();
};

struct Result {
    long frames, ok, failed;
    double a440, a1250, a3000;
    int sampleRate;
    vector<vector<uint8_t> > coded;
};

static CAudioParam makeParam(CAudioParam::EAudioMode mode, bool sbr, CAudioParam::EAudSamRat rate)
{
    CAudioParam ap;
    ap.eAudioCoding = CAudioParam::AC_AAC;
    ap.eAudioMode = mode;
    ap.eSBRFlag = sbr ? CAudioParam::SB_USED : CAudioParam::SB_NOT_USED;
    ap.eAudioSamplRate = rate;
    return ap;
}

static bool run(const CAudioParam& ap, int bitrate, int nFrames, Result& res)
{
    FdkAacEncCodec enc;
    unsigned long perFrame = 0, maxOut = 0;
    if (!enc.EncOpen(ap, perFrame, maxOut))
        return false;
    enc.EncSetBitrate(bitrate);
    const int ch = (ap.eAudioMode == CAudioParam::AM_MONO) ? 1 : 2;
    const unsigned long perChannel = perFrame / unsigned(ch);
    const int encRate = int((ap.eAudioSamplRate == CAudioParam::AS_12KHZ ? 12000 : 24000) *
                            ((ap.eSBRFlag == CAudioParam::SB_USED || ap.eAudioMode == CAudioParam::AM_P_STEREO) ? 2 : 1));

    FdkAacCodec dec;
    int outRate = 0;
    if (!dec.DecOpen(ap, outRate))
        return false;
    res.sampleRate = outRate;
    res.frames = res.ok = res.failed = 0;
    vector<double> out;
    CVector<_SAMPLE> in;
    in.Init(int(perFrame));
    CVector<uint8_t> coded;
    coded.Init(int(maxOut));
    long t = 0;
    for (int f = 0; f < nFrames; f++) {
        for (unsigned long i = 0; i < perChannel; i++, t++) {
            const double v = 0.25 * sin(t * 2 * M_PI * 440.0 / encRate) + 0.15 * sin(t * 2 * M_PI * 1250.0 / encRate);
            for (int c = 0; c < ch; c++)
                in[int(i) * ch + c] = _SAMPLE(v * 26000);
        }
        const int n = enc.Encode(in, perFrame, coded, maxOut);
        if (n <= 0)
            continue; /* start up delay */
        vector<uint8_t> frame(&coded[0] + 1, &coded[0] + n);
        res.coded.push_back(vector<uint8_t>(&coded[0], &coded[0] + n));
        CVector<_REAL> L, R;
        res.frames++;
        if (dec.Decode(frame, coded[0], L, R) == CAudioCodec::DECODER_ERROR_OK) {
            res.ok++;
            if (f > 12)
                for (int s = 0; s < L.Size(); s++)
                    out.push_back(L[s]);
        }
        else if (f > 6)
            res.failed++;
    }
    if (out.size() < 20000)
        return false;
    auto amp = [&](double fq) {
        double re = 0, im = 0;
        const size_t n = 19200;
        for (size_t i = 0; i < n; i++) {
            const double w = 2 * M_PI * fq * double(i) / double(outRate);
            re += out[i] * cos(w);
            im += out[i] * sin(w);
        }
        return 2.0 * sqrt(re * re + im * im) / double(n);
    };
    res.a440 = amp(440);
    res.a1250 = amp(1250);
    res.a3000 = amp(3000);
    return true;
}

void DrmAacTest::roundTrip_data()
{
    QTest::addColumn<int>("mode");
    QTest::addColumn<bool>("sbr");
    QTest::addColumn<int>("rate");
    QTest::addColumn<int>("bitrate");
    QTest::addColumn<int>("outRate");
    QTest::newRow("AAC mono 24 kHz, 24 kbit/s") << int(CAudioParam::AM_MONO) << false << int(CAudioParam::AS_24KHZ) << 24000 << 24000;
    QTest::newRow("AAC mono 12 kHz, 8 kbit/s") << int(CAudioParam::AM_MONO) << false << int(CAudioParam::AS_12KHZ) << 8000 << 12000;
    QTest::newRow("AAC stereo 24 kHz, 48 kbit/s") << int(CAudioParam::AM_STEREO) << false << int(CAudioParam::AS_24KHZ) << 48000 << 24000;
    QTest::newRow("HE-AAC mono 12 kHz, 8 kbit/s") << int(CAudioParam::AM_MONO) << true << int(CAudioParam::AS_12KHZ) << 8000 << 24000;
    QTest::newRow("HE-AAC mono 24 kHz, 20 kbit/s") << int(CAudioParam::AM_MONO) << true << int(CAudioParam::AS_24KHZ) << 20000 << 48000;
    QTest::newRow("HE-AAC stereo 24 kHz, 24 kbit/s") << int(CAudioParam::AM_STEREO) << true << int(CAudioParam::AS_24KHZ) << 24000 << 48000;
    QTest::newRow("HE-AAC v2 (PS) 12 kHz, 12 kbit/s") << int(CAudioParam::AM_P_STEREO) << true << int(CAudioParam::AS_12KHZ) << 12000 << 24000;
    QTest::newRow("HE-AAC v2 (PS) 24 kHz, 24 kbit/s") << int(CAudioParam::AM_P_STEREO) << true << int(CAudioParam::AS_24KHZ) << 24000 << 48000;
}

void DrmAacTest::roundTrip()
{
    QFETCH(int, mode);
    QFETCH(bool, sbr);
    QFETCH(int, rate);
    QFETCH(int, bitrate);
    QFETCH(int, outRate);
    Result r;
    QVERIFY(run(makeParam(CAudioParam::EAudioMode(mode), sbr, CAudioParam::EAudSamRat(rate)), bitrate, 60, r));
    QCOMPARE(r.sampleRate, outRate);
    QVERIFY(r.frames >= 55);
    QCOMPARE(r.failed, 0L); /* the first frames after the start may fail */
    /* both tones at about the level fed in (6500 and 3900), nothing at 3 kHz;
       FdkAacCodec halves the level of mono */
    const double scale = (mode == int(CAudioParam::AM_MONO)) ? 0.5 : 1.0;
    QVERIFY2(r.a440 > 5000 * scale && r.a440 < 8500 * scale, qPrintable(QString("440 Hz amplitude %1").arg(r.a440)));
    QVERIFY2(r.a1250 > 2800 * scale && r.a1250 < 5200 * scale, qPrintable(QString("1250 Hz amplitude %1").arg(r.a1250)));
    QVERIFY2(r.a3000 < 400, qPrintable(QString("3000 Hz amplitude %1").arg(r.a3000)));
}

void DrmAacTest::corruptedCrc()
{
    /* the byte in front of a frame protects its side information: the decoder has to
       notice when it does not match */
    CAudioParam ap = makeParam(CAudioParam::AM_MONO, true, CAudioParam::AS_12KHZ);
    Result r;
    QVERIFY(run(ap, 8000, 30, r));
    FdkAacCodec dec;
    int rate = 0;
    QVERIFY(dec.DecOpen(ap, rate));
    long bad = 0, good = 0;
    for (size_t i = 0; i < r.coded.size(); i++) {
        vector<uint8_t> frame(r.coded[i].begin() + 1, r.coded[i].end());
        CVector<_REAL> L, R;
        const uint8_t crc = uint8_t(r.coded[i][0] ^ 0x55);
        if (dec.Decode(frame, crc, L, R) == CAudioCodec::DECODER_ERROR_OK)
            good++;
        else
            bad++;
    }
    QVERIFY2(bad > good, qPrintable(QString("accepted %1 of %2 frames with a wrong CRC").arg(good).arg(good + bad)));
}

QTEST_APPLESS_MAIN(DrmAacTest)

#include "tst_drmaac.moc"
