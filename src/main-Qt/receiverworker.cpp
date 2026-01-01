#include "receiverworker.h"
#include "qeventloop.h"

CReceiverWorker::CReceiverWorker(CReceiverQt* nrx, QObject *parent): QThread{parent}, rx(nrx)
{}

void CReceiverWorker::run() {
    QEventLoop eventLoop;
    ERunState eRunState;

    qDebug("Working thread started");
        // set the frequency from the command line or ini file
        int iFreqkHz = rx->GetParameters()->GetFrequency();
        if (iFreqkHz != -1)
            rx->SetFrequency(iFreqkHz);

    // emit any initial state needed by UI and not otherwise set
        emit rx->InputChannelChanged(int(rx->GetInChanSel()));
        emit rx->OutputChannelChanged(int(rx->GetOutChanSel()));

        do
        {
            rx->InitReceiverMode();
            rx->SetInStartMode();

            ERecMode rxMode = rx->GetReceiverMode();
            switch(rx->GetReceiverMode()) {
            case RM_DRM: emit rx->drmModeStarted(); break;
            case RM_AM: emit rx->amModeStarted(); break;
            case RM_FM: emit rx->fmModeStarted(); break;
            case RM_NONE:;
            }

            /* Set run flag so that the thread can work */
            eRunState = RUNNING;
            do
            {
                rx->updatePosition();
                rx->process();
                if (rx->GetNewReceiverMode() != rxMode && rx->GetNewReceiverMode() != RM_NONE)
                    eRunState = RESTART;


            }
            while (eRunState == RUNNING && !isInterruptionRequested());

            /* Restore some parameter previously set by SetInput() */
        }
        while (eRunState == RESTART);

        rx->CloseSoundInterfaces();

    qDebug("Receiver working thread complete");
}
