#ifndef SOUNDFACTORY_H
#define SOUNDFACTORY_H

#include "soundinterface.h"

template<typename T>
class CSoundFactory: public CSelectionInterface
{
public:
    CSoundFactory();
    ~CSoundFactory();
    void Enumerate(std::vector<std::string>& names, std::vector<std::string>& descriptions, std::string& defaultDevice) override;
    std::string GetItemName() override;
    void SetItem(std::string sNewDev) override;
    T* GetItem();
protected:
    std::string currentDevice;
    std::vector<T*> drivers;
    size_t currentDriver;
};

class CSoundFactoryIn: public CSoundFactory<
{
    CSoundFactoryIn();
}
class CSoundFactoryOut: public CSoundFactory<
{
    CSoundFactoryOut();
}
#endif // SOUNDFACTORY_H
