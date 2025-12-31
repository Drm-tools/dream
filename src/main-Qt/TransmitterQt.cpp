#include "TransmitterQt.h"
#include <string>
#include <vector>


using namespace std;

CTransmitterQt::CTransmitterQt() : eRunState(STOPPED) {}

void CTransmitterQt::CTransmitterQt::Restart() { eRunState = RESTART; }

void CTransmitterQt::CTransmitterQt::Stop() { eRunState = STOP_REQUESTED; }

void CTransmitterQt::EnumerateInputs(QStringList &names,
                                     QStringList &descriptions,
                                     QString &defaultInput) {
  names = QStringList();
  descriptions = QStringList();
  defaultInput = "";
  vector<string> n, d;
  string def;
  CDRMTransceiver::EnumerateInputs(n, d, def);

  for (size_t i = 0; i < n.size(); i++) {
    names.append(QString::fromStdString(n[i]));
    descriptions.append(QString::fromStdString(d[i]));
  }
  defaultInput = QString::fromStdString(def);
}

void CTransmitterQt::EnumerateOutputs(QStringList &names,
                                      QStringList &descriptions,
                                      QString &defaultOutput) {
  names = QStringList();
  descriptions = QStringList();
  defaultOutput = "";
  vector<string> n, d;
  string def;
  CDRMTransceiver::EnumerateInputs(n, d, def);

  for (size_t i = 0; i < n.size(); i++) {
    names.append(QString::fromStdString(n[i]));
    descriptions.append(QString::fromStdString(d[i]));
  }
  defaultOutput = QString::fromStdString(def);
}

void CTransmitterQt::LoadSettings() { CDRMTransmitter::LoadSettings(); }
void CTransmitterQt::SaveSettings() { CDRMTransmitter::SaveSettings(); }
void CTransmitterQt::SetInputDevice(QString input) {
  CDRMTransmitter::SetInputDevice(input.toStdString());
}
void CTransmitterQt::SetOutputDevice(QString output) {
  CDRMTransmitter::SetOutputDevice(output.toStdString());
}
void CTransmitterQt::SetSettings(CSettings *pNewSettings) {
  CDRMTransmitter::SetSettings(pNewSettings);
}
void CTransmitterQt::SetTextMessage(QString text) {
  CDRMTransmitter::SetTextMessage(text.toStdString());
}
void CTransmitterQt::ClearTextMessage() { CDRMTransmitter::ClearTextMessage(); }
void CTransmitterQt::SetPicFileName(QString picFileName, QString caption) {
  CDRMTransmitter::SetPicFileName(picFileName.toStdString(),
                                  caption.toStdString());
}
void CTransmitterQt::SetPathRemoval(bool bPathRemoval) {
  CDRMTransmitter::SetPathRemoval(bPathRemoval);
}
void CTransmitterQt::ClearPicFileNames() {
  CDRMTransmitter::ClearPicFileNames();
}

void CTransmitterQt::SetHighQualityIQ(bool bHighQualityIQ) {
  CDRMTransmitter::SetHighQualityIQ(bHighQualityIQ);
}
void CTransmitterQt::SetOutputAmplified(bool bOutputAmplified) {
  CDRMTransmitter::SetOutputAmplified(bOutputAmplified);
}
void CTransmitterQt::SetCarrierOffset(_REAL dCarrierOffset) {
  CDRMTransmitter::SetCarrierOffset(dCarrierOffset);
}
void CTransmitterQt::SetIQOutput(int iIQOutput) {
  CDRMTransmitter::SetIQOutput(iIQOutput);
}
void CTransmitterQt::SetFrequency(int iFrequency) {
  CDRMTransmitter::SetFrequency(iFrequency);
}
