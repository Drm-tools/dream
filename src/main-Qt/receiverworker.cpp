#include "receiverworker.h"
#include "qeventloop.h"

CReceiverWorker::CReceiverWorker(CReceiverQt* nrx, QObject *parent): QThread{parent}, rx(nrx)
{}

void CReceiverWorker::run() {
    QEventLoop eventLoop;

    qDebug("Working thread started");
    // set the frequency from the command line or ini file
    int iFreqkHz = rx->GetParameters()->GetFrequency();
    if (iFreqkHz != -1)
        rx->SetFrequency(iFreqkHz);

    // emit any initial state needed by UI and not otherwise set
    emit rx->InputChannelChanged(int(rx->GetInChanSel()));
    emit rx->OutputChannelChanged(int(rx->GetOutChanSel()));

    rx->InitReceiverMode();
    rx->SetInStartMode();

    ERecMode rxMode = rx->GetReceiverMode();
    switch(rxMode) {
    case RM_DRM: emit rx->drmModeStarted(); break;
    case RM_AM: emit rx->amModeStarted(); break;
    case RM_FM: emit rx->fmModeStarted(); break;
    case RM_NONE:;
    }

    do
    {
        eventLoop.processEvents();
        // qDebug("processed some events in the working thread");
        rx->updatePosition();
        rx->process();

    }
    while (!rx->ended);

    rx->CloseSoundInterfaces();

    qDebug("Receiver working thread complete");
}
