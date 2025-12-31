#include "ReceiverQt.h"
using namespace std;

CReceiverQt::CReceiverQt() : CTransceiverQt() {}

CReceiverQt::~CReceiverQt() {}

void CReceiverQt::EnumerateInputs(QStringList& names, QStringList& descriptions, QString& defaultInput)
{
    names.removeAll();
    descriptions.removeAll();
    defaultInput = "";
    vector<string> n, d;
    string def;
    CDRMTransceiver::EnumerateInputs(n, d, def);

    for(size_t i=0; i<n.size(); i++)
    {
        names.append(QString::fromStdString(n[i]));
        descriptions.append(QString::fromStdString(d[i]));
    }
    defaultInput = QString::fromStdString(def);
}

void CReceiverQt::EnumerateOutputs(QStringList& names, QStringList& descriptions, QString& defaultOutput)
{
    names.removeAll();
    descriptions.removeAll();
    defaultOutput = "";
    vector<string> n, d;
    string def;
    CDRMTransceiver::EnumerateInputs(n, d, def);

    for(size_t i=0; i<n.size(); i++)
    {
        names.append(QString::fromStdString(n[i]));
        descriptions.append(QString::fromStdString(d[i]));
    }
    defaultOutput = QString::fromStdString(def);
}

void CReceiverQt::LoadSettings() {
  CDRMReceiver::LoadSettings();
  QString s = QString::fromStdString(GetInputDevice());
  emit InputDeviceChanged(s);
  emit soundFileChanged(s); // TODO only send if it is a file!!!
  s = QString::fromStdString(GetOutputDevice());
  emit OutputDeviceChanged(s);
  emit inputSampleRateChanged(GetParameters()->GetSigSampleRate());
  emit outputSampleRateChanged(GetParameters()->GetAudSampleRate());
  emit soundUpscaleRatioChanged(GetParameters()->GetSigUpscaleRatio());
}

void CReceiverQt::SaveSettings() { CDRMReceiver::SaveSettings(); }

void CReceiverQt::SetInputDevice(QString s) {
  CDRMReceiver::SetInputDevice(s.toStdString());
}

void CReceiverQt::SetInputDevice(string s) {
  CDRMReceiver::SetInputDevice(s);
  QString id = QString::fromStdString(GetInputDevice());
  emit InputDeviceChanged(id);
  emit soundFileChanged(id); // TODO only send if it is a file!!!
}

void CReceiverQt::SetOutputDevice(QString s) {
  CDRMReceiver::SetOutputDevice(s.toStdString());
}

void CReceiverQt::SetOutputDevice(string s) {
  cerr << "CReceiverQt::SetOutputDevice " << s << endl;
  CDRMReceiver::SetOutputDevice(s);
  emit OutputDeviceChanged(QString::fromStdString(GetOutputDevice()));
}

void CReceiverQt::Start() {}

void CReceiverQt::Restart() { Start(); }

void CReceiverQt::Stop() {}

void CReceiverQt::StartWriteWaveFile(string s) {
  WriteData.StartWriteWaveFile(s);
}

void CReceiverQt::StopWriteWaveFile() { WriteData.StopWriteWaveFile(); }

void CReceiverQt::SetTimeInterpolationAlgorithm(ETypeIntTime e) {
  SetTimeInt(e);
}

void CReceiverQt::SetFrequencyInterpolationAlgorithm(ETypeIntFreq e) {
  SetFreqInt(e);
}

void CReceiverQt::SetTimeSyncTrackingType(ETypeTiSyncTrac e) {
  SetTiSyncTracType(e);
}

void CReceiverQt::SetNumMSCMLCIterations(int n) {
  MSCMLCDecoder.SetNumIterations(n);
}

void CReceiverQt::SetFlipSpectrum(bool b) { ReceiveData.SetFlippedSpectrum(b); }

void CReceiverQt::SetFrequencySyncAcquisitionFilter(bool b) {
  FreqSyncAcq.SetRecFilter(b);
}

void CReceiverQt::SetConsiderInterferer(bool b) { SetIntCons(b); }

void CReceiverQt::MuteAudio(bool b) { WriteData.MuteAudio(b); }

void CReceiverQt::SetReverberationEffect(bool b) {
  return AudioSourceDecoder.SetReverbEffect(b);
}

void CReceiverQt::SetReceiverMode(ERecMode e) {
  CDRMReceiver::SetReceiverMode(e);
}

void CReceiverQt::SetAMDemodulationType(EDemodType e) {
  AMDemodulation.SetDemodType(e);
}

void CReceiverQt::SetAMFilterBW(int n) { AMDemodulation.SetFilterBW(n); }

void CReceiverQt::SetAMAGCType(EAmAgcType e) { AMDemodulation.SetAGCType(e); }

void CReceiverQt::SetAMNoiseReductionType(ENoiRedType e) {
  AMDemodulation.SetNoiRedType(e);
}

void CReceiverQt::SetAMNoiseReductionLevel(int n) {
  AMDemodulation.SetNoiRedLevel(n);
}

void CReceiverQt::SetFrequency(int n) { CDRMReceiver::SetFrequency(n); }

void CReceiverQt::SetAMDemodAcq(_REAL r) { CDRMReceiver::SetAMDemodAcq(r); }

void CReceiverQt::EnableAMPLL(bool b) { AMDemodulation.EnablePLL(b); }

void CReceiverQt::EnableAutoFrequenctAcquisition(bool b) {
  AMDemodulation.EnableAutoFreqAcq(b);
}

void CReceiverQt::onSoundInChannelChanged(int e) {
  ReceiveData.SetInChanSel(EInChanSel(e));
  emit InputChannelChanged(e);
}

void CReceiverQt::onSoundOutChannelChanged(EOutChanSel e) {
  WriteData.SetOutChanSel(e);
  emit OutputChannelChanged(int(e));
}

void CReceiverQt::onSoundSampleRateChanged(int n) {
  GetParameters()->SetNewAudSampleRate(n);
  Restart();
  emit outputSampleRateChanged(n);
}

void CReceiverQt::SetSoundSignalUpscale(int n) {
  GetParameters()->SetNewSigUpscaleRatio(n);
  Restart();
  emit soundUpscaleRatioChanged(n);
}
