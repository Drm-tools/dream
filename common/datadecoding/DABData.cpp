/******************************************************************************\
 * Technische Universitaet Darmstadt, Institut fuer Nachrichtentechnik
 * Copyright (c) 2001
 *
 * Author(s):
 *	Volker Fischer, Doyle Richard
 *
 * Description:
 *	DAB data decoding (MOT)
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

#include "DABData.h"


/* Implementation *************************************************************/
void CDABData::AddDataUnit(CVector<_BINARY>& vecbiNewData, CMOTPicture& NewPic)
{
	_BINARY			biExtensionFlag;
	_BINARY			biCRCFlag;
	_BINARY			biSegmentFlag;
	_BINARY			biUserAccFlag;
	_BINARY			biLastFlag;
	_BINARY			biTransportIDFlag;
	unsigned char	ucParamId;
	unsigned char	ucDatafield;
	int				i;
	int				iBodySize;
	int				iHeaderSize;
	int				iDataGroupType;
	int				iNewContInd;
	int				iRepitiIndex;
	int				iSegmentNum;
	int				iLenIndicat;
	int				iLenGroupDataField;
	int				iSegmentSize;
	int				iTransportID;
	int				iOldDataSize;
	int				iContentType;
	int				iContentSubType;
	int				iDaSiBytes;
	CCRC			CRCObject;
	_BOOLEAN		bCRCOk;
	FILE*			pFiBody;

	/* Get length of data unit */
	iLenGroupDataField = vecbiNewData.Size();


	/* CRC check ------------------------------------------------------------ */
	/* We do the CRC check at the beginning no matter if it is used or not
	   since we have to reset bit access for that */
	/* Reset bit extraction access */
	vecbiNewData.ResetBitAccess();

	/* Check the CRC of this packet */
	CRCObject.Reset(16);

	/* "- 2": 16 bits for CRC at the end */
	for (i = 0; i < (iLenGroupDataField / SIZEOF__BYTE) - 2; i++)
		CRCObject.AddByte((_BYTE) vecbiNewData.Separate(SIZEOF__BYTE));

	if (CRCObject.CheckCRC(vecbiNewData.Separate(16)) == TRUE)
		bCRCOk = TRUE;
	else
		bCRCOk = FALSE;


	/* MSC data group header ------------------------------------------------ */
	/* Reset bit extraction access */
	vecbiNewData.ResetBitAccess();

	/* Extension flag */
	biExtensionFlag = (_BINARY) vecbiNewData.Separate(1);

	/* CRC flag */
	biCRCFlag = (_BINARY) vecbiNewData.Separate(1);

	/* Segment flag */
	biSegmentFlag = (_BINARY) vecbiNewData.Separate(1);

	/* User access flag */
	biUserAccFlag = (_BINARY) vecbiNewData.Separate(1);
	
	/* Data group type */
	iDataGroupType = (int) vecbiNewData.Separate(4);

	/* Continuity index */
	iNewContInd = (int) vecbiNewData.Separate(4);

	/* Repetition index */
	iRepitiIndex = (int) vecbiNewData.Separate(4);

	/* Extension field (not used) */
	if (biExtensionFlag == TRUE)
		vecbiNewData.Separate(16);


	/* Session header ------------------------------------------------------- */
	/* Segment field */
	if (biSegmentFlag == TRUE)
	{
		/* Last */
		biLastFlag = (_BINARY) vecbiNewData.Separate(1);

		/* Segment number */
		iSegmentNum = (int) vecbiNewData.Separate(15);
	}

	/* User access field */
	if (biUserAccFlag == TRUE)
	{
		/* Rfa (Reserved for future addition) */
		vecbiNewData.Separate(3);

		/* Transport Id flag */
		biTransportIDFlag = (_BINARY) vecbiNewData.Separate(1);

		/* Length indicator */
		iLenIndicat = (int) vecbiNewData.Separate(4);

		/* Transport Id */
		iTransportID = (int) vecbiNewData.Separate(16);
			
		/* End user address field (not used) */
		vecbiNewData.Separate((iLenIndicat - 2) * SIZEOF__BYTE);
	}


	/* MSC data group data field -------------------------------------------- */
	/* If CRC is not used enter if-block, if CRC flag is used, it must be ok to
	   enter the if-block */
	if ((biCRCFlag == FALSE) || ((biCRCFlag == TRUE) && (bCRCOk == TRUE)))
	{
		/* Segmentation header ---------------------------------------------- */
		/* Repetition count (not used) */
		vecbiNewData.Separate(3);

		/* Segment size */
		iSegmentSize = (int) vecbiNewData.Separate(13);


		/* Get MOT data ----------------------------------------------------- */
		/* Segment number and user access data is needed */
		if ((biSegmentFlag == TRUE) && (biUserAccFlag == TRUE) &&
			(biTransportIDFlag == TRUE))
		{
			/* Distinguish between header and body */
			/* Header information, i.e. the header core and the header
			   extension, are transferred in Data Group type 3 */
			if (iDataGroupType == 3)
			{
				/* Header --------------------------------------------------- */
				if (iSegmentNum == 0)
				{
					/* Header */
					/* The first segment was received, reset header */
					MOTObject.Header.Reset();

					/* The first occurrence of a Data Group type 3 containing
					   header information is referred as the beginning of the
					   object transmission. Set new transport ID */
					MOTObject.iTransportID = iTransportID;

					/* Init flag for header ok */
					MOTObject.Header.bOK = TRUE;

					/* Add new segment data */
					MOTObject.Header.Add(vecbiNewData, iSegmentSize,
						iSegmentNum);
				}
				else
				{
					/* Check transport ID */
					if (MOTObject.iTransportID != iTransportID)
						MOTObject.Header.Reset();
					else
					{
						/* Sometimes a packet is transmitted more than once,
						   only use packets which are not already received
						   correctly */
						if (MOTObject.Header.iDataSegNum != iSegmentNum)
						{
							/* Check segment number */
							if (MOTObject.Header.iDataSegNum + 1 != iSegmentNum)
							{
								/* A packet is missing, reset Header */
								MOTObject.Header.Reset();
							}
							else
							{
								/* Add data */
								MOTObject.Header.Add(vecbiNewData, iSegmentSize,
									iSegmentNum);
							}
						}
					}
				}

				/* Test if last flag is active */
				if (biLastFlag == TRUE)
				{
					/* Header */
					if (MOTObject.Header.bOK == TRUE)
						MOTObject.Header.bReady = TRUE;
				}
			}
			else if (iDataGroupType == 4)
			{
				/* Body data segments are transferred in Data Group type 4 */
				/* Body ----------------------------------------------------- */
				if (iSegmentNum == 0)
				{
					/* The first segment was received, reset body */
					MOTObject.Body.Reset();

					/* Check transport ID */
					if (MOTObject.iTransportID == iTransportID)
					{
						/* Init flag for body ok */
						MOTObject.Body.bOK = TRUE;

						/* Add data */
						MOTObject.Body.Add(vecbiNewData, iSegmentSize,
							iSegmentNum);
					}
				}
				else
				{
					/* Check transport ID */
					if (MOTObject.iTransportID != iTransportID)
						MOTObject.Body.Reset();
					else
					{
						/* Sometimes a packet is transmitted more than once,
						   only use packets which are not already received
						   correctly */
						if (MOTObject.Body.iDataSegNum != iSegmentNum)
						{
							/* Check segment number */
							if (MOTObject.Body.iDataSegNum + 1 != iSegmentNum)
							{
								/* A packet is missing, reset Header */
								MOTObject.Body.Reset();
							}
							else
							{
								/* Add data */
								MOTObject.Body.Add(vecbiNewData, iSegmentSize,
									iSegmentNum);
							}
						}
					}
				}

				/* Test if last flag is active */
				if (biLastFlag == TRUE)
					if (MOTObject.Body.bOK == TRUE)
						MOTObject.Body.bReady = TRUE;
			}


			/* Use MOT object ----------------------------------------------- */
			/* Test if MOT object is ready */
			if ((MOTObject.Header.bReady == TRUE) &&
				(MOTObject.Body.bReady == TRUE))
			{
				MOTObject.Header.vecbiData.ResetBitAccess();

				/* HeaderSize and BodySize */
				iBodySize = (int) MOTObject.Header.vecbiData.Separate(28);
				iHeaderSize = (int) MOTObject.Header.vecbiData.Separate(13);

				/* 7 bytes for header core */
				int iSizeRec = iHeaderSize - 7;

				/* Content type and content sup-type */
				iContentType = (int) MOTObject.Header.vecbiData.Separate(6);
				iContentSubType = (int) MOTObject.Header.vecbiData.Separate(9);

				/* Use all header extension data blocks,
				   added by Doyle Richard 2003/12/22 */
				while (iSizeRec > 0)
				{
					/* PLI (Parameter Length Indicator) */
					int iPLI = (int) MOTObject.Header.vecbiData.Separate(2);

					switch(iPLI)
					{
					case 0:
						/* Total parameter length = 1 byte; no DataField
						   available */
						ucParamId = (unsigned char)
							MOTObject.Header.vecbiData.Separate(6);

						/* TODO: Use "ucParamId" */

						iSizeRec -= 1; /* 6 + 2 (PLI) bits */
						break;

					case 1:
						/* Total parameter length = 2 bytes, length of DataField
						   is 1 byte */
						ucParamId = (unsigned char)
							MOTObject.Header.vecbiData.Separate(6);

						ucDatafield = (unsigned char)
							MOTObject.Header.vecbiData.Separate(8);

						/* TODO: Use information in data field */

						iSizeRec -= 2; /* 6 + 8 + 2 (PLI) bits */
						break;

					case 2:
						/* Total parameter length = 5 bytes; length of DataField
						   is 4 bytes */
						ucParamId = (unsigned char)
							MOTObject.Header.vecbiData.Separate(6);

						for (i = 0; i < 4; i++)
						{
							ucDatafield = (unsigned char)
								MOTObject.Header.vecbiData.Separate(8);

							/* TODO: Use information in data field */
						}
						iSizeRec -= 5; /* 6 + 4 * 8 + 2 (PLI) bits */
						break;

					case 3:
						/* Total parameter length depends on the DataFieldLength
						   indicator (the maximum parameter length is
						   32770 bytes) */
						ucParamId = (unsigned char)
							MOTObject.Header.vecbiData.Separate(6);

						iSizeRec -= 1; /* 2 (PLI) + 6 bits */

						/* Ext (ExtensionFlag): This 1-bit field specifies the
						   length of the DataFieldLength Indicator and is coded
						   as follows:
						   - 0: the total parameter length is derived from the
								next 7 bits;
						   - 1: the total parameter length is derived from the
								next 15 bits */
						unsigned char ucExt = (unsigned char)
							MOTObject.Header.vecbiData.Separate(1);

						int iDataFieldLen = 0;

						/* Get data field length */
						if (ucExt == 0)
						{
							iDataFieldLen = (int)
								MOTObject.Header.vecbiData.Separate(7);

							iSizeRec -= 1;
						}
						else
						{
							iDataFieldLen = (int)
								MOTObject.Header.vecbiData.Separate(15);
							
							iSizeRec -= 2;
						}

						/* Get data */
						for (i = 0; i < iDataFieldLen; i++)
						{
							ucDatafield = (unsigned char)
								MOTObject.Header.vecbiData.Separate(8);

							/* TODO: Use information in data field */
						}
						break;
					}
				}

				/* We only use images */
				if (iContentType == 2 /* image */)
				{
					/* Check range of content sub type */
					if (iContentSubType < 4)
					{
						/* Set up MOT picture ------------------------------- */
						/* Reset bit access to extract data from body */
						MOTObject.Body.vecbiData.ResetBitAccess();

						/* Data size in bytes */
						iDaSiBytes =
							MOTObject.Body.vecbiData.Size() / SIZEOF__BYTE;

						/* Copy data */
						NewPic.vecbRawData.Init(iDaSiBytes);
						for (int i = 0; i < iDaSiBytes;	i++)
							NewPic.vecbRawData[i] =
								(_BYTE) MOTObject.Body.vecbiData.Separate(8);

						/* Set format */
						switch (iContentSubType)
						{
						case 0: /* gif */
							NewPic.strFormat = "gif";
							break;

						case 1: /* jfif */
							NewPic.strFormat = "jpeg";
							break;

						case 2: /* bmp */
							NewPic.strFormat = "bmp";
							break;

						case 3: /* png */
							NewPic.strFormat = "png";
							break;

						default:
							NewPic.strFormat = "";
							break;
						}

						/* Set ID */
						NewPic.iTransportID = MOTObject.iTransportID;
					}
				}

				/* Reset MOT object */
				MOTObject.Header.Reset();
				MOTObject.Body.Reset();
			}
		}
	}
}

void CDABData::CDataUnit::Add(CVector<_BINARY>& vecbiNewData, int iSegmentSize,
							  int iSegNum)
{
	/* Add new data (bit-wise copying) */
	int iOldDataSize = vecbiData.Size();

	vecbiData.Enlarge(iSegmentSize * SIZEOF__BYTE);

	/* Read useful bits */
	for (int i = 0; i < iSegmentSize * SIZEOF__BYTE; i++)
		vecbiData[iOldDataSize + i] =
			(_BINARY) vecbiNewData.Separate(1);

	/* Set new segment number */
	iDataSegNum = iSegNum;
}

void CDABData::CDataUnit::Reset()
{
	vecbiData.Init(0);
	bOK = FALSE;
	bReady = FALSE;
	iDataSegNum = -1;
}
