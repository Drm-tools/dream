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

#ifdef _WIN32
# include <windows.h>
#endif


/* Classes ********************************************************************/
class CDABData
{
public:
	CDABData() {}
	virtual ~CDABData() {}

	void AddDataUnit(CVector<_BINARY>& vecbiNewData);

protected:
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

	CMOTObject MOTObject;
};


#endif // !defined(DABDATA_H__3B0BAOHWEF78WF_987FW363E7A0D31912__INCLUDED_)
