#ifndef AUDIO_H
#define AUDIO_H

#include <QObject>
#include <QAudioFormat>
#include <QAudioDeviceInfo>
#include "QMessageBox"
#include "QAudioInput"
#include <QFile>
class audio : public QObject
{
    Q_OBJECT
public:
    explicit audio(QObject *parent = nullptr);
    void startAudio(QString fileName);
    void stopAudio();
    ~audio();

signals:
private:
    QAudioInput *m_audio;
    QFile *m_file;
};

#endif // AUDIO_H
