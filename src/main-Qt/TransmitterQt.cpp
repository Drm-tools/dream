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

void CTransmitterQt::EnumerateInputs(std::vector<std::string> &names,
                                  std::vector<std::string> &descriptions,
                                  std::string &defaultInput) {}
void CTransmitterQt::EnumerateOutputs(std::vector<std::string> &names,
                                   std::vector<std::string> &descriptions,
                                   std::string &defaultOutput) {}