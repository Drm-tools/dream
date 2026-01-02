/******************************************************************************\
 * British Broadcasting Corporation
 * Copyright (c) 2007
 *
 * Author(s):
 *	Julian Cable
 *
 * Description:
 *	Jack sound classes
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

#ifndef _JACK_H
#define _JACK_H

#include "../sound/soundinterface.h"
#include <jack/jack.h>
#include <jack/ringbuffer.h>
#include <map>
#include <utility>

/* Classes ********************************************************************/

struct instance_data_t
{
    instance_data_t();
    ~instance_data_t();
    int num_channels;
    jack_port_t *left;
    jack_port_t *right;
    jack_ringbuffer_t* buff;
    int underruns;
    int overruns;
    std::string peer_left, peer_right;
};

class CSoundInJack : public CSoundInInterface
{
public:
    CSoundInJack();
    virtual ~CSoundInJack();
    CSoundInJack(const CSoundInJack& e);
    CSoundInJack& operator=(const CSoundInJack& e);

    virtual bool        Init(int iSampleRate, int iNewBufferSize, bool bNewBlocking) override;
    virtual bool	    Read(CVector<short>& psData, CParameter&) override;
    virtual void		Enumerate(std::vector<std::string>&, std::vector<std::string>&, std::string&) override;
    virtual std::string	GetItemName() override;
    virtual CSoundInInterface* GetItem() override { return dynamic_cast<CSoundInInterface*>(this); }
    virtual void		SetItem(std::string sNewDev) override;
    virtual void		Close() override;
	virtual std::string	GetVersion() override;
protected:
    int iBufferSize;
    bool bBlocking;
    bool device_changed;
    instance_data_t capture_data;
    std::string dev;
};

class CSoundOutJack : public CSoundOutInterface
{
public:
    CSoundOutJack();
    virtual ~CSoundOutJack();
    CSoundOutJack(const CSoundOutJack& e);
    CSoundOutJack& operator=(const CSoundOutJack& e);

    virtual bool        Init(int iSampleRate, int iNewBufferSize, bool bNewBlocking) override;
    virtual bool	    Write(CVector<short>& psData) override;
    virtual void		Enumerate(std::vector<std::string>&, std::vector<std::string>&, std::string&) override;
    virtual std::string	GetItemName() override;
    virtual CSoundOutInterface* GetItem() override { return dynamic_cast<CSoundOutInterface*>(this); }
    virtual void		SetItem(std::string) override;
    virtual void		Close() override;
	virtual std::string	GetVersion() override;
protected:
    int iBufferSize;
    bool bBlocking;
    bool device_changed;
    instance_data_t play_data;
    std::string dev;
};

#endif
