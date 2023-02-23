#include "PacketSocketHTTP.h"
#include <string>
#include <sstream>
#include <iostream>
#include <QNetworkReply>
#include <QAuthenticator>

CPacketSocketHTTP::CPacketSocketHTTP()
{
    pNetworkAccessManager = new QNetworkAccessManager(this);
    connect(pNetworkAccessManager, &QNetworkAccessManager::finished, this, &CPacketSocketHTTP::onFinished);
    connect(this, &CPacketSocketHTTP::postDataReady, this, &CPacketSocketHTTP::doPost);
    connect(pNetworkAccessManager, &QNetworkAccessManager::authenticationRequired, this, &CPacketSocketHTTP::onAuthRequired);

}
CPacketSocketHTTP::~CPacketSocketHTTP()
{

}

// Set the sink which will receive the packets
void CPacketSocketHTTP::SetPacketSink(CPacketSink *pSink)
{
}

// Stop sending packets to the sink
void CPacketSocketHTTP::ResetPacketSink(void)
{

}

// Send packet to the socket
void CPacketSocketHTTP::SendPacket(const std::vector<_BYTE>& vecbydata, uint32_t addr, uint16_t port)
{
    std::cout<<"emitting postDataReady signal"<<std::endl;
    QByteArray qdata(reinterpret_cast<const char*>(vecbydata.data()), vecbydata.size());
    emit postDataReady(qdata);
}

void CPacketSocketHTTP::doPost(const QByteArray& qdata)
{
    std::cout<<"Sending packet to http"<<std::endl;
    QNetworkRequest req(QString::fromStdString(dest));
    pNetworkAccessManager->post(req, qdata);
}

void CPacketSocketHTTP::onFinished(QNetworkReply *pReply)
{
    std::cout<<"onFinished called; reply error num " <<pReply->error() << " string: " << pReply->errorString().toStdString() << std::endl;
    pReply->deleteLater();
}

void CPacketSocketHTTP::onAuthRequired(QNetworkReply *reply, QAuthenticator *authenticator)
{
    authenticator->setUser("user");
    authenticator->setPassword("password");
}

bool CPacketSocketHTTP::SetDestination(const std::string& str)
{

    std::istringstream iss(str);
    getline(iss, destScheme, ':');
    while (iss.peek()=='/')
        iss.get();
    getline(iss, destHost, '/');
    getline(iss, destPath);
    dest = str;
    std::cout<<"dest scheme " << destScheme << " host " << destHost << " path " << destPath <<std::endl;

    if (destScheme == "https")
    {
        QSslConfiguration sslConfig;

        pNetworkAccessManager->connectToHostEncrypted(QString::fromStdString(destHost));


    }
    else {
        pNetworkAccessManager->connectToHost(QString::fromStdString(destHost));
    }
    return true;
}
bool CPacketSocketHTTP::SetOrigin(const std::string& str)
{
    return true;

}

bool CPacketSocketHTTP::GetDestination(std::string& str)
{
    str = dest;
    return true;

}

bool CPacketSocketHTTP::GetOrigin(std::string& str)
{
    return true;
}

void CPacketSocketHTTP::poll()
{

}
