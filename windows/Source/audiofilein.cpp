/******************************************************************************\
 * British Broadcasting Corporation
 * Copyright (c) 2007
 *
 * Author(s):
 *	Julian Cable
 * 
 * Decription:
 * Read a file at the correct rate
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

#include "audiofilein.h"
#include <windows.h>
#include <iostream>

CAudioFileIn::CAudioFileIn(): CSoundInInterface(), pFileReceiver(NULL),
			strInFileName(), interval(0), timekeeper(0)
{
}

CAudioFileIn::~CAudioFileIn()
{
	Close();
}

void
CAudioFileIn::SetFileName(const string& strFileName)
{
	strInFileName = strFileName;
	cout << "CAudioFileIn::SetFileName(" << strFileName << ")" << endl;
}

void
CAudioFileIn::Init(int iNewBufferSize, _BOOLEAN bNewBlocking)
{
	cout << "CAudioFileIn::Init" << endl;
	/* Check previously a file was being used */
	if (pFileReceiver != NULL)
	{
		fclose(pFileReceiver);
		pFileReceiver = NULL;
	}

	pFileReceiver = fopen(strInFileName.c_str(), "rb");
	/* Check for error */
	if (pFileReceiver == NULL)
		throw CGenErr("The file " + strInFileName + " must exist.");

	/* The FILETIME structure is a 64-bit value representing 
	 * the number of 100-nanosecond intervals since January 1, 1601. 
	*/
	FILETIME now;
	GetSystemTimeAsFileTime(&now);
	timekeeper = *(uint64_t*)&now;
	/* interval also with 100ns resolution */
	interval = uint64_t(1e7 * double(iNewBufferSize) / double(SOUNDCRD_SAMPLE_RATE));
}

_BOOLEAN
CAudioFileIn::Read(CVector<short>& psData)
{
	cout << "CAudioFileIn::Read" << endl;
	FILETIME now;
	GetSystemTimeAsFileTime(&now);
	uint64_t now = *(uint64_t*)&now;
	int64_t delay = timekeeper + interval - now_us;
	timekeeper += interval;
	if(delay > 20000LL) /* don't expect too much resolution from Sleep */
	{
		Sleep(delay/10LL); /* us */
	}
	/* Read data from file ---------------------------------------------- */
	int iOutputBlockSize = psData.Size();
	for (int i = 0; i < iOutputBlockSize; i++)
	{
#ifdef FILE_DRM_USING_RAW_DATA
		short tIn;

		/* Read 2 bytes, 1 piece */
		if (fread((void*) &tIn, size_t(2), size_t(1), pFileReceiver) == size_t(0))
		{
			rewind(pFileReceiver);
			fread((void*) &tIn, size_t(2), size_t(1), pFileReceiver);
		}
		psData[i] = (short)tIn;
#else
		float tIn;

		if (fscanf(pFileReceiver, "%e\n", &tIn) == EOF)
		{
			/* If end-of-file is reached, stop simulation */
			return FALSE;
		}
		psData[i] = (short)tIn;
#endif
	}
	return TRUE;
}

void
CAudioFileIn::Close()
{
	cout << "CAudioFileIn::Close" << endl;
	/* Close file (if opened) */
	if (pFileReceiver != NULL)
		fclose(pFileReceiver);
}
