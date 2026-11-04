/******************************************************************************\
 * Description:
 *  DRM AAC encoder (AAC, HE-AAC, HE-AAC v2) using the vendored fdk-aac encoder
 *  in libs/fdk-aac-odr (see its README.dream.md). Encoder only: decoding is done
 *  by FdkAacCodec with the system fdk-aac.
 *
 *  The frames are what AudioSourceEncoder expects from an AAC codec: one CRC byte
 *  followed by the frame, as the DRM super frame wants them.
 *
 *  This header must not be mixed with the system <fdk-aac/...> headers: the
 *  vendored library has its own, which are only used in the .cpp file.
 ******************************************************************************
 * This program is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation; either version 2 of the License, or (at your option) any later
 * version.
\******************************************************************************/

#ifndef FDK_AAC_ENC_CODEC_H_
#define FDK_AAC_ENC_CODEC_H_

#include "AudioCodec.h"

struct AACENCODER;

class FdkAacEncCodec : public CAudioCodec
{
public:
    FdkAacEncCodec();
    virtual ~FdkAacEncCodec();
    /* Decoder: not supported here */
    virtual std::string DecGetVersion() { return ""; }
    virtual bool CanDecode(CAudioParam::EAudCod) { return false; }
    virtual bool DecOpen(const CAudioParam&, int&) { return false; }
    virtual EDecError Decode(const std::vector<uint8_t>&, uint8_t, CVector<_REAL>&, CVector<_REAL>&) { return DECODER_ERROR_UNKNOWN; }
    virtual void DecClose() {}
    virtual void DecUpdate(CAudioParam&) {}
    /* Encoder */
    virtual std::string EncGetVersion();
    virtual bool CanEncode(CAudioParam::EAudCod eAudioCoding) { return eAudioCoding == CAudioParam::AC_AAC; }
    virtual bool EncOpen(const CAudioParam& AudioParam, unsigned long& lNumSampEncIn, unsigned long& lMaxBytesEncOut);
    virtual int Encode(CVector<_SAMPLE>& vecsEncInData, unsigned long lNumSampEncIn, CVector<uint8_t>& vecsEncOutData, unsigned long lMaxBytesEncOut);
    virtual void EncClose();
    virtual void EncSetBitrate(int iBitRate);
    virtual void EncUpdate(CAudioParam&) {}
    virtual std::string fileName(const CParameter&) const { return ""; }

private:
    bool InitEncoder(int iBitRate);
    AACENCODER* hEncoder;
    int iAot;
    int iSampleRate;
    int iChannels;
    unsigned iFrameLength;
    unsigned iInputChannels;
    std::vector<short> inBuf;
    std::vector<unsigned char> outBuf;
};

#endif
