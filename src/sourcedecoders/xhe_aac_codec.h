/******************************************************************************\
 * Description:
 *  xHE-AAC (USAC) encoder for DRM using the fdk-xhe-aac library.
 *
 *  The library produces plain MPEG-D USAC access units plus an AudioSpecificConfig.
 *  DRM (ETSI ES 201 980 clause 5.3) needs a different packaging, so this class
 *  - converts the UsacConfig into the DRM "xHEAACStaticConfig()" for SDC type 9,
 *  - removes the extension elements which the DRM static config does not declare
 *    (audio pre-roll, uniDRC) from the start of every access unit.
 *  Audio frame CRC and the audio super frame are added by XHEAACSuperFrameEncoder.
 ******************************************************************************
 * This program is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation; either version 2 of the License, or (at your option) any later
 * version.
\******************************************************************************/

#ifndef XHE_AAC_CODEC_H_
#define XHE_AAC_CODEC_H_

#include "AudioCodec.h"
#include <vector>

struct xheaacenc_instance_handle;

/* Pure functions, kept separate so they can be unit tested without the library */
namespace XheDrm {
struct LeadingExt { bool hasDefault; unsigned defaultLen; bool frag; };
struct ConfigInfo {
    std::vector<LeadingExt> leading; /* extension elements ahead of the SCE/CPE */
    bool stereo;
    int coreSbrFrameLengthIndex;
    unsigned stripBitsEstimate;
};
/* Convert the bits of an AudioSpecificConfig (AOT 42) to DRM xHEAACStaticConfig().
   loudness is the program loudness in LKFS, or NaN to omit. */
bool AscToDrmStaticConfig(const std::vector<uint8_t>& asc, unsigned ascBits,
                          double loudness, std::vector<uint8_t>& drmConfig, ConfigInfo& info);
/* Remove the leading extension elements from a USAC access unit */
bool StripAccessUnit(const ConfigInfo& info, const uint8_t* au, size_t n, std::vector<uint8_t>& out);
}

class XheAacCodec : public CAudioCodec
{
public:
    XheAacCodec();
    virtual ~XheAacCodec();
    /* Decoder: not supported here, FdkAacCodec decodes xHE-AAC */
    virtual std::string DecGetVersion();
    virtual bool CanDecode(CAudioParam::EAudCod) { return false; }
    virtual bool DecOpen(const CAudioParam&, int&) { return false; }
    virtual EDecError Decode(const std::vector<uint8_t>&, uint8_t, CVector<_REAL>&, CVector<_REAL>&) { return DECODER_ERROR_UNKNOWN; }
    virtual void DecClose() {}
    virtual void DecUpdate(CAudioParam&) {}
    /* Encoder */
    virtual std::string EncGetVersion();
    virtual bool CanEncode(CAudioParam::EAudCod eAudioCoding) { return eAudioCoding == CAudioParam::AC_xHE_AAC; }
    virtual bool EncOpen(const CAudioParam& AudioParam, unsigned long& lNumSampEncIn, unsigned long& lMaxBytesEncOut);
    virtual int Encode(CVector<_SAMPLE>&, unsigned long, CVector<uint8_t>&, unsigned long) { return 0; }
    virtual void EncClose();
    virtual void EncSetBitrate(int) {}
    virtual void EncUpdate(CAudioParam&) {}
    virtual bool EncIsStreaming() const { return true; }
    virtual bool EncStartStreaming(const CAudioParam& AudioParam, int iSuperFrameBytes, std::vector<uint8_t>& staticConfig);
    virtual int EncStreamingSampleRate() const { return 48000; }
    virtual bool EncProcess(const _SAMPLE* pcm, size_t iNumInterleaved, std::vector<std::vector<uint8_t> >& frames);
    virtual std::string fileName(const CParameter&) const { return ""; }

    /* program loudness in LKFS: signalled in the static config and used as the
       encoder's live loudness level */
    void SetLoudness(double dLKFS) { dLoudness = dLKFS; }

protected:
    bool OpenEncoder(int iChannels, int iBitRate, int& iFrameSamples, std::vector<uint8_t>& asc, unsigned& ascBits);
    bool OpenEncoderAtOrBelow(int iChannels, int& iBitRate, int iStep, int& iFrameSamples, std::vector<uint8_t>& asc, unsigned& ascBits);
    xheaacenc_instance_handle* hEncoder;
    int iChannels;
    XheDrm::ConfigInfo info;
    std::vector<float> pending;
    double dLoudness;
};

#endif
