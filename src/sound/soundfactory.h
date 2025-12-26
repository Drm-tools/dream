#ifndef SOUNDFACTORY_H
#define SOUNDFACTORY_H

#include "selectioninterface.h"
#include "soundinterface.h"

template<class T>
class CSoundFactory: public CSelectionInterface<T>
{
public:
    CSoundFactory();
    ~CSoundFactory();
    void Enumerate(std::vector<std::string>& names, std::vector<std::string>& descriptions, std::string& defaultDevice) override;
    std::string GetItemName() override;
    void SetItem(std::string sNewDev) override;
    T* GetItem() override;

    template <>
    CSoundFactory<CSoundInInterface>::CSoundFactory();
    template<>
    CSoundFactory<CSoundOutInterface>::CSoundFactory();
protected:
    std::string currentDevice;
    std::vector< CSelectionInterface<T> > drivers;
    size_t currentDriver;
};

#endif // SOUNDFACTORY_H
