#include "soundfactory.h"

/******************************************************************************\
 * British Broadcasting Corporation
 * Copyright (c) 2007-2024
 *
 * Author(s):
 *	Julian Cable
 *
 * Decription:
 * sound device enumeratiion and selection
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

#ifdef _WIN32
/* mmsystem sound interface */
# include "../windows/Sound.h"
#endif

# ifdef USE_ALSA
#  include "../linux/alsain.h"
#  include "../linux/alsaout.h"
# endif

# ifdef USE_JACK
#  include "../linux/jack.h"
# endif

# ifdef USE_PULSEAUDIO
#  include "drm_pulseaudio.h"
# endif

# ifdef USE_PORTAUDIO
#  include "drm_portaudio.h"
# endif

# ifdef USE_OPENSL
#  include "../android/soundin.h"
#  include "../android/soundout.h"
# endif


#ifdef USE_SOAPYSDR
#  include "drm_soapySDR.h"
#endif

#include "soundnull.h"

CSoundFactory::CSoundFactory()
{

}

CSoundFactory::~CSoundFactory()
{
}

void CSoundFactory::Enumerate(std::vector<std::string>& names, std::vector<std::string>& descriptions, std::string& defaultDevice)
{
    names.clear();
    descriptions.clear();
    defaultDevice = "null";
    names.push_back("null");
    descriptions.push_back("no audio interface");
}

std::string CSoundFactory::GetDevName()
{
    return currentDevice;
}

void CSoundFactory::SetDev(std::string sNewDev)
{
    currentDevice = sNewDev;
}
CSoundInInterface* CSoundFactory::GetInDev()
{
    return new CSoundInNull();
}   

CSoundOutInterface* CSoundFactory::GetOutDev()
{
    return new CSoundOutNull();
}