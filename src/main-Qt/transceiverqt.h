#ifndef TRANSCEIVERQT_H
#define TRANSCEIVERQT_H

#include <QObject>

class CTransceiverQt : public QObject
{
    Q_OBJECT
public:
    explicit CTransceiverQt(QObject *parent = nullptr);
    virtual ~CTransceiverQt() {}
    virtual bool IsReceiver() const { return true; } // will be overridden in transmitter
    virtual void EnumerateInputs(std::vector<std::string>& names, std::vector<std::string>& descriptions, std::string& defaultInput);
    virtual void EnumerateOutputs(std::vector<std::string>& names, std::vector<std::string>& descriptions, std::string& defaultOutput);

signals:
};

using CTRx = CTransceiverQt; // transitional

#endif // TRANSCEIVERQT_H
