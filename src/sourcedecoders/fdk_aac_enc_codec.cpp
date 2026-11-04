/******************************************************************************\
 * DRM AAC encoder with the DRM object types of fdk-aac. See fdk_aac_enc_codec.h.
 *
 * This program is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation; either version 2 of the License, or (at your option) any later
 * version.
\******************************************************************************/

#include "fdk_aac_enc_codec.h"
#include <fdk-aac/aacenc_lib.h>
#include <iostream>

using namespace std;

/* AOT_DRM_AAC, AOT_DRM_SBR and AOT_DRM_MPEG_PS of FDK_audio.h */
enum { DRM_AAC = 143, DRM_SBR = 144, DRM_MPEG_PS = 145 };

/* A stock fdk-aac refuses these object types, the one of the fork accepts them */
bool FdkAacEncCodec::CanEncode(CAudioParam::EAudCod eAudioCoding)
{
    if (eAudioCoding != CAudioParam::AC_AAC)
        return false;
    static int iProbed = -1;
    if (iProbed < 0) {
        HANDLE_AACENCODER h = nullptr;
        iProbed = 0;
        if (aacEncOpen(&h, 0x01 | 0x02 | 0x04 | 0x08, 2) == AACENC_OK) {
            iProbed = (aacEncoder_SetParam(h, AACENC_AOT, DRM_SBR) == AACENC_OK &&
                       aacEncoder_SetParam(h, AACENC_AOT, DRM_MPEG_PS) == AACENC_OK) ? 1 : 0;
            aacEncClose(&h);
        }
    }
    return iProbed == 1;
}

FdkAacEncCodec::FdkAacEncCodec() :
    hEncoder(nullptr), iAot(0), iSampleRate(0), iChannels(1), iFrameLength(0), iInputChannels(1)
{
}

FdkAacEncCodec::~FdkAacEncCodec()
{
    EncClose();
}

string FdkAacEncCodec::EncGetVersion()
{
    return "fdk-aac (ODR, DRM)";
}

bool FdkAacEncCodec::InitEncoder(int iBitRate)
{
    AACENC_ERROR e;
#define SETP(p, v) do { e = aacEncoder_SetParam(hEncoder, p, UINT(v)); \
    if (e != AACENC_OK) { cerr << "DRM AAC encoder: parameter " #p " = " << (v) << " refused (" << hex << int(e) << dec << ")" << endl; return false; } } while (0)
    SETP(AACENC_AOT, iAot);
    SETP(AACENC_SAMPLERATE, iSampleRate);
    SETP(AACENC_CHANNELMODE, iChannels == 1 ? MODE_1 : MODE_2);
    SETP(AACENC_BITRATE, iBitRate);
    SETP(AACENC_TRANSMUX, TT_MP4_RAW);
    e = aacEncEncode(hEncoder, nullptr, nullptr, nullptr, nullptr);
    if (e != AACENC_OK) {
        cerr << "DRM AAC encoder: could not initialise at " << iBitRate << " bit/s (" << hex << int(e) << dec << ")" << endl;
        return false;
    }
    AACENC_InfoStruct info;
    if (aacEncInfo(hEncoder, &info) != AACENC_OK)
        return false;
    iFrameLength = info.frameLength;
    iInputChannels = info.inputChannels;
    outBuf.resize(info.maxOutBufBytes + 16);
    inBuf.resize(size_t(iFrameLength) * iInputChannels);
    return true;
}

bool FdkAacEncCodec::EncOpen(const CAudioParam& AudioParam, unsigned long& lNumSampEncIn, unsigned long& lMaxBytesEncOut)
{
    EncClose();
    if (aacEncOpen(&hEncoder, 0x01 | 0x02 | 0x04 | 0x08, 2) != AACENC_OK) {
        hEncoder = nullptr;
        return false;
    }
    /* the SDC audio sampling rate is the AAC rate, SBR doubles it */
    int iCoreRate = (AudioParam.eAudioSamplRate == CAudioParam::AS_12KHZ) ? 12000 : 24000;
    const bool bSbr = (AudioParam.eSBRFlag == CAudioParam::SB_USED) ||
                      (AudioParam.eAudioMode == CAudioParam::AM_P_STEREO);
    iSampleRate = bSbr ? 2 * iCoreRate : iCoreRate;
    iChannels = (AudioParam.eAudioMode == CAudioParam::AM_MONO) ? 1 : 2;
    if (AudioParam.eAudioMode == CAudioParam::AM_P_STEREO)
        iAot = DRM_MPEG_PS;
    else
        iAot = bSbr ? DRM_SBR : DRM_AAC;

    /* The frame length does not depend on the bit rate, but the bit rate has to
       be one the encoder accepts to initialise: find one */
    static const int rates[] = {64000, 48000, 32000, 24000, 16000, 12000, 8000};
    bool ok = false;
    for (size_t i = 0; i < sizeof(rates) / sizeof(rates[0]) && !ok; i++)
        ok = InitEncoder(rates[i]);
    if (!ok) {
        EncClose();
        return false;
    }
    lNumSampEncIn = iFrameLength * iInputChannels;
    lMaxBytesEncOut = outBuf.size();
    return true;
}

void FdkAacEncCodec::EncSetBitrate(int iBitRate)
{
    if (hEncoder == nullptr)
        return;
    if (!InitEncoder(iBitRate))
        cerr << "DRM AAC encoder: bit rate " << iBitRate << " not possible for this configuration" << endl;
}

int FdkAacEncCodec::Encode(CVector<_SAMPLE>& vecsEncInData, unsigned long lNumSampEncIn, CVector<uint8_t>& vecsEncOutData, unsigned long lMaxBytesEncOut)
{
    if (hEncoder == nullptr)
        return 0;
    if (lNumSampEncIn > inBuf.size())
        lNumSampEncIn = inBuf.size();
    for (unsigned long i = 0; i < lNumSampEncIn; i++)
        inBuf[i] = vecsEncInData[int(i)];

    void* inPtr[] = { inBuf.data() };
    INT inId[] = { IN_AUDIO_DATA };
    INT inSize[] = { INT(inBuf.size() * sizeof(short)) };
    INT inElSize[] = { INT(sizeof(short)) };
    void* outPtr[] = { outBuf.data() };
    INT outId[] = { OUT_BITSTREAM_DATA };
    INT outSize[] = { INT(outBuf.size()) };
    INT outElSize[] = { 1 };
    AACENC_BufDesc inDesc = { 1, inPtr, inId, inSize, inElSize };
    AACENC_BufDesc outDesc = { 1, outPtr, outId, outSize, outElSize };
    AACENC_InArgs inArgs = { INT(lNumSampEncIn), 0 };
    AACENC_OutArgs outArgs;

    AACENC_ERROR e = aacEncEncode(hEncoder, &inDesc, &outDesc, &inArgs, &outArgs);
    if (e != AACENC_OK) {
        cerr << "DRM AAC encoder error " << hex << int(e) << dec << endl;
        return 0;
    }
    if (outArgs.numOutBytes <= 0)
        return 0; /* start up delay */
    if ((unsigned long)outArgs.numOutBytes > lMaxBytesEncOut) {
        cerr << "DRM AAC encoder: output buffer too small" << endl;
        return 0;
    }
    for (int i = 0; i < outArgs.numOutBytes; i++)
        vecsEncOutData[i] = outBuf[size_t(i)];
    return outArgs.numOutBytes;
}

void FdkAacEncCodec::EncClose()
{
    if (hEncoder != nullptr) {
        aacEncClose(&hEncoder);
        hEncoder = nullptr;
    }
}
