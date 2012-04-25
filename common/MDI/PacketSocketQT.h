/******************************************************************************\
 * Technische Universitaet Darmstadt, Institut fuer Nachrichtentechnik
 * Copyright (c) 2004
 *
 * Author(s):
 *	Volker Fischer, Oliver Haffenden
 *
 * Description:
 *	Implementation of CPacketSocket interface that wraps up a QSocket. See PacketSocketQT.cpp.
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

#ifndef PACKET_SOCKET_QT_H_INCLUDED
#define PACKET_SOCKET_QT_H_INCLUDED

#include "../GlobalDefinitions.h"
#include "../util/Vector.h"
#include "../util/Buffer.h"

#include <QAbstractSocket>
#include <QUdpSocket>
#include <QHostAddress>
#include <QNetworkInterface>
#if QT_VERSION >= 0x040800
# include <QNetworkAddressEntry>
#endif
#include <QDateTime>
#include <QMutex>

/* Maximum number of bytes received from the network interface. Maximum data
   rate of DRM is approx. 80 kbps. One MDI packet must be sent each DRM frame
   which is every 400 ms -> 0.4 * 80000 / 8 = 4000 bytes. Allocating more than
   double of this size should be ok for all possible cases */
#define MAX_SIZE_BYTES_NETW_BUF		10000

#include "PacketInOut.h"

class CPacketSocketQT : public QObject, public CPacketSocket
{
	Q_OBJECT

public:
	CPacketSocketQT(bool udp=true);
	~CPacketSocketQT();
	// Set the sink which will receive the packets
	void SetPacketSink(CPacketSink *pSink);
	// Stop sending packets to the sink
	void ResetPacketSink(void);

	// Send packet to the socket
	void SendPacket(const vector<_BYTE>& vecbydata, uint32_t addr=0, uint16_t port=0);

	_BOOLEAN SetDestination(const string& str);
	_BOOLEAN SetOrigin(const string& str);

	_BOOLEAN GetDestination(string& str);

	void poll();

private:
	QStringList parseDest(const string & strNewAddr);
	_BOOLEAN doSetSource(QHostAddress, QHostAddress, int, QHostAddress);
	QNetworkInterface GetInterface(QHostAddress AddrInterface);
	CPacketSink *pPacketSink;

	uint32_t	sourceAddr;
	QHostAddress	HostAddrOut;
	int		iHostPortOut;

	QUdpSocket* pSocket;
	QMutex		writeLock;
	vector<_BYTE>	writeBuf;

public slots:
	void OnDataReceived();

};

#endif
