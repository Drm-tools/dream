#include "TransmitterQt.h"
#include <vector>
#include <string>

using namespace std;

CTransmitterQt::CTransmitterQt(): eRunState(STOPPED)
{

}

void CTransmitterQt::Restart()
{
    eRunState = RESTART;
}

void CTransmitterQt::Stop()
{
    eRunState = STOP_REQUESTED;
}

void CTransmitterQt::EnumerateInputs(QStringList& names, QStringList& descriptions, QString& defaultInput)
{
    names.removeAll();
    descriptions.removeAll();
    defaultInput = "";
    vector<string> n, d;
    string def;
    CDRMTransceiver::EnumerateInputs(n, d, def);

    for(size_t i=0; i<n.size(); i++)
    {
        names.append(QString::fromStdString(n[i]));
        descriptions.append(QString::fromStdString(d[i]));
    }
    defaultInput = QString::fromStdString(def);
}

void CTransmitterQt::EnumerateOutputs(QStringList& names, QStringList& descriptions, QString& defaultOutput)
{
    names.removeAll();
    descriptions.removeAll();
    defaultOutput = "";
    vector<string> n, d;
    string def;
    CDRMTransceiver::EnumerateInputs(n, d, def);

    for(size_t i=0; i<n.size(); i++)
    {
        names.append(QString::fromStdString(n[i]));
        descriptions.append(QString::fromStdString(d[i]));
    }
    defaultOutput = QString::fromStdString(def);
}