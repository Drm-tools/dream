/******************************************************************************\
 *
 * Copyright (c) 2013
 *
 * Author(s):
 *  David Flamand
 *
 * Description:
 *  See AudioCodec.cpp
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

#ifndef AUDIOCODECLIST_H_
#define AUDIOCODECLIST_H_

#include <vector>
#include "../Parameter.h"
#include "AudioCodec.h"
#define AC_NULL ((CAudioParam::EAudCod)-1)

class CAudioCodecList
{
public:
    CAudioCodecList();
    virtual ~CAudioCodecList();
    CAudioCodec* GetDecoder(CAudioParam::EAudCod eAudioCoding, bool bCanReturnNullPtr=false);
    CAudioCodec* GetEncoder(CAudioParam::EAudCod eAudioCoding, bool bCanReturnNullPtr=false);

private:
	std::vector<CAudioCodec*> CodecList;
	int RefCount;
};

#endif // _AUDIOCODECLIST_H_
