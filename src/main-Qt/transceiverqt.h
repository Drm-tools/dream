#ifndef TRANSCEIVERQT_H
#define TRANSCEIVERQT_H

#include <QObject>
#include <QStringList>

class CTransceiverQt : public QObject
{
    Q_OBJECT
public:
    explicit CTransceiverQt(QObject *parent = nullptr);
    virtual ~CTransceiverQt() {}
    virtual bool IsReceiver() const { return true; } // will be overridden in transmitter
    virtual void EnumerateInputs(QStringList& names, QStringList& descriptions, QString& defaultInput)=0;
    virtual void EnumerateOutputs(QStringList& names, QStringList& descriptions, QString& defaultOutput)=0;

signals:
};

using CTRx = CTransceiverQt; // transitional

#endif // TRANSCEIVERQT_H
