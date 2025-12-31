#include "TransmitterQt.h"

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

