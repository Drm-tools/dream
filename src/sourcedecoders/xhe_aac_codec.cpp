/******************************************************************************\
 * xHE-AAC (USAC) encoder for DRM using the fdk-xhe-aac library.
 * See xhe_aac_codec.h.
 *
 * This program is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation; either version 2 of the License, or (at your option) any later
 * version.
\******************************************************************************/

#include "xhe_aac_codec.h"
#include <cmath>
#include <cstring>
#include <iostream>

using namespace std;

namespace {

class BitReader {
public:
    BitReader(const uint8_t* d, size_t nbits) : data(d), total(nbits), pos(0), bad(false) {}
    unsigned get(int n) {
        unsigned v = 0;
        for (int i = 0; i < n; i++) {
            if (pos >= total) { bad = true; v <<= 1; continue; }
            v = (v << 1) | ((data[pos >> 3] >> (7 - (pos & 7))) & 1u);
            pos++;
        }
        return v;
    }
    void skip(size_t n) { if (pos + n > total) { bad = true; pos = total; } else pos += n; }
    size_t remaining() const { return total - pos; }
    unsigned esc(int a, int b, int c) {
        unsigned v = get(a);
        if (v == (1u << a) - 1) {
            unsigned add = get(b);
            v += add;
            if (c && add == (1u << b) - 1) v += get(c);
        }
        return v;
    }
    bool ok() const { return !bad; }
private:
    const uint8_t* data; size_t total; size_t pos; bool bad;
};

class BitWriter {
public:
    BitWriter() : nbits(0) {}
    void put(unsigned v, int n) {
        for (int i = n - 1; i >= 0; i--) {
            if ((nbits & 7) == 0) bytes.push_back(0);
            if ((v >> i) & 1u) bytes.back() |= uint8_t(0x80 >> (nbits & 7));
            nbits++;
        }
    }
    void esc(unsigned v, int a, int b, int c) {
        unsigned ma = (1u << a) - 1;
        if (v < ma) { put(v, a); return; }
        put(ma, a); v -= ma;
        unsigned mb = (1u << b) - 1;
        if (v < mb) { put(v, b); return; }
        put(mb, b); v -= mb;
        put(v, c);
    }
    vector<uint8_t> bytes; size_t nbits;
};

} // namespace

namespace XheDrm {

bool AscToDrmStaticConfig(const vector<uint8_t>& asc, unsigned ascBits,
                          double loudness, vector<uint8_t>& drmConfig, ConfigInfo& info)
{
    BitReader r(asc.data(), ascBits);
    unsigned aot = r.get(5);
    if (aot == 31) aot = 32 + r.get(6);
    unsigned sf = r.get(4);
    if (sf == 15) r.get(24);
    r.get(4); /* channelConfiguration */
    if (aot != 42 || !r.ok()) { cerr << "xHE-AAC: unexpected audio object type " << aot << endl; return false; }

    /* UsacConfig() */
    unsigned usf = r.get(5);
    if (usf == 0x1f) r.get(24);
    if (usf != 3) { cerr << "xHE-AAC: encoder output rate is not 48 kHz" << endl; return false; }
    unsigned csfl = r.get(3);
    unsigned chIdx = r.get(5);
    if (csfl < 1 || csfl > 4 || (chIdx != 1 && chIdx != 2)) {
        cerr << "xHE-AAC: unsupported coreSbrFrameLengthIndex " << csfl << " channels " << chIdx << endl;
        return false;
    }
    const bool sbr = csfl >= 2;
    unsigned numElements = r.esc(4, 8, 16) + 1;

    info.leading.clear();
    info.stereo = (chIdx == 2);
    info.coreSbrFrameLengthIndex = int(csfl);
    info.stripBitsEstimate = 0;

    struct Ext { unsigned type, len; bool hasDef; unsigned defLen; bool frag; vector<uint8_t> cfg; };
    vector<Ext> trailing;
    BitWriter w;
    w.put(csfl - 1, 2);
    bool mainSeen = false;

    for (unsigned i = 0; i < numElements && r.ok(); i++) {
        unsigned type = r.get(2);
        if (type == 3) { /* UsacExtElementConfig */
            Ext e;
            e.type = r.esc(4, 8, 16);
            e.len = r.esc(4, 8, 16);
            e.hasDef = r.get(1) != 0;
            e.defLen = e.hasDef ? r.esc(8, 16, 0) + 1 : 0;
            e.frag = r.get(1) != 0;
            for (unsigned k = 0; k < e.len; k++) e.cfg.push_back(uint8_t(r.get(8)));
            if (!mainSeen) {
                LeadingExt l; l.hasDefault = e.hasDef; l.defaultLen = e.defLen; l.frag = e.frag;
                info.leading.push_back(l);
                info.stripBitsEstimate += (e.hasDef && e.defLen) ? 2 + 8 * e.defLen + (e.frag ? 2 : 0) : 1;
            } else {
                if (e.type != 0 /* fill */ || e.len != 0) {
                    cerr << "xHE-AAC: unsupported trailing extension element " << e.type << endl;
                    return false;
                }
                trailing.push_back(e);
            }
            continue;
        }
        if (type == 2 || mainSeen) { cerr << "xHE-AAC: unsupported element layout" << endl; return false; }
        mainSeen = true;
        const bool cpe = (type == 1);
        if (cpe != info.stereo) { cerr << "xHE-AAC: element type does not match channel count" << endl; return false; }

        if (r.get(1)) { cerr << "xHE-AAC: tw_mdct not allowed" << endl; return false; }
        w.put(r.get(1), 1); /* noiseFilling */
        if (sbr) {
            unsigned harm = r.get(1), inter = r.get(1), pvc = r.get(1);
            w.put(harm, 1); w.put(inter, 1); w.put(pvc, 1);
            /* SbrDfltHeader(): copied verbatim */
            w.put(r.get(8), 8);
            unsigned e1 = r.get(1), e2 = r.get(1);
            w.put(e1, 1); w.put(e2, 1);
            if (e1) w.put(r.get(5), 5);
            if (e2) w.put(r.get(6), 6);
            if (cpe) {
                unsigned sc = r.get(2);
                w.put(sc, 2);
                if (sc > 0) {
                    /* Mps212Config: ISO -> DRM */
                    unsigned freqRes = r.get(3), gain = r.get(3), ts = r.get(2), decorr = r.get(2);
                    unsigned hr = r.get(1), pc = r.get(1), opp = r.get(1);
                    unsigned ott = opp ? r.get(5) : 0;
                    if (decorr != 0 || (ts != 0 && ts != 3)) {
                        cerr << "xHE-AAC: MPS212 tools (decorr " << decorr << ", temp shape " << ts
                             << ") not allowed in DRM" << endl;
                        return false;
                    }
                    if (harm && sc > 1) { cerr << "xHE-AAC: harmonic SBR with residual not allowed in DRM" << endl; return false; }
                    w.put(freqRes, 3); w.put(gain, 3); w.put(ts == 3 ? 1 : 0, 1);
                    w.put(hr, 1); w.put(pc, 1); w.put(opp, 1);
                    if (opp) w.put(ott, 5);
                    if (sc > 1) {
                        w.put(r.get(5), 5); /* bsResidualBands */
                        w.put(r.get(1), 1); /* bsPseudoLr */
                    }
                }
            }
        } else if (cpe) {
            /* no SBR: stereoConfigIndex is 0 and not transmitted */
        }
    }
    if (!r.ok() || !mainSeen) { cerr << "xHE-AAC: could not parse the encoder's UsacConfig" << endl; return false; }

    /* extension elements after the SCE/CPE, these appear in this order in each frame */
    w.esc(unsigned(trailing.size()), 2, 4, 8);
    for (size_t i = 0; i < trailing.size(); i++) {
        w.esc(trailing[i].type, 4, 8, 16);
        w.esc(trailing[i].len, 4, 8, 16);
        w.put(trailing[i].hasDef ? 1 : 0, 1);
        if (trailing[i].hasDef) w.esc(trailing[i].defLen - 1, 8, 16, 0);
        w.put(trailing[i].frag ? 1 : 0, 1);
    }

    /* usacConfigExtensionPresent + UsacConfigExtensionDrm() with the loudness */
    if (!std::isnan(loudness)) {
        double v = (loudness + 57.75) / 0.25;
        int iv = int(std::floor(v + 0.5));
        if (iv < 0) iv = 0;
        if (iv > 255) iv = 255;
        w.put(1, 1);
        w.esc(0, 2, 4, 8);  /* numConfigExtensions - 1 */
        w.esc(0, 3, 5, 8);  /* ID_CONFIG_EXT_LOUDNESS_INFO_DRM */
        w.esc(1, 3, 5, 8);  /* length in bytes */
        w.put(unsigned(iv), 8);
    } else {
        w.put(0, 1);
    }
    drmConfig = w.bytes; /* zero padded to a full byte */
    return true;
}

bool StripAccessUnit(const ConfigInfo& info, const uint8_t* au, size_t n, vector<uint8_t>& out)
{
    BitReader r(au, n * 8);
    BitWriter w;
    w.put(r.get(1), 1); /* usacIndependencyFlag */
    for (size_t i = 0; i < info.leading.size(); i++) {
        if (!r.get(1)) continue; /* usacExtElementPresent */
        unsigned len;
        if (r.get(1)) { /* usacExtElementUseDefaultLength */
            len = info.leading[i].defaultLen;
        } else {
            len = r.get(8);
            if (len == 255) len += r.get(16) - 2;
        }
        if (len > 0) {
            if (info.leading[i].frag) r.get(2);
            r.skip(size_t(len) * 8);
        }
        if (!r.ok()) return false;
    }
    while (r.remaining() >= 8) w.put(r.get(8), 8);
    unsigned rest = unsigned(r.remaining());
    if (rest) w.put(r.get(int(rest)), int(rest));
    out = w.bytes;
    return r.ok();
}

} // namespace XheDrm

#ifdef HAVE_LIBFDK_XHE_AAC
#include <fdk-xhe-aac/xHEAACEnc.h>

#define XHE_CHECK(call, what) do { int r_ = (call); if (r_ >= IIS_XHEAACENC_ERROR_FIRST) { \
    cerr << "xHE-AAC encoder: " << what << " failed, code " << r_ << endl; return false; } } while (0)

XheAacCodec::XheAacCodec() : hEncoder(nullptr), iChannels(2), dLoudness(-23.0) {}
XheAacCodec::~XheAacCodec() { EncClose(); }

string XheAacCodec::DecGetVersion() { return ""; }

string XheAacCodec::EncGetVersion()
{
    const char* v = IIS_xHEAACEnc_GetVersionInfoStr();
    return v ? v : "fdk-xhe-aac";
}

bool XheAacCodec::EncOpen(const CAudioParam& AudioParam, unsigned long& lNumSampEncIn, unsigned long& lMaxBytesEncOut)
{
    iChannels = (AudioParam.eAudioMode == CAudioParam::AM_MONO) ? 1 : 2;
    lNumSampEncIn = 0;
    lMaxBytesEncOut = 1;
    return true;
}

void XheAacCodec::EncClose()
{
    if (hEncoder != nullptr) {
        IIS_xHEAACEnc_Delete(hEncoder);
        hEncoder = nullptr;
    }
    pending.clear();
}

bool XheAacCodec::OpenEncoder(int channels, int iBitRate, int& iFrameSamples, vector<uint8_t>& asc, unsigned& ascBits)
{
    if (hEncoder != nullptr) {
        IIS_xHEAACEnc_Delete(hEncoder);
        hEncoder = nullptr;
    }
    IIS_XHEAACENC_CONFIG_INSTANCE_HANDLE cfg = nullptr;
    XHE_CHECK(IIS_xHEAACEnc_Config_Open(&cfg, 48000,
              channels == 1 ? IIS_XHEAACENC_CHANNELCONFIG_MONO : IIS_XHEAACENC_CHANNELCONFIG_STEREO), "config open");
    int r = 0;
    r = IIS_xHEAACEnc_Config_AddParamValueInt(cfg, IIS_XHEAACENC_PARAMETER_BITRATE, iBitRate);
    if (r == 0) r = IIS_xHEAACEnc_Config_AddParamValueInt(cfg, IIS_XHEAACENC_PARAMETER_BITRATEMODE, IIS_XHEAACENC_BITRATEMODE_CBR);
    if (r == 0) r = IIS_xHEAACEnc_Config_AddParamValueInt(cfg, IIS_XHEAACENC_PARAMETER_AOT, IIS_XHEAACENC_AOT_USAC);
    if (r == 0) r = IIS_xHEAACEnc_Config_AddParamValueInt(cfg, IIS_XHEAACENC_PARAMETER_TRANSPORTFORMAT, IIS_XHEAACENC_TRANSPORTFORMAT_RAW);
    if (r == 0) r = IIS_xHEAACEnc_Config_AddParamValueInt(cfg, IIS_XHEAACENC_PARAMETER_STREAMID, 0);
    /* Independent frames only on demand: periodic IPFs would carry the whole config and break CBR */
    if (r == 0) r = IIS_xHEAACEnc_Config_AddParamValueInt(cfg, IIS_XHEAACENC_PARAMETER_RAP_OCCURRENCE, IIS_XHEAACENC_RAP_OCCURRENCE_ON_DEMAND);
    if (r == 0) r = IIS_xHEAACEnc_Config_AddParamValueFloat(cfg, IIS_XHEAACENC_PARAMETER_LIVE_LOUDNESS_LEVEL, float(dLoudness));
    if (r >= IIS_XHEAACENC_ERROR_FIRST) { cerr << "xHE-AAC encoder: parameter error " << r << endl; IIS_xHEAACEnc_Config_Delete(cfg); return false; }
    r = IIS_xHEAACEnc_Config_Finalize(cfg);
    if (r >= IIS_XHEAACENC_ERROR_FIRST) {
        cerr << "xHE-AAC encoder: configuration rejected (bit rate " << iBitRate << ", " << channels
             << " channels), code " << r << endl;
        IIS_xHEAACEnc_Config_Delete(cfg);
        return false;
    }
    r = IIS_xHEAACEnc_Open(&hEncoder, cfg);
    IIS_xHEAACEnc_Config_Delete(cfg);
    if (r >= IIS_XHEAACENC_ERROR_FIRST) { cerr << "xHE-AAC encoder: open failed, code " << r << endl; hEncoder = nullptr; return false; }

    XHE_CHECK(IIS_xHEAACEnc_GetParam(hEncoder, IIS_XHEAACENC_PARAMETER_FRAMESAMPLES, IIS_XHEAACENC_PARAM_INT, &iFrameSamples, sizeof(int)), "get frame size");
    IIS_XHEAACENC_ASCINFO ai;
    XHE_CHECK(IIS_xHEAACEnc_GetAscInfo(hEncoder, &ai), "get ASC");
    ascBits = ai.ascSizeBits;
    asc.assign(ai.ascBuffer, ai.ascBuffer + (ai.ascSizeBits + 7) / 8);
    return true;
}

bool XheAacCodec::EncStartStreaming(const CAudioParam& AudioParam, int iSuperFrameBytes, vector<uint8_t>& staticConfig)
{
    iChannels = (AudioParam.eAudioMode == CAudioParam::AM_MONO) ? 1 : 2;
    if (iSuperFrameBytes > 4096) {
        /* the frame border index in the directory has 12 bits */
        cerr << "xHE-AAC: audio super frame of " << iSuperFrameBytes << " bytes is too large for the frame border directory" << endl;
        return false;
    }
    /* This encoder only accepts bit rates in steps of 2 kbit/s (at least 16 kbit/s for
       stereo, 12 kbit/s for mono). The difference to the capacity is padded. */
    const int iRateStep = 2000;
    int iBitRate = (iSuperFrameBytes * 8 * 5 / 2 / iRateStep) * iRateStep; /* first guess */
    int iFrameSamples = 0;
    vector<uint8_t> asc;
    unsigned ascBits = 0;

    bool settled = false;
    for (int attempt = 0; attempt < 4 && !settled; attempt++) {
        if (!OpenEncoder(iChannels, iBitRate, iFrameSamples, asc, ascBits))
            return false;
        if (!XheDrm::AscToDrmStaticConfig(asc, ascBits, dLoudness, staticConfig, info))
            return false;
        /* Share of the super frame left for the access units: the header (2 bytes) and,
           for every frame, its directory entry (2) and CRC (2) */
        const double framesPerSF = 0.4 * 48000.0 / iFrameSamples;
        if (framesPerSF > 15.0) {
            /* ETSI ES 201 980 5.3: at most 15 audio frames (directory entries) per super frame */
            cerr << "xHE-AAC: the encoder uses " << iFrameSamples << " sample frames at this bit rate, which gives more than 15 audio frames per super frame" << endl;
            return false;
        }
        const double budget = (iSuperFrameBytes - 2) / framesPerSF - 4.0;
        /* The leading extension elements are removed again, so ask for that much more.
           Stay slightly below what fits: the packer pads the difference, while a rate
           above the capacity could not be sent. */
        const double stripBytes = std::floor(info.stripBitsEstimate / 8.0);
        const double target = budget + stripBytes - 0.5;
        int newRate = int(std::floor(target * 8.0 * 48000.0 / iFrameSamples / iRateStep)) * iRateStep;
        const int minRate = (iChannels == 1) ? 12000 : 16000;
        if (newRate < minRate) {
            cerr << "xHE-AAC: the stream bit rate is too low for this encoder (minimum "
                 << minRate / 1000 << " kbit/s for " << iChannels << " channel(s))" << endl;
            return false;
        }
        if (newRate == iBitRate) settled = true;
        else iBitRate = newRate;
    }
    if (!settled) { /* frame size kept changing with the rate: use the last rate */
        if (!OpenEncoder(iChannels, iBitRate, iFrameSamples, asc, ascBits)) return false;
        if (!XheDrm::AscToDrmStaticConfig(asc, ascBits, dLoudness, staticConfig, info)) return false;
    }
    cerr << "xHE-AAC encoder: " << iChannels << " channel(s), " << iBitRate << " bit/s, "
         << iFrameSamples << " samples per frame at 48 kHz, static config " << staticConfig.size() << " bytes" << endl;
    pending.clear();
    return true;
}

bool XheAacCodec::EncProcess(const _SAMPLE* pcm, size_t n, vector<vector<uint8_t> >& frames)
{
    if (hEncoder == nullptr) return false;
    pending.reserve(pending.size() + n);
    for (size_t i = 0; i < n; i++)
        pending.push_back(float(pcm[i]) * (1.0f / 32768.0f));

    for (;;) {
        int next = 0;
        if (IIS_xHEAACEnc_GetParam(hEncoder, IIS_XHEAACENC_PARAMETER_SAMPLES_NEXT, IIS_XHEAACENC_PARAM_INT, &next, sizeof(int)) >= IIS_XHEAACENC_ERROR_FIRST)
            return false;
        if (next < 0 || pending.size() < size_t(next)) break;
        uint8_t out[20480];
        int outSize = 0;
        IIS_XHEAACENC_AUINFO au;
        int r = IIS_xHEAACEnc_EncodeFrame(hEncoder, pending.data(), next, out, &outSize, int(sizeof(out)), &au);
        if (r >= IIS_XHEAACENC_ERROR_FIRST) { cerr << "xHE-AAC encoder: encode failed, code " << r << endl; return false; }
        pending.erase(pending.begin(), pending.begin() + next);
        if (outSize > 0) {
            vector<uint8_t> stripped;
            if (!XheDrm::StripAccessUnit(info, out, size_t(outSize), stripped)) {
                cerr << "xHE-AAC encoder: could not parse access unit" << endl;
                continue;
            }
            frames.push_back(stripped);
        }
        if (next == 0 && outSize == 0) break;
    }
    return true;
}
#endif
