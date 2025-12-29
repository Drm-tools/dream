#ifndef CTRX_H
#define CTRX_H

#include <QThread>
#include "../DrmTransceiver.h"

class CTRx : public QObject, public CDRMTransceiver
{
    Q_OBJECT
public:
    explicit CTRx();
    virtual int GetFrequency()=0;

signals:
    void InputDeviceChanged(const std::string&);
    void OutputDeviceChanged(const std::string&);
    void soundUpscaleRatioChanged(int);

public slots:
    virtual void SetFrequency(int)=0;
    virtual void SetSoundSignalUpscale(int) {}
};

#endif // CTRX_H
