#ifndef CTRX_H
#define CTRX_H

#include "../DrmTransceiver.h"
#include <QObject>

class CTRx : public QObject, CDRMTransceiver
{
    Q_OBJECT
public:
    explicit CTRx(QObject *parent = nullptr);
    virtual int GetFrequency()=0;
    virtual void run() = 0;

signals:
    void InputDeviceChanged(const std::string&);
    void OutputDeviceChanged(const std::string&);
    void soundUpscaleRatioChanged(int);

public slots:
    virtual void SetFrequency(int)=0;
    virtual void SetSoundSignalUpscale(int) {}
};

#endif // CTRX_H
