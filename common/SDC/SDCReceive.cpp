/******************************************************************************\
 * Technische Universitaet Darmstadt, Institut fuer Nachrichtentechnik
 * Copyright (c) 2001
 *
 * Author(s):
 *	Volker Fischer
 *
 * Description:
 *	SDC data stream decoding (receiver)
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
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 *
\******************************************************************************/

#include "SDC.h"


/* Implementation *************************************************************/
CSDCReceive::ERetStatus CSDCReceive::SDCParam(CVector<_BINARY>* pbiData,
											  CParameter& Parameter)
{
	/* Calculate length of data field in bytes
	   (consistant to table 61 in (6.4.1)) */
	const int iLengthDataFieldBytes = 
		(int) ((_REAL) (Parameter.iNumSDCBitsPerSFrame - 20) / 8);

	/* 20 bits from AFS index and CRC */
	const int iUsefulBitsSDC = 20 + iLengthDataFieldBytes * 8;

	/* CRC ------------------------------------------------------------------ */
	/* Check the CRC of this data block */
	CRCObject.Reset(16);

	(*pbiData).ResetBitAccess();

	/* Special treatment of SDC data stream: The CRC (Cyclic Redundancy
	Check) field shall contain a 16-bit CRC calculated over the AFS
	index coded in an 8-bit field (4 msbs are 0) and the data field.
	4 MSBs from AFS-index. Insert four "0" in the data-stream */
	const _BYTE byFirstByte = (_BYTE) (*pbiData).Separate(4);
	CRCObject.AddByte(byFirstByte);

	/* "- 4": Four bits already used, "/ SIZEOF__BYTE": We add bytes, not bits,
	   "- 2": 16 bits for CRC at the end */
	const int iNumBytesForCRCCheck = (iUsefulBitsSDC - 4) / SIZEOF__BYTE - 2;
	for (int i = 0; i < iNumBytesForCRCCheck; i++)
		CRCObject.AddByte((_BYTE) (*pbiData).Separate(SIZEOF__BYTE));

	if (CRCObject.CheckCRC((*pbiData).Separate(16)) == TRUE)
	{
		/* CRC-check successful, extract data from SDC-stream --------------- */
		int			iLengthOfBody;
		_BOOLEAN	bError = FALSE;

		/* Reset separation function */
		(*pbiData).ResetBitAccess();

		/* AFS index */
		/* Reconfiguration index (not used by this application) */
		(*pbiData).Separate(4);

		/* Init bit count and total number of bits for body */
		int			iBitsConsumed = 4; /* 4 bits for AFS index */
		const int	iTotNumBitsWithoutCRC = iUsefulBitsSDC - 16;

		/* Length of the body, excluding the initial 4 bits ("- 4"),
		   measured in bytes ("/ 8").
		   With this condition also the error code of the "Separate" function
		   is checked! (implicitly)
		   Check for: -end tag, -error, -no more data available */
		while (((iLengthOfBody = (*pbiData).Separate(7)) != 0) &&
			(bError == FALSE) && (iBitsConsumed < iTotNumBitsWithoutCRC))
		{
			/* Version flag (not used in this implementation) */
			(*pbiData).Separate(1);

			/* Data entity type */
			/* First calculate number of bits for this entity ("+ 4" because of:
			   "The body of the data entities shall be at least 4 bits long. The
			   length of the body, excluding the initial 4 bits, shall be
			   signalled by the header") */
			const int iNumBitsEntity = iLengthOfBody * 8 + 4;

			/* Call the routine for the signalled type */
			switch ((*pbiData).Separate(4))
			{
			case 0: /* Type 0 */
				bError = DataEntityType0(pbiData, iLengthOfBody, Parameter);
				break;

			case 1: /* Type 1 */
				bError = DataEntityType1(pbiData, iLengthOfBody, Parameter);
				break;

			case 3: /* Type 3 */
				bError = DataEntityType3(pbiData, iLengthOfBody, Parameter);
				break;

			case 5: /* Type 5 */
				bError = DataEntityType5(pbiData, iLengthOfBody, Parameter);
				break;

			case 8: /* Type 8 */
				bError = DataEntityType8(pbiData, iLengthOfBody, Parameter);
				break;

			case 9: /* Type 9 */
				bError = DataEntityType9(pbiData, iLengthOfBody, Parameter);
				break;

			default:
				/* This type is not supported, delete all bits of this entity
				   from the queue */
				(*pbiData).Separate(iNumBitsEntity);
			}

			/* Count number of bits consumed (7 for length, 1 for version flag,
			   4 for type = 12 plus actual entitiy body data) */
			iBitsConsumed += 12 + iNumBitsEntity;
		}

		/* If error was detected, return proper error code */
		if (bError == TRUE)
			return SR_BAD_DATA;
		else
			return SR_OK; /* everything was ok */
	}
	else
	{
		/* Data is corrupted, do not use it. Return error code */
		return SR_BAD_CRC;
	}
}


/******************************************************************************\
* Data entity Type 0 (Multiplex description data entity)					   *
\******************************************************************************/
_BOOLEAN CSDCReceive::DataEntityType0(CVector<_BINARY>* pbiData,
									  const int iLengthOfBody,
									  CParameter& Parameter)
{
	CParameter::CMSCProtLev	MSCPrLe;
	int						iLenPartA;
	int						iLenPartB;

	/* The receiver may determine the number of streams present in the multiplex
	   by dividing the length field of the header by three (6.4.3.1) */
	const int iNumStreams = iLengthOfBody / 3;

	/* Check number of streams for overflow */
	if (iNumStreams > MAX_NUM_STREAMS)
		return TRUE;

	/* Get protection levels */
	/* Protection level for part A */
	MSCPrLe.iPartA = (*pbiData).Separate(2);

	/* Protection level for part B */
	MSCPrLe.iPartB = (*pbiData).Separate(2);

	/* Reset hierarchical flag (hierarchical present or not) */
	_BOOLEAN bWithHierarch = FALSE;

	/* Get stream parameters */
	for (int i = 0; i < iNumStreams; i++)
	{
		/* In case of hirachical modulation stream 0 describes the protection
		   level and length of hierarchical data */
		if ((i == 0) &&
			((Parameter.eMSCCodingScheme == CParameter::CS_3_HMSYM) ||
			(Parameter.eMSCCodingScheme == CParameter::CS_3_HMMIX)))
		{
			/* Protection level for hierarchical */
			MSCPrLe.iHierarch = (*pbiData).Separate(2);
			bWithHierarch = TRUE;

			/* rfu: these 10 bits shall be reserved for future use by the stream
			   description field and shall be set to zero until they are
			   defined */
			if ((*pbiData).Separate(10) != 0)
				return TRUE;

			/* Data length for hierarchical */
			iLenPartB = (*pbiData).Separate(12);

			/* Set new parameters in global struct. Lenght of part A is zero
			   with hierarchical modulation */
			Parameter.SetStreamLen(i, 0, iLenPartB);
		}
		else
		{
			/* Data length for part A */
			iLenPartA = (*pbiData).Separate(12);

			/* Data length for part B */
			iLenPartB = (*pbiData).Separate(12);

			/* Set new parameters in global struct */
			Parameter.SetStreamLen(i, iLenPartA, iLenPartB);
		}
	}

	/* Set new parameters in global struct */
	Parameter.SetMSCProtLev(MSCPrLe, bWithHierarch);

	return FALSE;
}


/******************************************************************************\
* Data entity Type 1 (Label data entity)									   *
\******************************************************************************/
_BOOLEAN CSDCReceive::DataEntityType1(CVector<_BINARY>* pbiData,
									  const int iLengthOfBody,
									  CParameter& Parameter)
{
	/* Short ID (the short ID is the index of the service-array) */
	const int iTempShortID = (*pbiData).Separate(2);

	/* rfu: these 2 bits are reserved for future use and shall be set to zero
	   until they are defined */
	if ((*pbiData).Separate(2) != 0)
		return TRUE;


	/* Get label string ----------------------------------------------------- */
	/* Check the following restriction to the length of label: "label: this is a
	   variable length field of up to 64 bytes defining the label" */
	if (iLengthOfBody <= 64)
	{
		/* Reset label string */
		Parameter.Service[iTempShortID].strLabel = "";

		/* Get all characters from SDC-stream */
		for (int i = 0; i < iLengthOfBody; i++)
		{
			/* Get character */
			const char cNewChar = (*pbiData).Separate(8);

			/* Append new character */
			Parameter.Service[iTempShortID].strLabel.append(&cNewChar, 1);
		}

		return FALSE;
	}
	else
		return TRUE; /* error */
}


/******************************************************************************\
* Data entity Type 3 (Alternative frequency signalling)                        *
\******************************************************************************/
_BOOLEAN CSDCReceive::DataEntityType3(CVector<_BINARY>* pbiData,
									  const int iLengthOfBody,
									  CParameter& Parameter)
{
	_BOOLEAN bSyncMultplxFlag;
	_BOOLEAN bEnhanceFlag;
	_BOOLEAN bServRestrFlag;
	_BOOLEAN bRegionSchedFlag;

	/* Init number of frequency count */
	int iNumFreq = iLengthOfBody;

	/* Synchronous Multiplex flag: this flag indicates whether the multiplex is
	   broadcast synchronously */
	switch ((*pbiData).Separate(1))
	{
	case 0: /* 0 */
		/* Multiplex is not synchronous (different content and/or channel
		   parameters and/or multiplex parameters and/or signal timing in target
		   area) */
		bSyncMultplxFlag = FALSE;
		break;

	case 1: /* 1 */
		/* Multiplex is synchronous (identical content and channel parameters
		   and multiplex parameters and signal timing in target area) */
		bSyncMultplxFlag = TRUE;
		break;
	}

	/* Layer flag: this flag indicates whether the frequencies given apply to
	   the base layer of the DRM multiplex or to the enhancement layer */
	switch ((*pbiData).Separate(1))
	{
	case 0: /* 0 */
		/* Base layer */
		bEnhanceFlag = FALSE;
		break;

	case 1: /* 1 */
		/* Enhancement layer */
		bEnhanceFlag = TRUE;
		break;
	}

	/* Service Restriction flag: this flag indicates whether all or just some of
	   the services of the tuned multiplex are available in the DRM multiplex on
	   the frequencies */
	switch ((*pbiData).Separate(1))
	{
	case 0: /* 0 */
		/* All services in the tuned multiplex are available on the frequencies
		   given */
		bServRestrFlag = FALSE;
		break;

	case 1: /* 1 */
		/* A restricted set of services are available on the frequencies
		   given */
		bServRestrFlag = TRUE;
		break;
	}

	/* Region/Schedule flag: this field indicates whether the list of
	   frequencies is restricted by region and/or schedule or not */
	switch ((*pbiData).Separate(1))
	{
	case 0: /* 0 */
		/* No restriction */
		bRegionSchedFlag = FALSE;
		break;

	case 1: /* 1 */
		/* Region and/or schedule applies to this list of frequencies */
		bRegionSchedFlag = TRUE;
		break;
	}

	/* Service Restriction field: this 8 bit field is only present if the
	   Service Restriction flag is set to 1 */
	if (bServRestrFlag == TRUE)
	{
		/* Short Id flags 4 bits. This field indicates, which services
		   (identified by their Short Id) of the tuned DRM multiplex are carried
		   in the DRM multiplex on the alternative frequencies by setting the
		   corresponding bit to 1. The first bit (msb) refers to Short Id 3,
		   while the last bit (lsb) refers to Short Id 0 of the tuned DRM
		   multiplex */
		(*pbiData).Separate(4);

		/* rfa 4 bits. This field (if present) is reserved for future additions
		   and shall be set to zero until it is defined */
		if ((*pbiData).Separate(4) != 0)
			return TRUE;

		/* Remove one byte from frequency count */
		iNumFreq--;
	}

	/* Region/Schedule field: this 8 bit field is only present if the
	   Region/Schedule flag is set to 1 */
	if (bRegionSchedFlag == TRUE)
	{
		/* Region Id 4 bits. This field indicates whether the region is
		   unspecified (value 0) or whether the alternative frequencies are
		   valid just in certain geographic areas, in which case it carries
		   the Region Id (value 1 to 15). The region may be described by one or
		   more "Alternative frequency signalling: Region definition data entity
		   - type 7" with this Region Id */
		(*pbiData).Separate(4);

		/* Schedule Id 4 bits. This field indicates whether the schedule is
		   unspecified (value 0) or whether the alternative frequencies are
		   valid just at certain times, in which case it carries the Schedule Id
		   (value 1 to 15). The schedule is described by one or more
		   "Alternative frequency signalling: Schedule definition data entity
		   - type 4" with this Schedule Id */
		(*pbiData).Separate(4);

		/* Remove one byte from frequency count */
		iNumFreq--;
	}

	/* Check for error (length of body must be so long to include Service
	   Restriction field and Region/Schedule field, also check that
	   remaining number of bytes is devidable by 2 since we read 16 bits) */
	if ((iNumFreq < 0) || (iNumFreq % 2 != 0))
		return TRUE;

	/* n frequencies: this field carries n 16 bit fields. n is in the
	   range 1 to 16. The number of frequencies, n, is determined from the
	   length field of the header and the value of the Service Restriction flag
	   and the Region/Schedule flag */
	for (int i = 0; i < iNumFreq / 2 /* 16 bits are read */; i++)
	{
		/* rfu 1 bit. This field is reserved for future use of the frequency
		   value field and shall be set to zero until defined */
		if ((*pbiData).Separate(1) != 0)
			return TRUE;

		/* Frequency value 15 bits. This field is coded as an unsigned integer
		   and gives the frequency in kHz */
		const int iFreqVal = (*pbiData).Separate(15);

/*
// TEST
static FILE* pFile = fopen("test/freqsched.dat", "w");
fprintf(pFile, "%d%d%d%d %d\n", bSyncMultplxFlag, bEnhanceFlag, bServRestrFlag, bRegionSchedFlag, iFreqVal);
fflush(pFile);
*/

	}

	return FALSE;
}


/******************************************************************************\
* Data entity Type 5 (Application information data entity)					   *
\******************************************************************************/
_BOOLEAN CSDCReceive::DataEntityType5(CVector<_BINARY>* pbiData,
									  const int iLengthOfBody,
									  CParameter& Parameter)
{
	/* Short ID (the short ID is the index of the service-array) */
	const int iTempShortID = (*pbiData).Separate(2);

	/* Load data parameters class with current parameters */
	CParameter::CDataParam DataParam = Parameter.GetDataParam(iTempShortID);

	/* Stream Id */
	DataParam.iStreamID = (*pbiData).Separate(2);

	/* Packet mode indicator */
	switch ((*pbiData).Separate(1))
	{
	case 0: /* 0 */
		DataParam.ePacketModInd = CParameter::PM_SYNCHRON_STR_MODE;

		/* Descriptor (not used) */
		(*pbiData).Separate(7);
		break;

	case 1: /* 1 */
		DataParam.ePacketModInd = CParameter::PM_PACKET_MODE;

		/* Descriptor */
		/* Data unit indicator */
		switch ((*pbiData).Separate(1))
		{
		case 0: /* 0 */
			DataParam.eDataUnitInd = CParameter::DU_SINGLE_PACKETS;
			break;

		case 1: /* 1 */
			DataParam.eDataUnitInd = CParameter::DU_DATA_UNITS;
			break;
		}

		/* Packet Id */
		DataParam.iPacketID = (*pbiData).Separate(2);

		/* Application domain */
		switch ((*pbiData).Separate(4))
		{
		case 0: /* 0000 */
			DataParam.eAppDomain = CParameter::AD_DRM_SPEC_APP;
			break;

		case 1: /* 0001 */
			DataParam.eAppDomain = CParameter::AD_DAB_SPEC_APP;
			break;

		default: /* 2 - 15 reserved */
			DataParam.eAppDomain = CParameter::AD_OTHER_SPEC_APP;
			break;
		}

		/* Packet length */
		DataParam.iPacketLen = (*pbiData).Separate(8);
		break;
	}

	/* Application data */
	if (DataParam.ePacketModInd == CParameter::PM_SYNCHRON_STR_MODE)
	{
		/* Not used */
		(*pbiData).Separate(iLengthOfBody * 8 - 8);
	}
	else if (DataParam.eAppDomain == CParameter::AD_DAB_SPEC_APP)
	{
		/* rfu */
		(*pbiData).Separate(5);

		/* User application identifier */
		DataParam.iUserAppIdent = (*pbiData).Separate(11);

		/* Data fields as required by DAB application specification, not used */
		(*pbiData).Separate(iLengthOfBody * 8 - 32);
	}
	else
	{
		/* Not used */
		(*pbiData).Separate(iLengthOfBody * 8 - 16);
	}

	/* Set new parameters in global struct */
	Parameter.SetDataParam(iTempShortID, DataParam);

	return FALSE;
}


/******************************************************************************\
* Data entity Type 8 (Time and date information data entity)				   *
\******************************************************************************/
_BOOLEAN CSDCReceive::DataEntityType8(CVector<_BINARY>* pbiData,
									  const int iLengthOfBody,
									  CParameter& Parameter)
{
	/* Check length -> must be 3 bytes */
	if (iLengthOfBody != 3)
		return TRUE;

	/* Decode date */
	CModJulDate ModJulDate((*pbiData).Separate(17));

	Parameter.iDay = ModJulDate.GetDay();
	Parameter.iMonth = ModJulDate.GetMonth();
	Parameter.iYear = ModJulDate.GetYear();

	/* UTC (hours and minutes) */
	Parameter.iUTCHour = (*pbiData).Separate(5);
	Parameter.iUTCMin = (*pbiData).Separate(6);

	return FALSE;
}


/******************************************************************************\
* Data entity Type 9 (Audio information data entity)						   *
\******************************************************************************/
_BOOLEAN CSDCReceive::DataEntityType9(CVector<_BINARY>* pbiData,
									  const int iLengthOfBody,
									  CParameter& Parameter)
{
	/* Check length -> must be 2 bytes */
	if (iLengthOfBody != 2)
		return TRUE;

	/* Init error flag with "no error" */
	_BOOLEAN bError = FALSE;

	/* Short ID (the short ID is the index of the service-array) */
	const int iTempShortID = (*pbiData).Separate(2);

	/* Load audio parameters class with current parameters */
	CParameter::CAudioParam AudParam = Parameter.GetAudioParam(iTempShortID);

	/* Stream Id */
	AudParam.iStreamID = (*pbiData).Separate(2);

	/* Audio coding */
	switch ((*pbiData).Separate(2))
	{
	case 0: /* 00 */
		AudParam.eAudioCoding = CParameter::AC_AAC;
		break;

	case 1: /* 01 */
		AudParam.eAudioCoding = CParameter::AC_CELP;
		break;

	case 2: /* 10 */
		AudParam.eAudioCoding = CParameter::AC_HVXC;
		break;

	default: /* reserved */
		bError = TRUE;
		break;
	}

	/* SBR flag */
	switch ((*pbiData).Separate(1))
	{
	case 0: /* 0 */
		AudParam.eSBRFlag = CParameter::SB_NOT_USED;
		break;

	case 1: /* 1 */
		AudParam.eSBRFlag = CParameter::SB_USED;
		break;
	}

	/* Audio mode */
	switch (AudParam.eAudioCoding)
	{
	case CParameter::AC_AAC:
		/* Channel type */
		switch ((*pbiData).Separate(2))
		{
		case 0: /* 00 */
			AudParam.eAudioMode = CParameter::AM_MONO;
			break;

		case 1: /* 01 */
			AudParam.eAudioMode = CParameter::AM_P_STEREO;
			break;

		case 2: /* 10 */
			AudParam.eAudioMode = CParameter::AM_STEREO;
			break;

		default: /* reserved */
			bError = TRUE;
			break;
		}
		break;

	case CParameter::AC_CELP:
		/* rfa */
		(*pbiData).Separate(1);

		/* CELP_CRC */
		switch ((*pbiData).Separate(1))
		{
		case 0: /* 0 */
			AudParam.bCELPCRC = FALSE;
			break;

		case 1: /* 1 */
			AudParam.bCELPCRC = TRUE;
			break;
		}
		break;

	case CParameter::AC_HVXC:
		/* HVXC_rate */
		switch ((*pbiData).Separate(1))
		{
		case 0: /* 0 */
			AudParam.eHVXCRate = CParameter::HR_2_KBIT;
			break;

		case 1: /* 1 */
			AudParam.eHVXCRate = CParameter::HR_4_KBIT;
			break;
		}

		/* HVXC CRC */
		switch ((*pbiData).Separate(1))
		{
		case 0: /* 0 */
			AudParam.bHVXCCRC = FALSE;
			break;

		case 1: /* 1 */
			AudParam.bHVXCCRC = TRUE;
			break;
		}
		break;
	}

	/* Audio sampling rate */
	switch ((*pbiData).Separate(3))
	{
	case 0: /* 000 */
		AudParam.eAudioSamplRate = CParameter::AS_8_KHZ;
		break;

	case 1: /* 001 */
		AudParam.eAudioSamplRate = CParameter::AS_12KHZ;
		break;

	case 2: /* 010 */
		AudParam.eAudioSamplRate = CParameter::AS_16KHZ;
		break;

	case 3: /* 011 */
		AudParam.eAudioSamplRate = CParameter::AS_24KHZ;
		break;

	default: /* reserved */
		bError = TRUE;
		break;
	}

	/* Text flag */
	switch ((*pbiData).Separate(1))
	{
	case 0: /* 0 */
		AudParam.bTextflag = FALSE;
		break;

	case 1: /* 1 */
		AudParam.bTextflag = TRUE;
		break;
	}

	/* Enhancement flag */
	switch ((*pbiData).Separate(1))
	{
	case 0: /* 0 */
		AudParam.bEnhanceFlag = FALSE;
		break;

	case 1: /* 1 */
		AudParam.bEnhanceFlag = TRUE;
		break;
	}

	/* Coder field */
	if (AudParam.eAudioCoding == CParameter::AC_CELP)
	{
		/* CELP index */
		AudParam.iCELPIndex = (*pbiData).Separate(5);
	}
	else
	{
		/* rfa 5 bit */
		(*pbiData).Separate(5);
	}

	/* rfa 1 bit */
	(*pbiData).Separate(1);

	/* Set new parameters in global struct */
	if (bError == FALSE)
	{
		Parameter.SetAudioParam(iTempShortID, AudParam);
		return FALSE;
	}
	else
		return TRUE;
}
