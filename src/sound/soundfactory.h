#ifndef SOUNDFACTORY_H
#define SOUNDFACTORY_H

#include "selectioninterface.h"

class CSoundFactory: public CSelectionInterface
{
public:
    CSoundFactory();
    ~CSoundFactory();
    void Enumerate(std::vector<std::string>& names, std::vector<std::string>& descriptions, std::string& defaultDevice) override;
    std::string GetDevName() override;
    void SetDev(std::string sNewDev) override;
    CSoundInInterface* GetInDev() override;
    CSoundOutInterface* GetOutDev() override;
protected:
    std::string currentDevice;
    std::vector<CSelectionInterface*> inDrivers;
    std::vector<CSelectionInterface*> outDrivers;
    size_t currentInDriver, currentOutDriver;
};

#endif // SOUNDFACTORY_H
