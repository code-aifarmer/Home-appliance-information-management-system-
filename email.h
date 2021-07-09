#ifndef EMAIL_H
#define EMAIL_H

#include<QtCore>
#include<QObject>
#include<QCoreApplication>
#include <QTcpSocket>
#include <QString>
#include <QTextStream>
#include <QDebug>
#include <QAbstractSocket>
#include <QDateTime>
#include <QDate>
#include <QLocale>
#include <QObject>
#include <QTcpSocket>

class Email
{
public:
    Email();
    Email(QString smtphost,QString smtpusername,QString smtppass);
    bool Send( const QString &to,const QString &subject, const QString &body );
    int linesend;
    QStringList ErrorMSG;
    bool ReadLiner();
    void ErrorCloseAll();
signals:
    void status( const QString &);
    void SendLine();
public slots:
    bool PutSendLine();

private:
    bool isconnect;
       QString smtphost;
       QString smtpusername;
       QString smtppass;
       QString message;
       QString output;
       QString RemoteServerName;
       QString mailstatus;
       QTextStream *t;
       QTcpSocket *smtpsocket;
       QString from;
       QString rcpt;
       QString response;
       QString SendLineAndGrab(QString senddata);
       int Timeout;
       QString encodeBase64( QString xml );
       QString decodeBase64( QString xml );
       int dateswap(QString form, uint unixtime );
       QString TimeStampMail();

};


#endif // EMAIL_H
