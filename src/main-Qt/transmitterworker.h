#ifndef TRANSMITTERWORKER_H
#define TRANSMITTERWORKER_H

#include "TransmitterQt.h"
#include <QObject>
#include <QThread>

class CTransmitterWorker : public QThread
{
public:
    explicit CTransmitterWorker(CTransmitterQt* ntx, QObject *parent = nullptr);
protected:
    void run() override;
    CTransmitterQt *tx;
};

#endif // TRANSMITTERWORKER_H
