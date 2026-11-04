#include <QtTest>
#include <vector>
#include <cmath>
#include "../src/GlobalDefinitions.h"
#include "../src/util/CRC.h"
#include "../src/MSC/xheaacsuperframe.h"
#include "../src/MSC/xheaacsuperframeenc.h"
#include "../src/sourcedecoders/xhe_aac_codec.h"
#ifdef HAVE_LIBFDK_AAC
# include "../src/sourcedecoders/fdk_aac_codec.h"
#endif

using namespace std;

static vector<uint8_t> fromHex(const char* h)
{
    vector<uint8_t> v;
    for (size_t i = 0; h[i] && h[i + 1]; i += 2) {
        unsigned x = 0;
        sscanf(h + i, "%2x", &x);
        v.push_back(uint8_t(x));
    }
    return v;
}

static uint16_t crc16(const uint8_t* d, size_t n)
{
    CCRC crc;
    crc.Reset(16);
    for (size_t i = 0; i < n; i++)
        crc.AddByte(d[i]);
    return uint16_t(crc.GetCRC());
}

class XheAacTest : public QObject
{
    Q_OBJECT
private slots:
    void staticConfigStereo();
    void staticConfigMono();
    void stripAccessUnit();
    void superFrameRoundTrip();
    void superFrameRoundTrip_data();
    void encodeDecode();
    void encodeDecodeLowRate();
};

/* ASCs as produced by fdk-xhe-aac (AOT 42, 48 kHz, CBR); the expected bytes are
   the DRM xHEAACStaticConfig() which the fdk decoder accepts */
static const char* kAscStereo = "f94643423cc0d3c920200000124b66810204060b5c880209020809080009fc0180011080055fc0180c2819080081ff200602860842002064006020000515429e6c00ae40000500020009700462cb00";
static const char* kAscMono = "f94623813cc0d3c7202000000a4b264880209020809080009fc0100221000abf80230a064200207fc80114304210010320022000010d177002b900001400080025c0118b2c00";

void XheAacTest::staticConfigStereo()
{
    vector<uint8_t> cfg;
    XheDrm::ConfigInfo info;
    QVERIFY(XheDrm::AscToDrmStaticConfig(fromHex(kAscStereo), 627, -23.0, cfg, info));
    const uint8_t expect[] = {0x62, 0xa8, 0x53, 0xe4, 0x00, 0x80, 0xc5, 0x80};
    QCOMPARE(cfg, vector<uint8_t>(expect, expect + sizeof(expect)));
    QVERIFY(info.stereo);
    QCOMPARE(info.coreSbrFrameLengthIndex, 2);
    QCOMPARE(int(info.leading.size()), 2);
    /* the DRM coreSbrFrameLengthIndex is the MPEG one minus 1 */
    QCOMPARE(int(cfg[0] >> 6), 1);
}

void XheAacTest::staticConfigMono()
{
    vector<uint8_t> cfg;
    XheDrm::ConfigInfo info;
    QVERIFY(XheDrm::AscToDrmStaticConfig(fromHex(kAscMono), 553, -23.0, cfg, info));
    const uint8_t expect[] = {0xe1, 0xa2, 0xea, 0x00, 0x40, 0x62, 0xc0};
    QCOMPARE(cfg, vector<uint8_t>(expect, expect + sizeof(expect)));
    QVERIFY(!info.stereo);
    QCOMPARE(info.coreSbrFrameLengthIndex, 4);
    /* without loudness the extension flag is 0 and the config is not longer */
    vector<uint8_t> cfg2;
    QVERIFY(XheDrm::AscToDrmStaticConfig(fromHex(kAscMono), 553, std::nan(""), cfg2, info));
    QVERIFY(cfg2.size() <= cfg.size());
}

void XheAacTest::stripAccessUnit()
{
    XheDrm::ConfigInfo info;
    XheDrm::LeadingExt pre = {false, 0, false};     /* audio pre-roll: no default length */
    XheDrm::LeadingExt drc = {true, 2, false};      /* uniDRC: default length 2 bytes */
    info.leading.push_back(pre);
    info.leading.push_back(drc);
    /* independency flag 1, pre-roll absent (0), uniDRC present (1) default length (1)
       + 16 bits payload, then 5 bits of core data "10110": 1 0 11 <16 bits> 10110 */
    const char bits[] = "1" "0" "11" "1010101010101010" "10110";
    vector<uint8_t> au((sizeof(bits) - 1 + 7) / 8, 0);
    for (size_t i = 0; i < sizeof(bits) - 1; i++)
        if (bits[i] == '1') au[i / 8] |= uint8_t(0x80 >> (i % 8));
    vector<uint8_t> out;
    QVERIFY(XheDrm::StripAccessUnit(info, au.data(), au.size(), out));
    /* independency flag, the core bits and the alignment padding of the original
       access unit: 1 10110 + 7 zero bits -> 1101 1000 0000 0000 */
    QCOMPARE(out.size(), size_t(2));
    QCOMPARE(int(out[0]), 0xd8);
    QCOMPARE(int(out[1]), 0x00);
}

void XheAacTest::superFrameRoundTrip_data()
{
    QTest::addColumn<int>("superFrameBytes");
    QTest::addColumn<int>("minFrame");
    QTest::addColumn<int>("maxFrame");
    QTest::newRow("small frames") << 600 << 40 << 140;
    QTest::newRow("frames about 1/9 super frame") << 1044 << 90 << 140;
    QTest::newRow("big frames") << 1500 << 300 << 900;
    QTest::newRow("one frame spans several super frames") << 300 << 700 << 900;
    QTest::newRow("fixed size, borders drift through all positions") << 997 << 111 << 111;
}

void XheAacTest::superFrameRoundTrip()
{
    QFETCH(int, superFrameBytes);
    QFETCH(int, minFrame);
    QFETCH(int, maxFrame);

    XHEAACSuperFrameEncoder mux;
    mux.init(unsigned(superFrameBytes));
    CAudioParam ap;
    ap.eAudioCoding = CAudioParam::AC_xHE_AAC;
    XHEAACSuperFrame rx;
    rx.init(ap, unsigned(superFrameBytes));

    vector<vector<uint8_t> > pushed, received;
    unsigned seed = 12345;
    auto next = [&seed]() { seed = seed * 1664525u + 1013904223u; return seed >> 8; };
    /* a frame of 2 bytes can never be a whole access unit, so stay above that */
    for (int sf = 0; sf < 300; sf++) {
        while (mux.queuedFrames() < 4) {
            vector<uint8_t> au(size_t(minFrame + int(next() % unsigned(maxFrame - minFrame + 1))));
            for (auto& b : au) b = uint8_t(next());
            pushed.push_back(au);
            mux.push(au);
        }
        vector<uint8_t> asf;
        mux.build(asf);
        QCOMPARE(asf.size(), size_t(superFrameBytes));

        CVectorEx<_BINARY> bits;
        bits.Init(superFrameBytes * 8);
        bits.ResetBitAccess();
        for (auto c : asf) bits.Enqueue(c, 8);
        bits.ResetBitAccess();
        QVERIFY2(rx.parse(bits), qPrintable(QString("super frame %1 did not parse").arg(sf)));
        for (unsigned i = 0; i < rx.getNumFrames(); i++) {
            vector<uint8_t> f;
            uint8_t crc;
            rx.getFrame(f, crc, i);
            received.push_back(f);
        }
    }
    /* the first parsed frame is the (empty) one completing "the previous frame" */
    QVERIFY(received.size() + 8 > pushed.size());
    const size_t n = min(received.size(), pushed.size()) - 2;
    QVERIFY(n > 50);
    size_t padded = 0;
    for (size_t i = 0; i < n; i++) {
        const vector<uint8_t>& f = received[i];
        QVERIFY2(f.size() >= pushed[i].size() + 2, qPrintable(QString("frame %1 too short").arg(i)));
        /* the frame is the access unit, optional zero padding, and the CRC over both */
        const size_t body = f.size() - 2;
        QVERIFY2(equal(pushed[i].begin(), pushed[i].end(), f.begin()), qPrintable(QString("frame %1 differs").arg(i)));
        for (size_t k = pushed[i].size(); k < body; k++)
            QCOMPARE(int(f[k]), 0);
        if (body != pushed[i].size()) padded++;
        const uint16_t c = crc16(f.data(), body);
        QCOMPARE(int(f[body]), int(c >> 8));
        QCOMPARE(int(f[body + 1]), int(c & 0xff));
    }
    /* padding is only needed when the queue runs dry, it must not be the norm */
    QVERIFY(padded < n / 2 + 1);
}

static void roundTrip(int ch, int T, bool& started)
{
#if defined(HAVE_LIBFDK_XHE_AAC) && defined(HAVE_LIBFDK_AAC)
    {
        CAudioParam ap;
        ap.eAudioCoding = CAudioParam::AC_xHE_AAC;
        ap.eAudioMode = ch == 1 ? CAudioParam::AM_MONO : CAudioParam::AM_STEREO;
        ap.eAudioSamplRate = CAudioParam::AS_48KHZ;
        XheAacCodec enc;
        unsigned long a, b;
        QVERIFY(enc.EncOpen(ap, a, b));
        vector<uint8_t> cfg;
        started = enc.EncStartStreaming(ap, T, cfg);
        if (!started)
            return;
        ap.xHE_AAC_config = cfg;

        /* the receiver gets the configuration through SDC data entity type 9 */
        vector<uint8_t> t9 = ap.getType9Bytes();
        CVector<_BINARY> tb;
        tb.Init(int(t9.size()) * 8);
        tb.ResetBitAccess();
        for (auto c : t9) tb.Enqueue(c, 8);
        tb.ResetBitAccess();
        CAudioParam rxParam;
        rxParam.setFromType9Bits(tb, unsigned(t9.size()));
        QCOMPARE(int(rxParam.eAudioCoding), int(CAudioParam::AC_xHE_AAC));
        QCOMPARE(int(rxParam.eAudioMode), int(ap.eAudioMode));
        QCOMPARE(rxParam.xHE_AAC_config, cfg);

        XHEAACSuperFrameEncoder mux;
        mux.init(unsigned(T));
        XHEAACSuperFrame rxsf;
        rxsf.init(rxParam, unsigned(T));
        FdkAacCodec dec;
        int rate = 0;
        QVERIFY(dec.DecOpen(rxParam, rate));
        QCOMPARE(rate, 48000);

        vector<_SAMPLE> pcm(size_t(19200 * ch));
        vector<double> out;
        long t = 0, ok = 0, bad = 0;
        for (int sf = 0; sf < 40; sf++) {
            for (int i = 0; i < 19200; i++, t++) {
                const double v = 0.25 * sin(t * 2 * M_PI * 440.0 / 48000.0) + 0.15 * sin(t * 2 * M_PI * 1250.0 / 48000.0);
                for (int c = 0; c < ch; c++) pcm[size_t(i * ch + c)] = _SAMPLE(v * 16000);
            }
            vector<vector<uint8_t> > frames;
            QVERIFY(enc.EncProcess(pcm.data(), pcm.size(), frames));
            for (auto& f : frames) mux.push(f);
            vector<uint8_t> asf;
            mux.build(asf);
            QCOMPARE(asf.size(), size_t(T));
            CVectorEx<_BINARY> bits;
            bits.Init(T * 8);
            bits.ResetBitAccess();
            for (auto c : asf) bits.Enqueue(c, 8);
            bits.ResetBitAccess();
            QVERIFY(rxsf.parse(bits));
            for (unsigned i = 0; i < rxsf.getNumFrames(); i++) {
                vector<uint8_t> f;
                uint8_t crc;
                rxsf.getFrame(f, crc, i);
                CVector<_REAL> L, R;
                if (dec.Decode(f, 0, L, R) == CAudioCodec::DECODER_ERROR_OK) {
                    ok++;
                    if (sf >= 5)
                        for (int s = 0; s < L.Size(); s++) out.push_back(L[s]);
                }
                else if (sf >= 3)
                    bad++;
            }
        }
        QVERIFY(ok > 100);
        QCOMPARE(bad, 0L); /* only the first frames after start up may fail */
        auto amp = [&out](double f) {
            double re = 0, im = 0;
            for (size_t i = 0; i < out.size(); i++) {
                const double w = 2 * M_PI * f * double(i) / 48000.0;
                re += out[i] * cos(w);
                im += out[i] * sin(w);
            }
            return 2.0 * sqrt(re * re + im * im) / double(out.size());
        };
        /* the encoder levels the loudness, so only check that both tones are there */
        QVERIFY2(amp(440.0) > 300.0, "440 Hz tone missing");
        QVERIFY2(amp(1250.0) > 150.0, "1250 Hz tone missing");
        QVERIFY2(amp(3000.0) < amp(440.0) / 5, "unexpected energy at 3 kHz");
    }
#else
    (void)ch; (void)T; started = false;
#endif
}


void XheAacTest::encodeDecode()
{
#if defined(HAVE_LIBFDK_XHE_AAC) && defined(HAVE_LIBFDK_AAC)
    for (int ch = 1; ch <= 2; ch++) {
        bool started = false;
        roundTrip(ch, ch == 1 ? 900 : 1200, started);
        QVERIFY(started);
    }
#else
    QSKIP("needs fdk-aac and fdk-xhe-aac");
#endif
}

void XheAacTest::encodeDecodeLowRate()
{
#if defined(HAVE_LIBFDK_XHE_AAC) && defined(HAVE_LIBFDK_AAC)
    /* about 8 kbit/s mono: only with libs/patches/fdk-xhe-aac-low-bitrate.patch applied */
    bool started = false;
    roundTrip(1, 500, started);
    if (!started)
        QSKIP("the fdk-xhe-aac library does not go below 12 kbit/s (low bit rate patch not applied)");
#else
    QSKIP("needs fdk-aac and fdk-xhe-aac");
#endif
}

QTEST_APPLESS_MAIN(XheAacTest)

#include "tst_xheaac.moc"
