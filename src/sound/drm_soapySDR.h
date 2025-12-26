#ifndef DRM_SOAPYSDR_H
#define DRM_SOAPYSDR_H

#include "soundinterface.h"
#include "selectioninterface.h"
#include "soundnull.h"
#include "../tuner.h"

namespace SoapySDR {class Device; class Stream;};

class CSoapySDRIn : public CSoundInInterface, public CTuner, public CSelectionInterface
{
public:

    CSoapySDRIn();
    virtual ~CSoapySDRIn();

    // CSoundInInterface methods
    virtual bool Init(int iSampleRate, int iNewBufferSize, bool bNewBlocking);
    virtual bool Read(CVector<short>& psData, CParameter &Parameters);
    virtual void Close();
    virtual std::string	GetVersion();

    // CSelectionInterface methods
    virtual void		Enumerate(std::vector<std::string>& names, std::vector<std::string>& descriptions, std::string& defaultDevice);
    virtual std::string	GetItemName();
    virtual void		SetItem(std::string sNewDev);
    virtual CSoundInInterface* GetInDev() { return this; }
    virtual CSoundOutInterface* GetOutDev() { return new CSoundOutNull(); }
    // CTuner methods
    virtual void SetFrequency(int);
    virtual void LoadSettings(CSettings&);
    virtual void SaveSettings(CSettings&);

protected:

    void ApplyConfigString();
    std::string currentDev;
    int				iSampleRate;
    int				iBufferSize;
    int             iFrequency;

    SoapySDR::Device *pDevice;
    SoapySDR::Stream *pStream;
    std::string strSDRConfig;

    FILE *pFile;
};

#endif // DRM_SOAPYSDR_H
