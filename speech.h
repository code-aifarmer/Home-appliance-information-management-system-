#ifndef SPEECH_H
#define SPEECH_H
#include "http.h"
#include <QObject>
#include <QFile>
#include <QMessageBox>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QHostInfo>
#include <QIODevice>
//获取access_token相关
const QString baidutokenurl="http://aip.baidubce.com/oauth/2.0/token?grant_type=client_credentials&client_id=%1&client_secret=%2&";
const QString client_id="XeOI2tr0mtX2UqMbGubCMwGm";
const QString client_secret="ZzcSWeh2hBUQbakncQcsiMpMVMOnddK5";

const QString baiduSpeechurl = "http://vop.baidu.com/server_api?dev_pid=1537&cuid=%1&token=%2"; //普通话测试
class Speach : public QObject
{
    Q_OBJECT
public:
    explicit Speach(QObject *parent = nullptr);
    QString speechIdentify(QString fileName);
    QString getJsonvalue(QByteArray ba,QString key);

signals:
private:
      QString  accessToken;
};

#endif // SPEECH_H
