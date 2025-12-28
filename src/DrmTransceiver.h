/******************************************************************************\
 *
 * Copyright (c) 2012
 *
 * Author(s):
 *	David Flamand
 *
 * Description:
 *	DRM receiver-transmitter base class
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

#ifndef DRM_TRANSCEIVER_H
#define DRM_TRANSCEIVER_H

#include "sound/soundfactory.h"
#include <vector>

class CSettings;
class CParameter;
enum ERunState { STOPPED, RUNNING, STOP_REQUESTED, RESTART };

class CDRMTransceiver {
public:
  CDRMTransceiver();
  virtual ~CDRMTransceiver();

  virtual void LoadSettings() = 0;
  virtual void SaveSettings() = 0;
  virtual void SetInputDevice(std::string name) {
    soundinfactory.SetItem(name);
  };
  virtual void SetOutputDevice(std::string name) {
    soundoutfactory.SetItem(name);
  };
  virtual void EnumerateInputs(std::vector<std::string> &names,
                               std::vector<std::string> &descriptions,
                               std::string &defaultInput) {
    return soundinfactory.Enumerate(names, descriptions, defaultInput);
  };
  virtual void EnumerateOutputs(std::vector<std::string> &names,
                                std::vector<std::string> &descriptions,
                                std::string &defaultOutput) {
    return soundoutfactory.Enumerate(names, descriptions, defaultOutput);
  };
  virtual CSettings *GetSettings() { return pSettings; };
  virtual void SetSettings(CSettings *pNewSettings) {
    pSettings = pNewSettings;
  };
  virtual CParameter *GetParameters() { return &Parameters; };
  virtual bool IsReceiver() const = 0;
  virtual bool IsTransmitter() const = 0;

protected:
  CParameter &Parameters;
  CSettings *pSettings;
  CSoundFactoryIn soundinfactory;
  CSoundFactoryOut soundoutfactory;
};

#endif
