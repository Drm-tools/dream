#ifndef DRM_SOAPYSDR_H
#define DRM_SOAPYSDR_H

#include "soundinterface.h"
#include "selectioninterface.h"
#include "../tuner.h"

namespace SoapySDR {class Device; class Stream;};

class CSoapySDRIn : public CSoundInInterface, public CTuner
{
public:

    CSoapySDRIn();
    virtual ~CSoapySDRIn();
    // CSoundInInterface methods
    virtual bool Init(int iSampleRate, int iNewBufferSize, bool bNewBlocking);
    virtual bool Read(CVector<short>& psData, CParameter &Parameters);
    virtual void Close();
    virtual std::string	GetVersion();

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
