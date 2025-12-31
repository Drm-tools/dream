#ifndef RECEIVERQT_H
#define RECEIVERQT_H

#include <QObject>
#include "../DrmReceiver.h"
#include "transceiverqt.h"

class CReceiverQt : public CTransceiverQt, public CDRMReceiver
{
    Q_OBJECT
public:
    explicit CReceiverQt();
    virtual ~CReceiverQt() override;
    virtual void EnumerateInputs(std::vector<std::string>& names, std::vector<std::string>& descriptions, std::string& defaultInput) override;
    virtual void EnumerateOutputs(std::vector<std::string>& names, std::vector<std::string>& descriptions, std::string& defaultOutput) override;

public slots:
    virtual void LoadSettings() override;
    virtual void SaveSettings() override;
    virtual void SetInputDevice(std::string) override;
    virtual void SetOutputDevice(std::string) override;
    virtual void SetInputDevice(QString);
    virtual void SetOutputDevice(QString);
    virtual void Start();
    virtual void Stop();
    virtual void Restart();
    virtual void SetSettings(CSettings* pNewSettings) override;
    virtual void StartWriteWaveFile(std::string);
    virtual void StopWriteWaveFile();
    virtual void SetTimeInterpolationAlgorithm(ETypeIntTime);
    virtual void SetFrequencyInterpolationAlgorithm(ETypeIntFreq);
    virtual void SetTimeSyncTrackingType(ETypeTiSyncTrac);
    virtual void SetNumMSCMLCIterations(int);
    virtual void SetFlipSpectrum(bool);
    virtual void SetFrequencySyncAcquisitionFilter(bool);
    virtual void SetConsiderInterferer(bool);
    virtual void MuteAudio(bool);
    virtual void SetReverberationEffect(bool);
    virtual void SetReceiverMode(ERecMode);
    virtual void SetAMDemodulationType(EDemodType);
    virtual void SetAMFilterBW(int);
    virtual void SetAMAGCType(EAmAgcType);
    virtual void SetAMNoiseReductionType(ENoiRedType);
    virtual void SetAMNoiseReductionLevel(int);
    virtual void SetFrequency(int);
    virtual void SetAMDemodAcq(_REAL);
    virtual void EnableAMPLL(bool);
    virtual void EnableAutoFrequenctAcquisition(bool);
    virtual void onSoundInChannelChanged(int);
    virtual void onSoundOutChannelChanged(EOutChanSel);
    virtual void onSoundSampleRateChanged(int);
    virtual void SetSoundSignalUpscale(int);

signals:
    void inputSampleRateChanged(int);
    void outputSampleRateChanged(int);
    void soundUpscaleRatioChanged(int);
    void soundFileChanged(QString);
    void InputDeviceChanged(QString);
    void OutputDeviceChanged(QString);
    void AMBWParametersChanged(double rCenterFreq, double rBW);
    void AMNoiseReductionLevelChanged(int);
    void AMNoiseReductionTypeChanged(ENoiRedType);
    void AMDemodulationTypeChanged(EDemodType);
    void AMAGCTypeChanged(EAmAgcType);
    void AMFilterBWChanged(int);
    void AMMixerFrequencyOffsetChanged(double);
    void AMPLLPhaseChanged(_REAL);
    void ReceiverModeChanged(ERecMode);
    void InputChannelChanged(int);
    void OutputChannelChanged(int);
    void MSCMLInitNumIterationsChanged(int);
    void isInputRSCIChanged(bool);
    void isWriteWaveFileChanged(bool);
    void isAudioMutedChanged(bool);
    void isIntefererConsiderationEnabledChanged(bool);
    void isFrequencySyncAcquisitionFilterEnabledChanged(bool);
    void isSpectrumFlippedChanged(bool);
    void isAMAutoFrequencyAcquisitionEnabledChanged(bool);
    void isAMPLLEnabledChanged(bool);
    void AMSSPLLPhaseChanged(_REAL);
    void AMSSPercentageDataEntityGroupCompleteChanged(int);
    void AMSSDataEntityGroupStatusChanged(QString);
    void AMSSCurrentBlockChanged(int);
    void AMSSCurrentBlockBitsChanged(QString);
    void AMSSBlock1StatusChanged(bool);
    void AMSSLockStatusChanged(EAMSSBlockLockStat);
    void canDecodeChanged(bool);
    void TimeInterpolationAlgorithmChanged(ETypeIntTime);
    void FrequencyInterpolationAlgorithmChanged(ETypeIntFreq);
    void TimeSyncTrackingTypeChanged(ETypeTiSyncTrac);
    void ReverbEffectChanged(bool);
    void AcquisitionStateChanged(EAcqStat);
    void FrequencyChanged(int);
    void drmModeStarted();
    void amModeStarted();
    void fmModeStarted();
};

using CRx = CReceiverQt; // transitional

#endif // RECEIVERQT_H
