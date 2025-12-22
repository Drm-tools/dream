/******************************************************************************\
 *
 * Copyright (c) 2013
 *
 * Author(s):
 *  David Flamand
 *
 * Description:
 *  Audio codec base class
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

#include "AudioCodecList.h"
#include "null_codec.h"
#include "aac_codec.h"
#include "opus_codec.h"
#include "fdk_aac_codec.h"
#include <iostream>
using namespace std;

CAudioCodecList::CAudioCodecList():CodecList(),RefCount(0)
{
	if (CodecList.size() == 0)
	{
		/* Null codec, MUST be the first */
		CodecList.push_back(new NullCodec);
        	CodecList.push_back(new AacCodec);
        	CodecList.push_back(new FdkAacCodec);
		CodecList.push_back(new OpusCodec);
	}
	RefCount ++;
}

CAudioCodecList::~CAudioCodecList() {
	RefCount --;
	if (!RefCount)
	{
		while (CodecList.size() != 0)
		{
			delete CodecList.back();
			CodecList.pop_back();
		}
	}
}

CAudioCodec*
CAudioCodecList::GetDecoder(CAudioParam::EAudCod eAudioCoding, bool bCanReturnNullPtr)
{
    for (size_t i = 0; i < CodecList.size(); i++) {
	CAudioCodec* codec = CodecList[i];
	cerr << i << "    " << codec->DecGetVersion() << "    " << codec->CanDecode(eAudioCoding) << endl;
    }
    for (size_t i = 1; i < CodecList.size(); i++) {
		CAudioCodec* codec = CodecList[i];
        if (codec->CanDecode(eAudioCoding)) {
	    	cerr << "using " << codec->DecGetVersion() << endl;
            return CodecList[unsigned(i)];
		}
    }
	/* Fallback to null codec */
    return bCanReturnNullPtr ? nullptr : CodecList[0]; // ie the null codec
}

CAudioCodec*
CAudioCodecList::GetEncoder(CAudioParam::EAudCod eAudioCoding, bool bCanReturnNullPtr)
{
	const int size = CodecList.size();
	for (int i = 1; i < size; i++)
		if (CodecList[i]->CanEncode(eAudioCoding))
			return CodecList[i];
	/* Fallback to null codec */
    return bCanReturnNullPtr ? nullptr : CodecList[0]; // ie the null codec
}
