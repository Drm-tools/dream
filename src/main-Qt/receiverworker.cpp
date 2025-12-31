#include "receiverworker.h"
#include "qeventloop.h"

CReceiverWorker::CReceiverWorker(CReceiverQt* nrx, QObject *parent): QThread{parent}, rx(nrx)
{}

void CReceiverWorker::run() {
    QEventLoop eventLoop;
    do {
        eventLoop.processEvents();
        rx->process();
    } while(!isInterruptionRequested());
}
