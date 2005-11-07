/******************************************************************************\
 * Technische Universitaet Darmstadt, Institut fuer Nachrichtentechnik
 * Copyright (c) 2001
 *
 * Author(s):
 *	Volker Fischer, Andrea Russo
 *
 * Description:
 *	See DABMOT.cpp
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

#if !defined(DABMOT_H__3B0UBVE98732KJVEW363E7A0D31912__INCLUDED_)
#define DABMOT_H__3B0UBVE98732KJVEW363E7A0D31912__INCLUDED_

#include "../GlobalDefinitions.h"
#include "../util/Vector.h"
#include "../util/CRC.h"

#ifdef HAVE_LIBFREEIMAGE
# include <FreeImage.h>
#endif


/* Definitions ****************************************************************/
/* Invalid data segment number. Shall be a negative value since the test for
   invalid data segment number is always "if (iDataSegNum < 0)" */
#define INVALID_DATA_SEG_NUM			-1

/* Maximum number of bytes for zip'ed files. We need to specify this number to
   avoid segmentation faults due to erroneous zip header giving a much too high
   number of bytes */
#define MAX_DEC_NUM_BYTES_ZIP_DATA		1000000 /* 1 MB */


/* Classes ********************************************************************/
class CDataUnit
{
public:
	CDataUnit() {Reset();}

	CDataUnit& operator=(const CDataUnit& nDU)
	{
		ResizeAndCopyVector(nDU.vecbiData);
		bReady = nDU.bReady;
		bOK = nDU.bOK;
		iDataSegNum = nDU.iDataSegNum;
		return *this;
	}

	void Reset();
	void Add(CVector<_BINARY>& vecbiNewData, const int iSegmentSize,
		const int iSegNum);
	void ResizeAndCopyVector(const CVector<_BINARY>& vecbiNewData);

	CVector<_BINARY>	vecbiData;
	_BOOLEAN			bOK, bReady;
	int					iDataSegNum;
};

class CMOTObjectRaw
{
public:
	CMOTObjectRaw() {Reset();}

	CMOTObjectRaw& operator=(const CMOTObjectRaw& nOR)
	{
		iTransportID = nOR.iTransportID;
		bDispose = nOR.bDispose;
		Header = nOR.Header;
		Body = nOR.Body;
		return *this; 
	}

	void Reset();

	int			iTransportID;
	_BOOLEAN	bDispose;
	CDataUnit	Header;
	CDataUnit	Body;
};

class CMOTDirectoryHeader
{
public:
	int			iTransportID;
	CDataUnit	Header;
};

class CMOTObject
{
public:
	CMOTObject() {Reset();}
	CMOTObject(const CMOTObject& NewObj) : vecbRawData(NewObj.vecbRawData),
		strFormat(NewObj.strFormat), strName(NewObj.strName),
		strMimeType(NewObj.strMimeType),
		iCompressionType(NewObj.iCompressionType),
		strContentDescription(NewObj.strContentDescription) {}

	inline CMOTObject& operator=(const CMOTObject& NewObj)
	{
		strName = NewObj.strName;
		strFormat = NewObj.strFormat;
		strMimeType = NewObj.strMimeType;
		iCompressionType = NewObj.iCompressionType;
		strContentDescription = NewObj.strContentDescription;
		iVersion = NewObj.iVersion;

		vecbRawData.Init(NewObj.vecbRawData.Size());
		vecbRawData = NewObj.vecbRawData;

		return *this;
	}

	void Reset()
	{
		vecbRawData.Init(0);
		strFormat = "";
		strName = "";
		strMimeType = "";
		iCompressionType = 0;
		strContentDescription = "";
		iVersion = 0;
	}

	CVector<_BYTE>	vecbRawData;
	string			strName;
	string			strFormat;
	string			strMimeType;
	int				iCompressionType;
	string			strContentDescription;
	int				iVersion;
};


/* Encoder ------------------------------------------------------------------ */
class CMOTDABEnc
{
public:
	CMOTDABEnc() {}
	virtual ~CMOTDABEnc() {}

	void Reset();
	_BOOLEAN GetDataGroup(CVector<_BINARY>& vecbiNewData);
	void SetMOTObject(CMOTObject& NewMOTObject);
	_REAL GetProgPerc() const;

protected:
	class CMOTObjSegm
	{
	public:
		CVector<CVector<_BINARY> > vvbiHeader;
		CVector<CVector<_BINARY> > vvbiBody;
	};

	void GenMOTSegments(CMOTObjSegm& MOTObjSegm);
	void PartitionUnits(CVector<_BINARY>& vecbiSource,
						CVector<CVector<_BINARY> >& vecbiDest,
						const int iPartiSize);

	void GenMOTObj(CVector<_BINARY>& vecbiData, CVector<_BINARY>& vecbiSeg,
				   const _BOOLEAN bHeader, const int iSegNum,
				   const int iTranspID, const _BOOLEAN bLastSeg);

	CMOTObject		MOTObject;
	CMOTObjSegm		MOTObjSegments;

	int				iSegmCntHeader;
	int				iSegmCntBody;
	_BOOLEAN		bCurSegHeader;

	int				iContIndexHeader;
	int				iContIndexBody;

	int				iTransportID;
};


/* Decoder ------------------------------------------------------------------ */
class CMOTDABDec
{
public:
	CMOTDABDec() : iDirectoryTransportId(0) {vecMOTCarouselRaw.Init(0);}
	virtual ~CMOTDABDec() {}

	_BOOLEAN AddDataGroup(CVector<_BINARY>& vecbiNewData);
	void GetMOTObject(CMOTObject& NewMOTObject)
		{NewMOTObject = MOTObject; /* Simply copy object */}

protected:
	void DecodeObject(CMOTObjectRaw& MOTObjectRaw);
	_BOOLEAN GetObjectHeader(const int iTransportID,
		CMOTObjectRaw& MOTObjectRaw);

	int FindObjectIntoCarousel(const int iTransportID);
	int AddCarouselObject(CMOTObjectRaw& MOTObjectRaw);
	string ExtractString(CVector<_BINARY>& vecbiData, const int iDataLen);

	void BinaryVecToByteVec(CVector<_BINARY>& vecbiIn,
		CVector<_BYTE>& vecbReturn);

	_BOOLEAN IsZipped(CVector<_BINARY>& vecbiData);
	unsigned int gzGetOriginalSize(const CVector<_BYTE>& vecbData);

	CMOTObject						MOTObject;
	CVector<CMOTObjectRaw>			vecMOTCarouselRaw;
	CMOTObjectRaw					MOTObjectRaw;
	CMOTObjectRaw					MOTDirectoryRaw;
	CVector<CMOTDirectoryHeader>	vecMOTDirectoryHeaders;
	int								iDirectoryTransportId;
};


#endif // !defined(DABMOT_H__3B0UBVE98732KJVEW363E7A0D31912__INCLUDED_)
