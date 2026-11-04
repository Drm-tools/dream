/******************************************************************************\
 * Description:
 *  Raw sound interface on stdin / stdout, for running the transmitter (or the
 *  receiver) as a filter in a pipeline.
 *
 *  Device name "-"      : 16 bit signed little endian, stereo interleaved
 *  Device name "-mono"  : 16 bit signed little endian, mono (on output the left
 *                         channel is written, on input it is used as both channels)
 *  Reading never paces: it blocks on the pipe. At end of file the rest of the
 *  block is zero filled and IsEof() becomes true.
 *
 * This program is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation; either version 2 of the License, or (at your option) any later
 * version.
\******************************************************************************/

#ifndef SOUNDSTDIO_H
#define SOUNDSTDIO_H

#include "soundinterface.h"

class CSoundInStdin : public CSoundInInterface
{
public:
    CSoundInStdin() : strName("-"), bMono(false), bEof(false), iBufferSize(0) {}
    virtual void Enumerate(std::vector<std::string>& names, std::vector<std::string>& descriptions, std::string& defaultDevice);
    virtual std::string GetItemName() { return strName; }
    virtual void SetItem(std::string sNewDev);
    virtual bool Init(int iSampleRate, int iNewBufferSize, bool bNewBlocking);
    virtual bool Read(CVector<short>& psData, CParameter& Parameters);
    virtual void Close() {}
    virtual std::string GetVersion() { return "stdin (raw s16le)"; }
    virtual CSoundInInterface* GetItem() { return this; }
    virtual bool IsEof() { return bEof; }
private:
    std::string strName;
    bool bMono, bEof;
    int iBufferSize;
};

class CSoundOutStdout : public CSoundOutInterface
{
public:
    CSoundOutStdout() : strName("-"), bMono(false) {}
    virtual void Enumerate(std::vector<std::string>& names, std::vector<std::string>& descriptions, std::string& defaultDevice);
    virtual std::string GetItemName() { return strName; }
    virtual void SetItem(std::string sNewDev);
    virtual bool Init(int iSampleRate, int iNewBufferSize, bool bNewBlocking);
    virtual bool Write(CVector<short>& psData);
    virtual void Close();
    virtual std::string GetVersion() { return "stdout (raw s16le)"; }
    virtual CSoundOutInterface* GetItem() { return this; }
private:
    std::string strName;
    bool bMono;
};

#endif
