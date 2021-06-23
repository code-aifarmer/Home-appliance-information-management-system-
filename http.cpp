#include "http.h"



Http::Http(QObject *parent) : QObject(parent)
{

}
bool Http::post_sync(QString Url, QMap<QString, QString> header, QByteArray requestData, QByteArray &replyData)
{
    QNetworkAccessManager manager;//发送请求的对象

    //请求 对象
    QNetworkRequest request;
    request.setUrl(Url);
    QMapIterator<QString,QString> it(header);
    while(it.hasNext())
    {
        it.next();
        request.setRawHeader(it.key().toLatin1(),it.value().toLatin1());
    }
   QNetworkReply*reply=manager.post(request,requestData);
   QEventLoop l;
   connect(reply,&QNetworkReply::finished,&l,&QEventLoop::quit);
   l.exec();
   if(reply!=nullptr&&reply->error()==QNetworkReply::NoError)
   {
       replyData=reply->readAll();//读取服务器返回的数据
       //qDebug()<<replyData;
        return true;
   }
   else
   {
        qDebug()<<"请求失败";
        return false;
   }
}
