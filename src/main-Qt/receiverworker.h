#ifndef RECEIVERWORKER_H
#define RECEIVERWORKER_H

#include "src/main-Qt/ReceiverQt.h"
#include <QThread>

class CReceiverWorker : public QThread
{
public:
    explicit CReceiverWorker(CReceiverQt* nrx, QObject *parent = nullptr);
protected:
    void run() override;
    CReceiverQt* rx;
};

#endif // RECEIVERWORKER_H
