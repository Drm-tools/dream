/******************************************************************************\
 * Technische Universitaet Darmstadt, Institut fuer Nachrichtentechnik
 * Copyright (c) 2001
 *
 * Author(s):
 *	Volker Fischer
 *
 * Description:
 *	See DABData.cpp
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

#if !defined(DABDATA_H__3B0BAOHWEF78WF_987FW363E7A0D31912__INCLUDED_)
#define DABDATA_H__3B0BAOHWEF78WF_987FW363E7A0D31912__INCLUDED_

#include "../GlobalDefinitions.h"
#include "../Vector.h"
#include "../CRC.h"


/* Classes ********************************************************************/
class CMOTObjSegm
{
public:
	CVector<CVector<_BINARY> > vvbiHeader;
	CVector<CVector<_BINARY> > vvbiBody;
};

class CDataUnit
{
public:
	CDataUnit() {Reset();}

	void Reset();
	void Add(CVector<_BINARY>& vecbiNewData, int iSegmentSize, int iSegNum);

	CVector<_BINARY>	vecbiData;
	_BOOLEAN			bOK;
	_BOOLEAN			bReady;
	int					iDataSegNum;
};

class CMOTObject
{
public:
	int					iTransportID;
	CDataUnit			Header;
	CDataUnit			Body;
};


/* Encoder ------------------------------------------------------------------ */
class CDABDataEnc
{
public:
	CDABDataEnc() {}
	virtual ~CDABDataEnc() {}

	void Init();
	void GetDataUnit(CVector<_BINARY>& vecbiNewData);


protected:
	void GenMOTSegments(CMOTObjSegm& MOTObjSegm);
	void PartitionUnits(CVector<_BINARY>& vecbiSource,
						CVector<CVector<_BINARY> >& vecbiDest,
						const int iPartiSize);

	void GenMOTObj(CVector<_BINARY>& vecbiData, CVector<_BINARY>& vecbiSeg,
				   const _BOOLEAN bHeader, const int iSegNum,
				   const int iTranspID, const _BOOLEAN bLastSeg);

	CMOTObjSegm MOTObjSegments;

	int			iSegmCnt;
	_BOOLEAN	bCurSegHeader;

	int			iContIndexHeader;
	int			iContIndexBody;

	int			iTransportID;
};


/* Decoder ------------------------------------------------------------------ */
class CMOTPicture
{
public:
	CMOTPicture() : vecbRawData(0), strFormat(""), iTransportID(-1) {}

	CVector<_BYTE>	vecbRawData;
	string			strFormat;
	int				iTransportID;
};

class CDABData
{
public:
	CDABData() {}
	virtual ~CDABData() {}

	void AddDataUnit(CVector<_BINARY>& vecbiNewData, CMOTPicture& NewPic);


protected:
	CMOTObject MOTObject;
};


#endif // !defined(DABDATA_H__3B0BAOHWEF78WF_987FW363E7A0D31912__INCLUDED_)
