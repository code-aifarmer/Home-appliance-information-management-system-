#include "audio.h"

audio::audio(QObject *parent) : QObject(parent)
{

}
void audio::startAudio(QString fileName)
{
    QAudioDeviceInfo  device =QAudioDeviceInfo::defaultInputDevice();
    if(device.isNull())
    {
    QMessageBox::warning(NULL,"QAudioDeviceInfo","录音设备不存在");
    }
    else
    {



    QAudioFormat m_format;
    //设置采样频率
    m_format.setSampleRate(16000);
    //设置通道
    m_format.setChannelCount(1);
    //设置位深
    m_format.setSampleSize(16);
    //设置编码
    m_format.setCodec("audio/pcm");

    //判断设备是否支持该格式
    if(!device.isFormatSupported(m_format))
    {
        m_format=device.nearestFormat(m_format);
    }

    m_file = new QFile;
    m_file->setFileName(fileName);
    m_file->open(QIODevice::WriteOnly | QIODevice::Truncate);


    m_audio=new QAudioInput(m_format,this);
    m_audio->start(m_file);
    }

}
void audio::stopAudio()
{
    m_audio->stop();//停止录音
    m_file->close();//删除文件对象
    delete m_file;
    m_file=NULL;
}
audio::~audio()
{
    delete m_audio;
    delete m_file;
}
