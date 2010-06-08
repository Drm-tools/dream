/******************************************************************************\
 * Technische Universitaet Darmstadt, Institut fuer Nachrichtentechnik
 * Copyright (c) 2001
 *
 * Author(s):
 *	Volker Fischer
 *
 * Description:
 *	Audio source encoder/decoder
 *
 ******************************************************************************
 *
 * This program is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation; either version 2 of the License, or (at your option) any later
 * version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more 1111
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 *
\******************************************************************************/

#include "AudioSourceDecoder.h"
#include <iostream>

/* CRC lookup table for G8 polynome in DRM standard (from faad) */

static const uint8_t crc_table_G8[256] = {
    0x0, 0x1d, 0x3a, 0x27, 0x74, 0x69, 0x4e, 0x53,
    0xe8, 0xf5, 0xd2, 0xcf, 0x9c, 0x81, 0xa6, 0xbb,
    0xcd, 0xd0, 0xf7, 0xea, 0xb9, 0xa4, 0x83, 0x9e,
    0x25, 0x38, 0x1f, 0x2, 0x51, 0x4c, 0x6b, 0x76,
    0x87, 0x9a, 0xbd, 0xa0, 0xf3, 0xee, 0xc9, 0xd4,
    0x6f, 0x72, 0x55, 0x48, 0x1b, 0x6, 0x21, 0x3c,
    0x4a, 0x57, 0x70, 0x6d, 0x3e, 0x23, 0x4, 0x19,
    0xa2, 0xbf, 0x98, 0x85, 0xd6, 0xcb, 0xec, 0xf1,
    0x13, 0xe, 0x29, 0x34, 0x67, 0x7a, 0x5d, 0x40,
    0xfb, 0xe6, 0xc1, 0xdc, 0x8f, 0x92, 0xb5, 0xa8,
    0xde, 0xc3, 0xe4, 0xf9, 0xaa, 0xb7, 0x90, 0x8d,
    0x36, 0x2b, 0xc, 0x11, 0x42, 0x5f, 0x78, 0x65,
    0x94, 0x89, 0xae, 0xb3, 0xe0, 0xfd, 0xda, 0xc7,
    0x7c, 0x61, 0x46, 0x5b, 0x8, 0x15, 0x32, 0x2f,
    0x59, 0x44, 0x63, 0x7e, 0x2d, 0x30, 0x17, 0xa,
    0xb1, 0xac, 0x8b, 0x96, 0xc5, 0xd8, 0xff, 0xe2,
    0x26, 0x3b, 0x1c, 0x1, 0x52, 0x4f, 0x68, 0x75,
    0xce, 0xd3, 0xf4, 0xe9, 0xba, 0xa7, 0x80, 0x9d,
    0xeb, 0xf6, 0xd1, 0xcc, 0x9f, 0x82, 0xa5, 0xb8,
    0x3, 0x1e, 0x39, 0x24, 0x77, 0x6a, 0x4d, 0x50,
    0xa1, 0xbc, 0x9b, 0x86, 0xd5, 0xc8, 0xef, 0xf2,
    0x49, 0x54, 0x73, 0x6e, 0x3d, 0x20, 0x7, 0x1a,
    0x6c, 0x71, 0x56, 0x4b, 0x18, 0x5, 0x22, 0x3f,
    0x84, 0x99, 0xbe, 0xa3, 0xf0, 0xed, 0xca, 0xd7,
    0x35, 0x28, 0xf, 0x12, 0x41, 0x5c, 0x7b, 0x66,
    0xdd, 0xc0, 0xe7, 0xfa, 0xa9, 0xb4, 0x93, 0x8e,
    0xf8, 0xe5, 0xc2, 0xdf, 0x8c, 0x91, 0xb6, 0xab,
    0x10, 0xd, 0x2a, 0x37, 0x64, 0x79, 0x5e, 0x43,
    0xb2, 0xaf, 0x88, 0x95, 0xc6, 0xdb, 0xfc, 0xe1,
    0x5a, 0x47, 0x60, 0x7d, 0x2e, 0x33, 0x14, 0x9,
    0x7f, 0x62, 0x45, 0x58, 0xb, 0x16, 0x31, 0x2c,
    0x97, 0x8a, 0xad, 0xb0, 0xe3, 0xfe, 0xd9, 0xc4,
};

/* CRC checker from faad */

static uint8_t check_crc(unsigned char * buffer, uint16_t len)
{
    int bytes=len, rem=0;
    unsigned int CRC;
    unsigned int r=255;  /* Initialize to all ones */

    /* CRC polynome used x^8 + x^4 + x^3 + x^2 +1 */
	#define GPOLY 0435

	size_t i=0;

    CRC = (unsigned int) (~buffer[i++]) & 0xFF;

    //bytes = len >> 3;
    //rem = len & 0x7;

    for (; bytes > 0; bytes--)
    {
        r = crc_table_G8[( r ^ buffer[i++] ) & 0xFF];
    }
    for (; rem > 0; rem--)
    {
        r = ( (r << 1) ^ (( ( buffer[i++]  & 1) ^ ((r >> 7) & 1)) * GPOLY )) & 0xFF;
    }

    if (r != CRC)
    {
        return 28;
    } else {
        return 0;
    }
}

// dummy AAC Decoder implementation if dll not found

NeAACDecHandle NEAACDECAPI NeAACDecOpenDummy(void) { return NULL; }
void NEAACDECAPI NeAACDecCloseDummy(NeAACDecHandle h) { }

char NEAACDECAPI NeAACDecInitDRMDummy(NeAACDecHandle* h, unsigned long samplerate, unsigned char channels)
{
	return 1; /* error */
}

void* NEAACDECAPI NeAACDecDecodeDummy(NeAACDecHandle h,NeAACDecFrameInfo* hInfo,unsigned char * buffer,unsigned long buffer_size)
{
	hInfo->error = 1; // check_crc(buffer, buffer_size);
	return NULL;
}

/* Implementation *************************************************************/
void
CAudioSourceDecoder::ProcessDataInternal(CParameter & ReceiverParam)
{
	int i, j;
	_BOOLEAN bCurBlockOK;
	_BOOLEAN bGoodValues;

	NeAACDecFrameInfo DecFrameInfo;
	short *psDecOutSampleBuf;

	bGoodValues = FALSE;

	ReceiverParam.Lock();
	ReceiverParam.vecbiAudioFrameStatus.Init(0);
	ReceiverParam.vecbiAudioFrameStatus.ResetBitAccess();
	ReceiverParam.Unlock();

	/* Check if something went wrong in the initialization routine */
	if (DoNotProcessData == TRUE)
	{
		return;
	}

	/* Text Message ********************************************************** */
	/* Total frame size depends on whether text message is used or not */
	if (bTextMessageUsed == TRUE)
	{
		/* Decode last for bytes of input block for text message */
		for (i = 0; i < SIZEOF__BYTE * NUM_BYTES_TEXT_MESS_IN_AUD_STR; i++)
			vecbiTextMessBuf[i] = (*pvecInputData)[iTotalFrameSize + i];

		TextMessage.Decode(vecbiTextMessBuf);
	}

	/* Audio data header parsing ********************************************* */
	/* Check if audio shall not be decoded */
	if (DoNotProcessAudDecoder == TRUE)
	{
		return;
	}

	/* Reset bit extraction access */
	(*pvecInputData).ResetBitAccess();

	/* Check which audio coding type is used */
	if (eAudioCoding == CAudioParam::AC_AAC)
	{
		/* AAC super-frame-header ------------------------------------------- */
		int iPrevBorder = 0;
		for (i = 0; i < iNumBorders; i++)
		{
			/* Frame border in bytes (12 bits) */
			const int iFrameBorder = (*pvecInputData).Separate(12);

			/* The lenght is difference between borders */
			veciFrameLength[i] = iFrameBorder - iPrevBorder;
			iPrevBorder = iFrameBorder;
		}

		/* Byte-alignment (4 bits) in case of 10 audio frames */
		if (iNumBorders == 9)
			(*pvecInputData).Separate(4);

		/* Frame length of last frame */
		veciFrameLength[iNumBorders] = iAudioPayloadLen - iPrevBorder;

		/* Check if frame length entries represent possible values */
		bGoodValues = TRUE;
		for (i = 0; i < iNumAudioFrames; i++)
		{
			if ((veciFrameLength[i] < 0) ||
				(veciFrameLength[i] > iMaxLenOneAudFrame))
			{
				bGoodValues = FALSE;
			}
		}

		if (bGoodValues == TRUE)
		{
			/* Higher-protected part */
			for (i = 0; i < iNumAudioFrames; i++)
			{
				/* Extract higher protected part bytes (8 bits per byte) */
				for (j = 0; j < iNumHigherProtectedBytes; j++)
					audio_frame[i][j] = _BINARY((*pvecInputData).Separate(8));

				/* Extract CRC bits (8 bits) */
				aac_crc_bits[i] = _BINARY((*pvecInputData).Separate(8));
			}

			/* Lower-protected part */
			for (i = 0; i < iNumAudioFrames; i++)
			{
				/* First calculate frame length, derived from higher protected
				   part frame length and total size */
				const int iNumLowerProtectedBytes =
					veciFrameLength[i] - iNumHigherProtectedBytes;

				/* Extract lower protected part bytes (8 bits per byte) */
				for (j = 0; j < iNumLowerProtectedBytes; j++)
				{
					audio_frame[i][iNumHigherProtectedBytes + j] =
						_BINARY((*pvecInputData).Separate(8));
				}
			}
		}
	}
	else if (eAudioCoding == CAudioParam::AC_CELP)
	{
		/* celp_super_frame(celp_table_ind) --------------------------------- */
		/* Higher-protected part */
		for (i = 0; i < iNumAudioFrames; i++)
		{
			celp_frame[i].ResetBitAccess();

			/* Extract higher protected part bits */
			for (j = 0; j < iNumHigherProtectedBits; j++)
				celp_frame[i].Enqueue((*pvecInputData).Separate(1), 1);

			/* Extract CRC bits (8 bits) if used */
			if (bCELPCRC == TRUE)
				celp_crc_bits[i] = _BINARY((*pvecInputData).Separate(8));
		}

		/* Lower-protected part */
		for (i = 0; i < iNumAudioFrames; i++)
		{
			for (j = 0; j < iNumLowerProtectedBits; j++)
				celp_frame[i].Enqueue((*pvecInputData).Separate(1), 1);
		}
	}

	/* Audio decoding ******************************************************** */
	/* Init output block size to zero, this variable is also used for
	   determining the position for writing the output vector */
	iOutputBlockSize = 0;

	for (j = 0; j < iNumAudioFrames; j++)
	{
		if (eAudioCoding == CAudioParam::AC_AAC)
		{
			if (bGoodValues == TRUE)
			{
				/* Prepare data vector with CRC at the beginning (the definition
				   with faad2 DRM interface) */
				vecbyPrepAudioFrame[0] = aac_crc_bits[j];

				for (i = 0; i < veciFrameLength[j]; i++)
					vecbyPrepAudioFrame[i + 1] = audio_frame[j][i];

#if 0
// Store AAC-data in file
				string strAACTestFileName = "test/aac_";
				ReceiverParam.Lock();
				if (ReceiverParam.
					Service[ReceiverParam.GetCurSelAudioService()].AudioParam.
					eAudioSamplRate == CAudioParam::AS_12KHZ)
				{
					strAACTestFileName += "12kHz_";
				}
				else
					strAACTestFileName += "24kHz_";

				switch (ReceiverParam.
						Service[ReceiverParam.GetCurSelAudioService()].
						AudioParam.eAudioMode)
				{
				case CAudioParam::AM_MONO:
					strAACTestFileName += "mono";
					break;

				case CAudioParam::AM_P_STEREO:
					strAACTestFileName += "pstereo";
					break;

				case CAudioParam::AM_STEREO:
					strAACTestFileName += "stereo";
					break;
				}

				if (ReceiverParam.
					Service[ReceiverParam.GetCurSelAudioService()].AudioParam.
					eSBRFlag == CAudioParam::SB_USED)
				{
					strAACTestFileName += "_sbr";
				}
				ReceiverParam.Unlock();
				strAACTestFileName += ".dat";
				static FILE *pFile2 = fopen(strAACTestFileName.c_str(), "wb");
				int iNewFrL = veciFrameLength[j] + 1;
				fwrite((void *) &iNewFrL, size_t(4), size_t(1), pFile2);	// frame length
				fwrite((void *) &vecbyPrepAudioFrame[0], size_t(1), size_t(iNewFrL), pFile2);	// data
				fflush(pFile2);
#endif

				/* Call decoder routine */
				psDecOutSampleBuf = (short *) NeAACDecDecode(HandleAACDecoder,
															 &DecFrameInfo,
															 &vecbyPrepAudioFrame
															 [0],
															 veciFrameLength
															 [j] + 1);

				/* OPH: add frame status to vector for RSCI */
				ReceiverParam.Lock();
				ReceiverParam.vecbiAudioFrameStatus.Add(DecFrameInfo.error == 0 ? 0 : 1);
				ReceiverParam.Unlock();
				if (DecFrameInfo.error != 0)
				{
					//cerr << "AAC decode error" << endl;
					bCurBlockOK = FALSE;	/* Set error flag */
				}
				else
				{
					bCurBlockOK = TRUE;

					if(psDecOutSampleBuf) // might be dummy decoder
					{
					/* Conversion from _SAMPLE vector to _REAL vector for
					   resampling. ATTENTION: We use a vector which was
					   allocated inside the AAC decoder! */
						if (DecFrameInfo.channels == 1)
						{
							/* Change type of data (short -> real) */
							for (i = 0; i < iLenDecOutPerChan; i++)
								vecTempResBufInLeft[i] = psDecOutSampleBuf[i];

							/* Resample data */
							ResampleObjL.Resample(vecTempResBufInLeft,
												  vecTempResBufOutCurLeft);

							/* Mono (write the same audio material in both
							   channels) */
							for (i = 0; i < iResOutBlockSize; i++)
							{
								vecTempResBufOutCurRight[i] =
									vecTempResBufOutCurLeft[i];
							}
						}
						else
						{
							/* Stereo */
							for (i = 0; i < iLenDecOutPerChan; i++)
							{
								vecTempResBufInLeft[i] = psDecOutSampleBuf[i * 2];
								vecTempResBufInRight[i] =
									psDecOutSampleBuf[i * 2 + 1];
							}

							/* Resample data */
							ResampleObjL.Resample(vecTempResBufInLeft,
												  vecTempResBufOutCurLeft);
							ResampleObjR.Resample(vecTempResBufInRight,
												  vecTempResBufOutCurRight);
						}
					}
				}
			}
			else
			{
				/* DRM AAC header was wrong, set flag to "bad block" */
				bCurBlockOK = FALSE;
				/* OPH: update audio status vector for RSCI */
				ReceiverParam.Lock();
				ReceiverParam.vecbiAudioFrameStatus.Add(1);
				ReceiverParam.Unlock();
			}
		}
		else if (eAudioCoding == CAudioParam::AC_CELP)
		{
			if (bCELPCRC == TRUE)
			{
				/* Prepare CRC object and data stream */
				CELPCRCObject.Reset(8);
				celp_frame[j].ResetBitAccess();

				for (i = 0; i < iNumHigherProtectedBits; i++)
					CELPCRCObject.AddBit((_BINARY) celp_frame[j].Separate(1));

				bCurBlockOK = CELPCRCObject.CheckCRC(celp_crc_bits[j]);
			}
			else
				bCurBlockOK = TRUE;

			/* OPH: update audio status vector for RSCI */
			ReceiverParam.Lock();
			ReceiverParam.vecbiAudioFrameStatus.Add(bCurBlockOK == TRUE ? 0 : 1);
			ReceiverParam.Unlock();

#if 0
// Store CELP-data in file
			char cDummy[200];
			string strCELPTestFileName = "test/celp_";
			ReceiverParam.Lock();
			if (ReceiverParam.Service[ReceiverParam.GetCurSelAudioService()].
				AudioParam.eAudioSamplRate == CAudioParam::AS_8_KHZ)
			{
				strCELPTestFileName += "8kHz_";
				strCELPTestFileName +=
					_itoa(iTableCELP8kHzUEPParams
						  [ReceiverParam.
						   Service[ReceiverParam.GetCurSelAudioService()].
						   AudioParam.iCELPIndex][0], cDummy, 10);
			}
			else
			{
				strCELPTestFileName += "16kHz_";
				strCELPTestFileName +=
					_itoa(iTableCELP16kHzUEPParams
						  [ReceiverParam.
						   Service[ReceiverParam.GetCurSelAudioService()].
						   AudioParam.iCELPIndex][0], cDummy, 10);
			}
			strCELPTestFileName += "bps";

			if (ReceiverParam.Service[ReceiverParam.GetCurSelAudioService()].
				AudioParam.eSBRFlag == CAudioParam::SB_USED)
			{
				strCELPTestFileName += "_sbr";
			}
			strCELPTestFileName += ".dat";
			ReceiverParam.Unlock();

			static FILE *pFile2 = fopen(strCELPTestFileName.c_str(), "wb");
			int iTotNumBits =
				iNumHigherProtectedBits + iNumLowerProtectedBits;
			int iNewFrL = (int) Ceil((CReal) iTotNumBits / 8);
			fwrite((void *) &iNewFrL, size_t(4), size_t(1), pFile2);	// frame length
			celp_frame[j].ResetBitAccess();
			for (i = 0; i < iNewFrL; i++)
			{
				int iNumBits = Min(iTotNumBits - i * 8, 8);
				_BYTE bCurVal = (_BYTE) celp_frame[j].Separate(iNumBits);
				fwrite((void *) &bCurVal, size_t(1), size_t(1), pFile2);	// data
			}
			fflush(pFile2);
#endif

#ifdef USE_CELP_DECODER

/* Write zeros in current output buffer since we do not have a decoder */
			for (i = 0; i < iResOutBlockSize; i++)
			{
				vecTempResBufOutCurLeft[i] = (_REAL) 0.0;
				vecTempResBufOutCurRight[i] = (_REAL) 0.0;
			}

#endif

		}
		else
			bCurBlockOK = FALSE;

// This code is independent of particular audio source type and should work
// fine with CELP and HVXC

		/* Postprocessing of audio blocks, status informations -------------- */
		if (bCurBlockOK == FALSE)
		{
			if (bAudioWasOK == TRUE)
			{
				/* Post message to show that CRC was wrong (yellow light) */
				ReceiverParam.Lock();
				ReceiverParam.ReceiveStatus.Audio.SetStatus(DATA_ERROR);
				ReceiverParam.ReceiveStatus.LLAudio.SetStatus(DATA_ERROR);
				ReceiverParam.Unlock();

				/* Fade-out old block to avoid "clicks" in audio. We use linear
				   fading which gives a log-fading impression */
				for (i = 0; i < iResOutBlockSize; i++)
				{
					/* Linear attenuation with time of OLD buffer */
					const _REAL rAtt =
						(_REAL) 1.0 - (_REAL) i / iResOutBlockSize;

					vecTempResBufOutOldLeft[i] *= rAtt;
					vecTempResBufOutOldRight[i] *= rAtt;

					if (bUseReverbEffect == TRUE)
					{
						/* Fade in input signal for reverberation to avoid
						   clicks */
						const _REAL rAttRev = (_REAL) i / iResOutBlockSize;

						/* Cross-fade reverberation effect */
						const _REAL rRevSam = (1.0 - rAtt) * AudioRev.
							ProcessSample(vecTempResBufOutOldLeft[i] *
										  rAttRev,
										  vecTempResBufOutOldRight[i] *
										  rAttRev);

						/* Mono reverbration signal */
						vecTempResBufOutOldLeft[i] += rRevSam;
						vecTempResBufOutOldRight[i] += rRevSam;
					}
				}

				/* Set flag to show that audio block was bad */
				bAudioWasOK = FALSE;
			}
			else
			{
				ReceiverParam.Lock();
				ReceiverParam.ReceiveStatus.Audio.SetStatus(CRC_ERROR);
				ReceiverParam.ReceiveStatus.LLAudio.SetStatus(CRC_ERROR);
				ReceiverParam.Unlock();

				if (bUseReverbEffect == TRUE)
				{
					/* Add Reverberation effect */
					for (i = 0; i < iResOutBlockSize; i++)
					{
						/* Mono reverberation signal */
						vecTempResBufOutOldLeft[i] =
							vecTempResBufOutOldRight[i] = AudioRev.
							ProcessSample(0, 0);
					}
				}
			}

			/* Write zeros in current output buffer */
			for (i = 0; i < iResOutBlockSize; i++)
			{
				vecTempResBufOutCurLeft[i] = (_REAL) 0.0;
				vecTempResBufOutCurRight[i] = (_REAL) 0.0;
			}
		}
		else
		{
			/* Increment correctly decoded audio blocks counter */
			iNumCorDecAudio++;

			ReceiverParam.Lock();
			ReceiverParam.ReceiveStatus.Audio.SetStatus(RX_OK);
			ReceiverParam.ReceiveStatus.LLAudio.SetStatus(RX_OK);
			ReceiverParam.Unlock();

			if (bAudioWasOK == FALSE)
			{
				if (bUseReverbEffect == TRUE)
				{
					/* Add "last" reverbration only to old block */
					for (i = 0; i < iResOutBlockSize; i++)
					{
						/* Mono reverberation signal */
						vecTempResBufOutOldLeft[i] =
							vecTempResBufOutOldRight[i] = AudioRev.
							ProcessSample(vecTempResBufOutOldLeft[i],
										  vecTempResBufOutOldRight[i]);
					}
				}

				/* Fade-in new block to avoid "clicks" in audio. We use linear
				   fading which gives a log-fading impression */
				for (i = 0; i < iResOutBlockSize; i++)
				{
					/* Linear attenuation with time */
					const _REAL rAtt = (_REAL) i / iResOutBlockSize;

					vecTempResBufOutCurLeft[i] *= rAtt;
					vecTempResBufOutCurRight[i] *= rAtt;

					if (bUseReverbEffect == TRUE)
					{
						/* Cross-fade reverberation effect */
						const _REAL rRevSam = (1.0 - rAtt) * AudioRev.
							ProcessSample(0, 0);

						/* Mono reverberation signal */
						vecTempResBufOutCurLeft[i] += rRevSam;
						vecTempResBufOutCurRight[i] += rRevSam;
					}
				}

				/* Reset flag */
				bAudioWasOK = TRUE;
			}
		}

		/* Conversion from _REAL to _SAMPLE with special function */
		for (i = 0; i < iResOutBlockSize; i++)
		{
			(*pvecOutputData)[iOutputBlockSize + i * 2] = Real2Sample(vecTempResBufOutOldLeft[i]);	/* Left channel */
			(*pvecOutputData)[iOutputBlockSize + i * 2 + 1] = Real2Sample(vecTempResBufOutOldRight[i]);	/* Right channel */
		}

		/* Add new block to output block size ("* 2" for stereo output block) */
		iOutputBlockSize += iResOutBlockSize * 2;

		/* Store current audio block */
		for (i = 0; i < iResOutBlockSize; i++)
		{
			vecTempResBufOutOldLeft[i] = vecTempResBufOutCurLeft[i];
			vecTempResBufOutOldRight[i] = vecTempResBufOutCurRight[i];
		}
	}
}

void
CAudioSourceDecoder::InitInternal(CParameter & ReceiverParam)
{
/*
	Since we use the exception mechanism in this init routine, the sequence of
	the individual initializations is very important!
	Requirement for text message is "stream is used" and "audio service".
	Requirement for AAC decoding are the requirements above plus "audio coding
	is AAC"
*/
	int iCurAudioStreamID;
	int iMaxLenResamplerOutput;
	int iCurSelServ;
	int iAudioSampleRate;

	/* Init error flags and output block size parameter. The output block
	   size is set in the processing routine. We must set it here in case
	   of an error in the initialization, this part in the processing
	   routine is not being called */
	DoNotProcessAudDecoder = FALSE;
	DoNotProcessData = FALSE;
	iOutputBlockSize = 0;

	try
	{

		ReceiverParam.Lock();

		/* Init counter for correctly decoded audio blocks */
		iNumCorDecAudio = 0;

		/* Init "audio was ok" flag */
		bAudioWasOK = TRUE;

		/* Get number of total input bits for this module */
		iInputBlockSize = ReceiverParam.iNumAudioDecoderBits;

		/* Get current selected audio service */
		iCurSelServ = ReceiverParam.GetCurSelAudioService();

		/* Current audio stream ID */
		iCurAudioStreamID =
			ReceiverParam.Service[iCurSelServ].AudioParam.iStreamID;

		/* The requirement for this module is that the stream is used and the
		   service is an audio service. Check it here */
		if ((ReceiverParam.Service[iCurSelServ].  eAudDataFlag != CService::SF_AUDIO) ||
			(iCurAudioStreamID == STREAM_ID_NOT_USED))
		{
			throw CInitErr(ET_ALL);
		}

		/* Init text message application ------------------------------------ */
		switch (ReceiverParam.Service[iCurSelServ].AudioParam.bTextflag)
		{
		case TRUE:
			bTextMessageUsed = TRUE;

			/* Get a pointer to the string */
			TextMessage.Init(&ReceiverParam.Service[iCurSelServ].AudioParam.
							 strTextMessage);

			/* Total frame size is input block size minus the bytes for the text
			   message */
			iTotalFrameSize = iInputBlockSize -
				SIZEOF__BYTE * NUM_BYTES_TEXT_MESS_IN_AUD_STR;

			/* Init vector for text message bytes */
			vecbiTextMessBuf.Init(SIZEOF__BYTE *
								  NUM_BYTES_TEXT_MESS_IN_AUD_STR);
			break;

		case FALSE:
			bTextMessageUsed = FALSE;

			/* All bytes are used for AAC data, no text message present */
			iTotalFrameSize = iInputBlockSize;
			break;
		}

		/* Get audio coding type */
		eAudioCoding =
			ReceiverParam.Service[iCurSelServ].AudioParam.eAudioCoding;

		if (eAudioCoding == CAudioParam::AC_AAC)
		{
			/* Init for AAC decoding ---------------------------------------- */
			int iAACSampleRate, iNumHeaderBytes, iDRMchanMode = DRMCH_MONO;

			/* Length of higher protected part of audio stream */
			const int iLenAudHigh =
				ReceiverParam.Stream[iCurAudioStreamID].iLenPartA;

			/* Set number of AAC frames in a AAC super-frame */
			switch (ReceiverParam.Service[iCurSelServ].AudioParam.eAudioSamplRate)	/* Only 12 kHz and 24 kHz is allowed */
			{
			case CAudioParam::AS_12KHZ:
				iNumAudioFrames = 5;
				iNumHeaderBytes = 6;
				iAACSampleRate = 12000;
				break;

			case CAudioParam::AS_24KHZ:
				iNumAudioFrames = 10;
				iNumHeaderBytes = 14;
				iAACSampleRate = 24000;
				break;

			default:
				/* Some error occurred, throw error */
				throw CInitErr(ET_AUDDECODER);
				break;
			}

			/* Number of borders */
			iNumBorders = iNumAudioFrames - 1;

			/* Number of channels for AAC: Mono, PStereo, Stereo */
			switch (ReceiverParam.Service[iCurSelServ].AudioParam.eAudioMode)
			{
			case CAudioParam::AM_MONO:
				if (ReceiverParam.Service[iCurSelServ].AudioParam.
					eSBRFlag == CAudioParam::SB_USED)
				{
					iDRMchanMode = DRMCH_SBR_MONO;
				}
				else
					iDRMchanMode = DRMCH_MONO;
				break;

			case CAudioParam::AM_P_STEREO:
				/* Low-complexity only defined in SBR mode */
				iDRMchanMode = DRMCH_SBR_PS_STEREO;
				break;

			case CAudioParam::AM_STEREO:
				if (ReceiverParam.Service[iCurSelServ].AudioParam.
					eSBRFlag == CAudioParam::SB_USED)
				{
					iDRMchanMode = DRMCH_SBR_STEREO;
				}
				else
				{
					iDRMchanMode = DRMCH_STEREO;
				}
				break;
			}

			/* In case of SBR, AAC sample rate is half the total sample rate.
			   Length of output is doubled if SBR is used */
			if (ReceiverParam.Service[iCurSelServ].AudioParam.
				eSBRFlag == CAudioParam::SB_USED)
			{
				iAudioSampleRate = iAACSampleRate * 2;
				iLenDecOutPerChan = AUD_DEC_TRANSFROM_LENGTH * 2;
			}
			else
			{
				iAudioSampleRate = iAACSampleRate;
				iLenDecOutPerChan = AUD_DEC_TRANSFROM_LENGTH;
			}

			/* The audio_payload_length is derived from the length of the audio
			   super frame (data_length_of_part_A + data_length_of_part_B)
			   subtracting the audio super frame overhead (bytes used for the
			   audio super frame header() and for the aac_crc_bits)
			   (5.3.1.1, Table 5) */
			iAudioPayloadLen = iTotalFrameSize / SIZEOF__BYTE -
				iNumHeaderBytes - iNumAudioFrames;

			/* Check iAudioPayloadLen value, only positive values make sense */
			if (iAudioPayloadLen < 0)
				throw CInitErr(ET_AUDDECODER);

			/* Calculate number of bytes for higher protected blocks */
			iNumHigherProtectedBytes = (iLenAudHigh - iNumHeaderBytes -
										iNumAudioFrames /* CRC bytes */ ) /
				iNumAudioFrames;

			if (iNumHigherProtectedBytes < 0)
				iNumHigherProtectedBytes = 0;

			/* The maximum length for one audio frame is "iAudioPayloadLen". The
			   regular size will be much shorter since all audio frames share
			   the total size, but we do not know at this time how the data is
			   split in the transmitter source coder */
			iMaxLenOneAudFrame = iAudioPayloadLen;
			audio_frame.Init(iNumAudioFrames, iMaxLenOneAudFrame);

			/* Init vector which stores the data with the CRC at the beginning
			   ("+ 1" for CRC) */
			vecbyPrepAudioFrame.Init(iMaxLenOneAudFrame + 1);

			/* Init storage for CRCs and frame lengths */
			aac_crc_bits.Init(iNumAudioFrames);
			veciFrameLength.Init(iNumAudioFrames);

			/* Init AAC-decoder */
			NeAACDecInitDRM(&HandleAACDecoder, iAACSampleRate,
							(unsigned char) iDRMchanMode);
		}
		else if (eAudioCoding == CAudioParam::AC_CELP)
		{
			/* Init for CELP decoding --------------------------------------- */
			int iCurCelpIdx, iCelpFrameLength;

			/* Set number of AAC frames in a AAC super-frame */
			switch (ReceiverParam.Service[iCurSelServ].AudioParam.eAudioSamplRate)	/* Only 8000 and 16000 is allowed */
			{
			case CAudioParam::AS_8_KHZ:
				/* Check range */
				iCurCelpIdx =
					ReceiverParam.Service[iCurSelServ].AudioParam.iCELPIndex;

				if ((iCurCelpIdx > 0) &&
					(iCurCelpIdx < LEN_CELP_8KHZ_UEP_PARAMS_TAB))
				{
					/* CELP frame length */
					iCelpFrameLength =
						iTableCELP8kHzUEPParams[iCurCelpIdx][1];

					/* Number of bits for lower and higher protected parts */
					iNumHigherProtectedBits =
						iTableCELP8kHzUEPParams[iCurCelpIdx][2];
					iNumLowerProtectedBits =
						iTableCELP8kHzUEPParams[iCurCelpIdx][3];
				}
				else
					throw CInitErr(ET_AUDDECODER);

				/* Set audio sample rate */
				iAudioSampleRate = 8000;
				break;

			case CAudioParam::AS_16KHZ:
				/* Check range */
				iCurCelpIdx =
					ReceiverParam.Service[iCurSelServ].AudioParam.iCELPIndex;

				if ((iCurCelpIdx > 0) &&
					(iCurCelpIdx < LEN_CELP_16KHZ_UEP_PARAMS_TAB))
				{
					/* CELP frame length */
					iCelpFrameLength =
						iTableCELP16kHzUEPParams[iCurCelpIdx][1];

					/* Number of bits for lower and higher protected parts */
					iNumHigherProtectedBits =
						iTableCELP16kHzUEPParams[iCurCelpIdx][2];
					iNumLowerProtectedBits =
						iTableCELP16kHzUEPParams[iCurCelpIdx][3];
				}
				else
					throw CInitErr(ET_AUDDECODER);

				/* Set audio sample rate */
				iAudioSampleRate = 16000;
				break;

			default:
				/* Some error occurred, throw error */
				throw CInitErr(ET_AUDDECODER);
				break;
			}

			/* Check lengths of iNumHigherProtectedBits and
			   iNumLowerProtectedBits for overrun */
			const int iTotalNumCELPBits =
				iNumHigherProtectedBits + iNumLowerProtectedBits;

			if (iTotalNumCELPBits * SIZEOF__BYTE > iTotalFrameSize)
				throw CInitErr(ET_AUDDECODER);

			/* Calculate number of audio frames (one audio super frame is
			   always 400 ms long) */
			iNumAudioFrames = 400 /* ms */  / iCelpFrameLength /* ms */ ;

			/* Set CELP CRC flag */
			bCELPCRC = ReceiverParam.Service[iCurSelServ].AudioParam.bCELPCRC;

			/* Init vectors storing the CELP raw data and CRCs */
			celp_frame.Init(iNumAudioFrames, iTotalNumCELPBits);
			celp_crc_bits.Init(iNumAudioFrames);

// TEST
			iLenDecOutPerChan = 0;

#ifdef USE_CELP_DECODER

// TODO put decoder initialization here

#else
			/* No CELP decoder available */
			throw CInitErr(ET_AUDDECODER);
#endif
		}
		else
		{
			/* Audio codec not supported */
			throw CInitErr(ET_AUDDECODER);
		}

		/* Set number of Audio frames for log file */
		ReceiverParam.iNumAudioFrames = iNumAudioFrames;

		/* Since we do not correct for sample rate offsets here (yet), we do not
		   have to consider larger buffers. An audio frame always corresponds
		   to 400 ms */
		iMaxLenResamplerOutput = (int) ((_REAL) SOUNDCRD_SAMPLE_RATE *
										(_REAL) 0.4 /* 400ms */  *
										2 /* for stereo */ );

		iResOutBlockSize = (int) ((_REAL) iLenDecOutPerChan *
								  SOUNDCRD_SAMPLE_RATE / iAudioSampleRate);

		/* Additional buffers needed for resampling since we need conversation
		   between _REAL and _SAMPLE. We have to init the buffers with
		   zeros since it can happen, that we have bad CRC right at the
		   start of audio blocks */
		vecTempResBufInLeft.Init(iLenDecOutPerChan, (_REAL) 0.0);
		vecTempResBufInRight.Init(iLenDecOutPerChan, (_REAL) 0.0);
		vecTempResBufOutCurLeft.Init(iResOutBlockSize, (_REAL) 0.0);
		vecTempResBufOutCurRight.Init(iResOutBlockSize, (_REAL) 0.0);
		vecTempResBufOutOldLeft.Init(iResOutBlockSize, (_REAL) 0.0);
		vecTempResBufOutOldRight.Init(iResOutBlockSize, (_REAL) 0.0);

		/* Init resample objects */
		ResampleObjL.Init(iLenDecOutPerChan,
						  (_REAL) SOUNDCRD_SAMPLE_RATE / iAudioSampleRate);
		ResampleObjR.Init(iLenDecOutPerChan,
						  (_REAL) SOUNDCRD_SAMPLE_RATE / iAudioSampleRate);

		/* Clear reverberation object */
		AudioRev.Clear();

		/* With this parameter we define the maximum lenght of the output
		   buffer. The cyclic buffer is only needed if we do a sample rate
		   correction due to a difference compared to the transmitter. But for
		   now we do not correct and we could stay with a single buffer
		   Maybe TODO: sample rate correction to avoid audio dropouts */
		iMaxOutputBlockSize = iMaxLenResamplerOutput;

		ReceiverParam.Unlock();
	}

	catch(CInitErr CurErr)
	{
		ReceiverParam.Unlock();

		switch (CurErr.eErrType)
		{
		case ET_ALL:
			/* An init error occurred, do not process data in this module */
			DoNotProcessData = TRUE;
			break;

		case ET_AUDDECODER:
			/* Audio part should not be decdoded, set flag */
			DoNotProcessAudDecoder = TRUE;
			break;

		default:
			DoNotProcessData = TRUE;
		}

		/* In all cases set output size to zero */
		iOutputBlockSize = 0;
	}
}

int
CAudioSourceDecoder::GetNumCorDecAudio()
{
	/* Return number of correctly decoded audio blocks. Reset counter
	   afterwards */
	const int iRet = iNumCorDecAudio;

	iNumCorDecAudio = 0;

	return iRet;
}

CAudioSourceDecoder::CAudioSourceDecoder()
:	bUseReverbEffect(TRUE), AudioRev((CReal) 1.0 /* seconds delay */ )
{
#ifndef USE_FAAD2_LIBRARY
    NeAACDecOpen = NeAACDecOpenDummy;
    NeAACDecInitDRM = NeAACDecInitDRMDummy;
    NeAACDecClose = NeAACDecCloseDummy;
    NeAACDecDecode = NeAACDecDecodeDummy;
# ifdef _WIN32
    hFaaDlib = LoadLibrary(TEXT("faad_drm.dll"));
    if(hFaaDlib)
    {
		NeAACDecOpen = (NeAACDecOpen_t*)GetProcAddress(hFaaDlib, TEXT("NeAACDecOpen"));
		NeAACDecInitDRM = (NeAACDecInitDRM_t*)GetProcAddress(hFaaDlib, TEXT("NeAACDecInitDRM"));
		NeAACDecClose = (NeAACDecClose_t*)GetProcAddress(hFaaDlib, TEXT("NeAACDecClose"));
		NeAACDecDecode = (NeAACDecDecode_t*)GetProcAddress(hFaaDlib, TEXT("NeAACDecDecode"));
    }
# else
#  if defined(__APPLE__)
    hFaaDlib = dlopen("libfaad_drm.dylib", RTLD_LOCAL | RTLD_NOW);
#  else
    hFaaDlib = dlopen("libfaad2_drm.so", RTLD_LOCAL | RTLD_NOW);
#  endif
    if(hFaaDlib)
    {
		cerr << "loaded aac decoder library OK" << endl;
		NeAACDecOpen = (NeAACDecOpen_t*)dlsym(hFaaDlib, "NeAACDecOpen");
		NeAACDecInitDRM = (NeAACDecInitDRM_t*)dlsym(hFaaDlib, "NeAACDecInitDRM");
		NeAACDecClose = (NeAACDecClose_t*)dlsym(hFaaDlib, "NeAACDecClose");
		NeAACDecDecode = (NeAACDecDecode_t*)dlsym(hFaaDlib,"NeAACDecDecode");
    }
    else
    {
		cerr << "No aac decoder library - audio will not be decoded" << endl;
    }
# endif
    if(NeAACDecInitDRM == NULL) // Might be non-DRM version of FAAD2
    {
		NeAACDecInitDRM = NeAACDecInitDRMDummy;
    }
#endif
	/* Open AACEncoder instance */
	HandleAACDecoder = NeAACDecOpen();

	/* Decoder MUST be initialized at least once, therefore do it here in the
	   constructor with arbitrary values to be sure that this is satisfied */
	NeAACDecInitDRM(&HandleAACDecoder, 24000, DRMCH_MONO);
}

CAudioSourceDecoder::~CAudioSourceDecoder()
{
	/* Close decoder handle */
	NeAACDecClose(HandleAACDecoder);
}
