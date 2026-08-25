#include "ctrx.h"
/*#include "../GlobalDefinitions.h"*/

CTRx::CTRx(QThread *parent) : QThread(parent)
{

}

CTRx::~CTRx()
{
    if (this->isRunning()) {
        this->quit(); // Signal event loop to stop
        this->wait(); // Wait blocks until thread completes execution
    }
}

