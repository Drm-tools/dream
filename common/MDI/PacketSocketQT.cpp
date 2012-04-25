/******************************************************************************\
 * Technische Universitaet Darmstadt, Institut fuer Nachrichtentechnik
 * Copyright(c) 2004
 *
 * Author(s):
 *	Volker Fischer, Julian Cable, Oliver Haffenden
 *
 * Description:
 *
 * This is an implementation of the CPacketSocket interface that wraps up a QT socket.
 *
 *
 ******************************************************************************
 *
 * This program is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation; either version 2 of the License, or(at your option) any later
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

#include "PacketSocketQT.h"
#include <qstringlist.h>
#include <qtimer.h>
#include <iostream>
#include <sstream>

#include <errno.h>
#ifndef _WIN32
# include <netinet/in.h>
# include <arpa/inet.h>
#endif

#ifdef _WIN32
/* Always include winsock2.h before windows.h */
# include <winsock2.h>
# include <ws2tcpip.h>
# include <windows.h>
#endif

/* Some defines needed for compatibility when using Linux */
#ifndef _WIN32
typedef int SOCKET;
# define SOCKET_ERROR				(-1)
# define INVALID_SOCKET				(-1)
#endif

CPacketSocketQT::CPacketSocketQT(bool udp):
        HostAddrOut(), iHostPortOut(-1), pSocket(NULL),
        writeLock(),writeBuf()
{
}

CPacketSocketQT::~CPacketSocketQT()
{
}

// Set the sink which will receive the packets
void
CPacketSocketQT::SetPacketSink(CPacketSink * pSink)
{
    pPacketSink = pSink;
}

// Stop sending packets to the sink
void
CPacketSocketQT::ResetPacketSink(void)
{
    pPacketSink = NULL;
}

// Send packet to the socket
void
CPacketSocketQT::SendPacket(const vector < _BYTE > &vecbydata, uint32_t addr, uint16_t port)
{
    int bytes_written;
    /* Send packet to network */
    //cout << "CPacketSocketQT::SendPacket(" << vecbydata.size() << " bytes, " << addr << ", " << port << ") " << HostAddrOut.toString() << ":" << iHostPortOut << endl;

    //QUdpSocket* s = dynamic_cast<QUdpSocket*>(pSocket);
    QUdpSocket* s = pSocket;
    if (s != NULL)
        bytes_written = s->writeDatagram((char*)&vecbydata[0], vecbydata.size(), HostAddrOut, iHostPortOut);
    else
        bytes_written = pSocket->write((char*)&vecbydata[0], vecbydata.size());
}

QStringList
CPacketSocketQT::parseDest(const string & strNewAddr)
{
    return QString(strNewAddr.c_str()).split(":", QString::KeepEmptyParts);
}

_BOOLEAN
CPacketSocketQT::SetDestination(const string & strNewAddr)
{
    /* syntax
       1:  <port>                send to port on localhost
       2:  <ip>:<port>           send to port on host or port on m/c group
       3:  <ip>:<ip>:<port>      send to port on m/c group via interface
     */
    /* Init return flag and copy string in QT-String "QString" */
    int ttl = 127;
    _BOOLEAN bAddressOK = TRUE;
    //QUdpSocket* pSocket = dynamic_cast<QUdpSocket*>(pSocket);
    QUdpSocket* pSocket = pSocket;
    QStringList parts = parseDest(strNewAddr);
    switch (parts.count())
    {
    case 1: // Just a port - send to ourselves
        bAddressOK = HostAddrOut.setAddress("127.0.0.1");
        iHostPortOut = parts[0].toUInt();
        break;
    case 2: // host and port, unicast
        bAddressOK = HostAddrOut.setAddress(parts[0]);
        iHostPortOut = parts[1].toUInt();
        if (pSocket != NULL)
        {
# if QT_VERSION < 0x040800
            if (setsockopt(pSocket->socketDescriptor(), IPPROTO_IP, IP_TTL,
                           (char*)&ttl, sizeof(ttl))==SOCKET_ERROR)
                bAddressOK = FALSE;
# else
            pSocket->setSocketOption(QAbstractSocket::MulticastTtlOption, ttl);
# endif
        }
        else
        {
            pSocket->connectToHost(HostAddrOut, iHostPortOut);
            bAddressOK = pSocket->waitForConnected(5000);
        }
        break;
    case 3:
    {
        QHostAddress AddrInterface;
        AddrInterface.setAddress(parts[0]);
        bAddressOK = HostAddrOut.setAddress(parts[1]);
        iHostPortOut = parts[2].toUInt();
#if QT_VERSION < 0x040800
        const SOCKET s = pSocket->socketDescriptor();
        uint32_t mc_if = htonl(AddrInterface.toIPv4Address());
        if (setsockopt(s, IPPROTO_IP, IP_MULTICAST_IF,
                       (char *) &mc_if, sizeof(mc_if)) == SOCKET_ERROR)
            bAddressOK = FALSE;
        if (setsockopt(s, IPPROTO_IP, IP_MULTICAST_TTL,
                       (char*) &ttl, sizeof(ttl)) == SOCKET_ERROR)
            bAddressOK = FALSE;
#else
        if (pSocket != NULL)
        {
            pSocket->setMulticastInterface(GetInterface(AddrInterface));
            pSocket->setSocketOption(QAbstractSocket::MulticastTtlOption, ttl);
        }
#endif
    }
    break;
    default:
        bAddressOK = FALSE;
    }
    return bAddressOK;
}


_BOOLEAN
CPacketSocketQT::GetDestination(string & str)
{
    stringstream s;
    s << HostAddrOut.toString().toLatin1().constData() << ":" << iHostPortOut;
    str = s.str();
    return TRUE;
}


_BOOLEAN
CPacketSocketQT::SetOrigin(const string & strNewAddr)
{
    /* syntax (unwanted fields can be empty, e.g. <source ip>::<group ip>:<port>
       1:  <port>
       2:  <group ip>:<port>
       3:  <interface ip>:<group ip>:<port>
       4:  <source ip>:<interface ip>:<group ip>:<port>
       5: - for TCP - no need to separately set origin
     */

    if (strNewAddr == "-")
    {
        if (pSocket==NULL) {
            //pSocket = new QTcpSocket();
        }
        return TRUE;
    }

    int iPort=-1;
    QHostAddress AddrGroup, AddrInterface, AddrSource;
    QStringList parts = parseDest(strNewAddr);
    bool ok=true;
    switch (parts.count())
    {
    case 1:
        iPort = parts[0].toUInt(&ok);
        break;
    case 2:
        iPort = parts[1].toUInt(&ok);
        ok &= AddrGroup.setAddress(parts[0]);
        break;
    case 3:
        iPort = parts[2].toUInt(&ok);
        if (parts[0].length() > 0)
            ok &= AddrInterface.setAddress(parts[0]);
        if (parts[1].length() > 0)
            ok &= AddrGroup.setAddress(parts[1]);
        break;
    case 4:
        iPort = parts[3].toUInt(&ok);
        if (parts[0].length() > 0)
            ok &= AddrSource.setAddress(parts[0]);
        if (parts[1].length() > 0)
            ok &= AddrInterface.setAddress(parts[1]);
        if (parts[2].length() > 0)
            ok &= AddrGroup.setAddress(parts[2]);
        break;
    default:
        ok = false;
    }

    if (ok)
    {
        if (pSocket==NULL)
            pSocket = new QUdpSocket();
        QObject::connect(pSocket, SIGNAL(readyRead()), this, SLOT(OnDataReceived()));
        qDebug("connected signal to slot");

        sourceAddr = AddrSource.toIPv4Address();
        /* Multicast ? */
        uint32_t gp = AddrGroup.toIPv4Address();
        if (gp == 0)
        {
            /* Initialize the listening socket. */
            pSocket->bind(AddrInterface, iPort);
        }
        else if ((gp & 0xe0000000) == 0xe0000000)	/* multicast! */
        {

            /* Initialize the listening socket. Host address is 0 -> "INADDR_ANY" */
            bool ok = pSocket->bind(iPort, QUdpSocket::ShareAddress);
            if (ok == false)
            {
                throw CGenErr("Can't bind to port to receive packets");
            }
            else
                qDebug("bound port in shared mode");
#if QT_VERSION < 0x040800
            struct ip_mreq mreq;
            mreq.imr_multiaddr.s_addr = htonl(AddrGroup.toIPv4Address());
            mreq.imr_interface.s_addr = htonl(AddrInterface.toIPv4Address());
            int n = setsockopt(pSocket->socketDescriptor(), IPPROTO_IP, IP_ADD_MEMBERSHIP,(char *) &mreq,	sizeof(mreq));
            if (n == SOCKET_ERROR)
                ok = false;
#else
            ok = pSocket->joinMulticastGroup(AddrGroup);
#endif
            if (!ok)
            {
                qDebug("Can't join multicast group");
                //throw CGenErr(string());
            }
        }
        else /* one address specified, but not multicast - listen on a specific interface */
        {
            /* Initialize the listening socket. */
            pSocket->bind(AddrGroup, iPort);
        }
        return TRUE;
    }
    return FALSE;
}

QNetworkInterface
CPacketSocketQT::GetInterface(QHostAddress AddrInterface)
{
    QList<QNetworkInterface> list = QNetworkInterface::allInterfaces ();
    QList<QNetworkInterface>::const_iterator ifIt;
    for ( ifIt = list.begin(); ifIt != list.end(); ++ifIt )
    {
        QList<QNetworkAddressEntry> addresses = ifIt->addressEntries();
        QList<QNetworkAddressEntry>::const_iterator i;
        for (i = addresses.begin(); i!=addresses.end(); ++i)
        {
            if (i->ip() == AddrInterface)
            {
                return *ifIt;
            }
        }
    }
    return QNetworkInterface::allInterfaces().first();
}

void
CPacketSocketQT::poll()
{
    vector < _BYTE > vecbydata(MAX_SIZE_BYTES_NETW_BUF);
     while (pSocket->hasPendingDatagrams()) {
         vecbydata.resize(pSocket->pendingDatagramSize());
         QHostAddress sender;
         quint16 senderPort;

         pSocket->readDatagram((char*)&vecbydata[0], vecbydata.size(), &sender, &senderPort);

        uint32_t addr = sender.toIPv4Address();
        pPacketSink->SendPacket(vecbydata, addr, senderPort);
     }
}

void
CPacketSocketQT::OnDataReceived()
{
    qDebug("packet received");
    vector < _BYTE > vecbydata(MAX_SIZE_BYTES_NETW_BUF);
    while (pSocket->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(pSocket->pendingDatagramSize());
        QHostAddress sender;
        quint16 senderPort;

        pSocket->readDatagram(datagram.data(), datagram.size(),
                              &sender, &senderPort);

        uint32_t addr = sender.toIPv4Address();
        vecbydata.resize(datagram.size());
        for (int i=0; i<datagram.size(); i++)
            vecbydata[i] = datagram[i];
        pPacketSink->SendPacket(vecbydata, addr, senderPort);
    }
}
