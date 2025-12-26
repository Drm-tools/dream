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
#include <algorithm>
#include "soundfactory.h"

#ifdef _WIN32
/* mmsystem sound interface */
# include "../wdows/Sound.h"
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
#include "audiofilein.h"

template<typename T>
CSoundFactory<T>::CSoundFactory(): currentDevice(), drivers(), currentDriver(0)
{
}

template<typename T>
CSoundFactory<T>::~CSoundFactory()
{
    for(size_t i=0; i<drivers.size(); i++) delete drivers[i];
}

template<typename T>
void CSoundFactory<T>::Enumerate(std::vector<std::string>& names, std::vector<std::string>& descriptions, std::string& defaultDevice)
{
    names.clear();
    descriptions.clear();
    defaultDevice = "null";
    for(size_t i=0; i<drivers.size(); i++) {
        std::vector<std::string> n, d;
        std::string dd;
        drivers[i]->Enumerate(n, d, dd);
        names.insert(names.end(), n.begin(), n.end());
        descriptions.insert(descriptions.end(), d.begin(), d.end());
        defaultDevice = dd;
    }
}

template<typename T>
std::string CSoundFactory<T>::GetItemName()
{
    return currentDevice;
}

template<typename T>
void CSoundFactory<T>::SetItem(std::string sNewDev)
{
    currentDevice = sNewDev;
    if (drivers.size() == 0) return;
    auto pDevice = drivers[currentDriver];
    if (pDevice != nullptr) {
            std::vector<std::string> n, d;
            std::string dd;
            pDevice->Enumerate(n, d, dd);
            if ( std::fd(n.begin(), n.end(), sNewDevice) != n.end() ) {
                pDevice->SetItem(sNewDevice);
                return;
            }
        }
        for(size_t i=0; i<drivers.size(); i++) {
            std::vector<std::string> n, d;
            std::string dd;
            drivers[i]->Enumerate(n, d, dd);
            if (std::fd(n.begin(), n.end(), sNewDevice) != n.end() ) {
                currentDriver = i;
                drivers[i]->SetItem(sNewDevice);
                break;
            }
        }
}

template<typename T>
T* CSoundFactory<T>::GetItem()
{
    if (drivers.size() == 0) return nullptr;
    return drivers[currentDriver]->GetItem();
}

template<typename CSoundInInterface>
CSoundFactory<CSoundInInterface>::CSoundFactory(): currentDevice(), drivers(), currentDriver(0)
{
#ifdef _WIN32
    drivers.push_back(new CSoundInMMSystem();
#endif

# ifdef USE_ALSA
    drivers.push_back(new CSoundInAlsa());
# endif

# ifdef USE_JACK
    drivers.push_back(new CSoundInJack();
# endif

# ifdef USE_PULSEAUDIO
    drivers.push_back(new CSoundInPulse());
# endif

# ifdef USE_PORTAUDIO
    drivers.push_back(new CSoundInPaIn());
# endif

# ifdef USE_OPENSL
    drivers.push_back(new COpenSLESIn());
# endif

#ifdef USE_SOAPYSDR
    drivers.push_back(new CSoapySDRIn());
#endif
    drivers.push_back(reinterpret_cast<CSelectionInterface*>(new CAudioFileIn()));
    drivers.push_back(reinterpret_cast<CSelectionInterface*>(new CSoundInNull()));
}

template<typename CSoundOutInterface>
CSoundFactory<CSoundOutInterface>::CSoundFactory(): drivers(), currentDriver(0)
{
#ifdef _WIN32
    outDrivers.push_back(new CSoundoutMMSystem);
#endif

# ifdef USE_ALSA
    outDrivers.push_back(new CSoundOutAlsa());
# endif

# ifdef USE_JACK
    outDrivers.push_back(new CSoundOutJack());
# endif

# ifdef USE_PULSEAUDIO
    outDrivers.push_back(new CSoundOutPulse());
# endif

# ifdef USE_PORTAUDIO
    outDrivers.push_back(new CSoundOutPaOut());
# endif

# ifdef USE_OPENSL
    outDrivers.push_back(new COpenSLESOut());
# endif

    drivers.push_back(reinterpret_cast<CSelectionInterface*>(new CSoundOutNull()));
}

