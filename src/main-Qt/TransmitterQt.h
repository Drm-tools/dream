#ifndef TRANSMITTERQT_H
#define TRANSMITTERQT_H

#include "transceiverqt.h"
#include "../DrmTransmitter.h"

class CTransmitterQt : public CTransceiverQt, public CDRMTransmitter
{
    Q_OBJECT
public:
    explicit CTransmitterQt();
    virtual ~CTransmitterQt() override {}
    virtual bool IsReceiver() const override { return false; }
    virtual void EnumerateInputs(QStringList& names, QStringList& descriptions, QString& defaultInput) override;
    virtual void EnumerateOutputs(QStringList& names, QStringList& descriptions, QString& defaultOutput) override;

public slots:
    virtual void LoadSettings() override;
    virtual void SaveSettings() override;
    virtual void SetInputDevice(std::string) override;
    virtual void SetOutputDevice(std::string) override;
    virtual void Restart();
    virtual void Stop();
    virtual void SetSettings(CSettings* pNewSettings) override;
    virtual void SetTextMessage(std::string);
    virtual void ClearTextMessage();
    virtual void SetPicFileName(std::string, std::string);
    virtual void SetPathRemoval(bool);
    virtual void ClearPicFileNames();
    virtual void SetHighQualityIQ(bool);
    virtual void SetOutputAmplified(bool);
    virtual void SetCarrierOffset(_REAL);
    virtual void SetIQOutput(int);
    virtual void SetFrequency(int);
private:
    ERunState eRunState;

};

using CTx = CTransmitterQt;

#endif // TRANSMITTERQT_H
