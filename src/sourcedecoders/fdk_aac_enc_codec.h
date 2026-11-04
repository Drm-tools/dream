/******************************************************************************\
 * Description:
 *  DRM AAC encoder (AAC, HE-AAC, HE-AAC v2) using the DRM object types of
 *  the encoder of rafael2k's fdk-aac (https://github.com/rafael2k/fdk-aac, vendored in
 *  libs/fdk-aac, see its README.DRM.md). Decoding is done by FdkAacCodec.
 *
 *  CanEncode() asks the linked library whether it has those object types, so with a
 *  stock fdk-aac there is simply no AAC encoder.
 *
 *  The frames are what AudioSourceEncoder expects from an AAC codec: one CRC byte
 *  followed by the frame, as the DRM super frame wants them.
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
typedef struct AACENCODER* FDK_AACENC_HANDLE;

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
    virtual bool CanEncode(CAudioParam::EAudCod eAudioCoding);
    virtual bool EncOpen(const CAudioParam& AudioParam, unsigned long& lNumSampEncIn, unsigned long& lMaxBytesEncOut);
    virtual int Encode(CVector<_SAMPLE>& vecsEncInData, unsigned long lNumSampEncIn, CVector<uint8_t>& vecsEncOutData, unsigned long lMaxBytesEncOut);
    virtual void EncClose();
    virtual void EncSetBitrate(int iBitRate);
    virtual void EncUpdate(CAudioParam&) {}
    virtual std::string fileName(const CParameter&) const { return ""; }

private:
    bool InitEncoder(int iBitRate);
    FDK_AACENC_HANDLE hEncoder;
    int iAot;
    int iSampleRate;
    int iChannels;
    unsigned iFrameLength;
    unsigned iInputChannels;
    std::vector<short> inBuf;
    std::vector<unsigned char> outBuf;
};

#endif
