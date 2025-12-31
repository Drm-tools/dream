#include "transmitterworker.h"
#include "qeventloop.h"

CTransmitterWorker::CTransmitterWorker(CTransmitterQt* ntx, QObject *parent)
    : QThread{parent}, tx(ntx)
{
}

void CTransmitterWorker::run() {
    QEventLoop eventLoop;
    do {
        eventLoop.processEvents();
        tx->process();
    } while(!isInterruptionRequested() || tx->CanSoftStopExit());
}
