#include "speech.h"

Speach::Speach(QObject *parent) : QObject(parent)
{

}
QString Speach::speechIdentify(QString fileName)
{
        //获取access_token
        QString tokenurl=QString(baidutokenurl).arg(client_id).arg(client_secret);
        QMap<QString ,QString>header;
        header.insert(QString("Content-Type"),QString("audio/pcm;rate=16000"));
        QByteArray requestData;//发送的内容
        QByteArray replyData;//服务器返回的内容
        Http m_http;
        bool result = m_http.post_sync(tokenurl,header,requestData,replyData);
        if(result)
        {
            QString key = "access_token";
                    accessToken  = getJsonvalue(replyData, key);  //获取到access_token（通过json数据格式解析）
                    //qDebug() << accessToken << endl;
        }
        else
        {
            return "";
        }
        QString baiduSpeech = QString(baiduSpeechurl).arg(QHostInfo::localHostName()).arg(accessToken);

        //把文件 转化为QByteArray
        QFile file;
        file.setFileName(fileName);
        file.open(QIODevice::ReadOnly);
        requestData =file.readAll();
        file.close();
        replyData.clear();

        //再次发起http请求
        result = m_http.post_sync(baiduSpeech, header, requestData, replyData);
        if (result)
        {
            QString key = "result" ;
            QString text = getJsonvalue (replyData, key) ;
            return text;
        }
        else
        {
            QMessageBox::warning(NULL,"识别提示","识别失败");

        }

        return "";

}
QString Speach::getJsonvalue(QByteArray ba, QString key)
{

    QJsonParseError parseError;
    QJsonDocument jsonDocument = QJsonDocument::fromJson(ba, &parseError);

    if(parseError.error == QJsonParseError::NoError)
    {
        if(jsonDocument.isObject())
        {
            //jsonDocument转换成json对象
            QJsonObject jsonObj = jsonDocument.object() ;
            if (jsonObj.contains (key))
            {
                QJsonValue jsonVal = jsonObj.value(key);
                if (jsonVal.isString())//字符串
                {
                    return jsonVal.toString();
                   }
                else if (jsonVal.isArray()) //数组
                {
                    QJsonArray arr = jsonVal.toArray(); //转换成JsonArray
                    QJsonValue jv = arr.at(0);          //获取第1个元素
                    return jv. toString();
                  }
               }
            }
        }
     return "";
}
