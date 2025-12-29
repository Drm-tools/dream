#ifndef SOUNDOUT_H
#define SOUNDOUT_H

#include "../sound/soundinterface.h"

/* Classes ********************************************************************/
class COpenSLESOut : public CSoundOutInterface
{
public:
    COpenSLESOut();
    virtual ~COpenSLESOut();

    virtual void		Enumerate(std::vector<string>&, std::vector<string>&);
    virtual void		SetItem(std::string sNewDevice);
    virtual std::string		GetItem();
    virtual int			GetSampleRate();

    virtual bool	Init(int iNewSampleRate, int iNewBufferSize, bool bNewBlocking);
    virtual bool 	Write(CVector<short>& psData);
    virtual void 		Close();

protected:
    std::string currentDevice;
};

#endif // SOUNDOUT_H
