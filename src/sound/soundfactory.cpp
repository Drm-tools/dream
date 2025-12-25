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

CSoundFactory::CSoundFactory(): inDrivers(), outDrivers(), currentInDriver(0), currentOutDriver(0)
{
#ifdef _WIN32
    inDrivers.push_back(new CSoundInMMSystem);
    outDrivers.push_back(new CSoundoutMMSystem);
#endif

# ifdef USE_ALSA
    inDrivers.push_back(new CSoundInAlsa());
    outDrivers.push_back(CSoundOutAlsa());
# endif

# ifdef USE_JACK
    inDrivers.push_back(new CSoundInJack());
    outDrivers.push_back(new CSoundOutJack());
# endif

# ifdef USE_PULSEAUDIO
    inDrivers.push_back(new CSoundInPulse());
    outDrivers.push_back(new CSoundOutPulse());
# endif

# ifdef USE_PORTAUDIO

# endif

# ifdef USE_OPENSL

# endif


#ifdef USE_SOAPYSDR

#endif

#include "soundnull.h"
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

/*
 * British Broadcasting Corporation
 * Copyright (c) 2025
 *
 * Author(s):
 *	Julian Cable
 *
 * Decription:
 * compound selection interface
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

#if 0
#include <algorithm>
#include "selectioninterface.h"

class CCompoundSelectionInterface: public CSelectionInterface
{
public:
    CCompoundSelectionInterface():devices(),pDevice(nullptr)
    {
    }
    void Init(std::vector<CSelectionInterface*> ci)
    {
        devices = ci;
        for(size_t i=0; i<devices.size(); i++) {
            std::vector<std::string> n, d;
            std::string dd;
            devices[i]->Enumerate(n, d, dd);
	        if (n.size()>0) {
                pDevice = devices[i];
                break;
	        }
        }
    }
    virtual ~CCompoundSelectionInterface() {}
    virtual void Enumerate(std::vector<std::string>& names, std::vector<std::string>& descriptions, std::string& defaultDevice)
    {
        for(size_t i=0; i<devices.size(); i++) {
            std::vector<std::string> n, d;
            std::string dd;
            devices[i]->Enumerate(n, d, dd);
            names.insert(names.end(), n.begin(), n.end());
            descriptions.insert(descriptions.end(), d.begin(), d.end());
            defaultDevice = dd;
        }
    }

    virtual void SetDev(std::string sNewDevice)
    {
        if (pDevice != nullptr) {
            std::vector<std::string> n, d;
            std::string dd;
            pDevice->Enumerate(n, d, dd);
            if ( std::find(n.begin(), n.end(), sNewDevice) != n.end() ) {
                pDevice->SetDev(sNewDevice);
                return;
            }
        }
        for(size_t i=0; i<devices.size(); i++) {
            std::vector<std::string> n, d;
            std::string dd;
            devices[i]->Enumerate(n, d, dd);
            if (std::find(n.begin(), n.end(), sNewDevice) != n.end() ) {
                pDevice = devices[i];
                pDevice->SetDev(sNewDevice);
            }
        }
    }

    virtual std::string	GetDev()
    {
        if (pDevice != nullptr) return pDevice->GetDev();
        return "";
    }

protected:

    std::vector<CSelectionInterface*> devices;
    CSelectionInterface *pDevice;
};

#endif