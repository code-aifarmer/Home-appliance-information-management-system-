#pragma execution_character_set("utf-8")
#include "widget1.h"
#include <QAbstractSocket>
#include <QMessageBox>
#include <QTcpSocket>
Widget1::Widget1(QWidget *parent): QWidget1(parent)),
    senderMail("这里填写发送方邮箱地址"), authCode("这里填写发送方邮箱授权码"), receiveMail("这里填写接收方邮箱地址"),
    expectedReply("220 163.com Anti-spam GT for Coremail System"), nextAction(&Widget::checkConnectState)
{
    ui->setupUi(this);

    //设置邮件的标题和正文
    this->title = "这是邮件标题";
    this->content = "这句话是邮件的正文";

    //tcpSocket初始化
    this->tcpSocket = new QTcpSocket(this);
    tcpSocket->connectToHost("smtp.163.com", 25);
    connect(tcpSocket, &QTcpSocket::readyRead,this, &Widget1::readyReadSlot);
}
void Widget1::readyReadSlot()
{
    QByteArray buffer = tcpSocket->readAll();
    qDebug()<<"收到服务器回复："<<buffer;

    if(buffer.contains(this->expectedReply.toLatin1())){
        if(nextAction) (this->*nextAction)();
    }
    else{
        QMessageBox::warning(this, "提示", "邮件发送失败!");
    }
}

//检查连接状态
void Widget1::checkConnectState()
{
    if(tcpSocket->state() == QAbstractSocket::ConnectedState){
        sendHelo();
    }
    else{
        QMessageBox::warning(this, "提示", "连接失败！");
    }
}

//发送helo
void Widget1::sendHelo()
{
    QString str = "helo 163.com\r\n";
    qDebug()<<"向服务器发送：　" + str;
    tcpSocket->write(str.toLatin1());
    this->expectedReply = "250 OK\r\n";
    this->nextAction = &Widget1::sendAuthLogin;
}

//发送auth login
void Widget1::sendAuthLogin()
{
    QString str = "auth login\r\n";
    qDebug()<<"向服务器发送：　" + str;
    tcpSocket->write(str.toLatin1());
    this->expectedReply = "334 dXNlcm5hbWU6\r\n";
    this->nextAction = &Widget1::sendUser;
}

//发送用户名
void Widget1::sendUser()
{
    QString str = QString("\r\n").prepend(senderMail.toLatin1().toBase64());
    qDebug()<<"向服务器发送：　" + str;
    tcpSocket->write(str.toLatin1());
    this->expectedReply = "334 UGFzc3dvcmQ6\r\n";
    this->nextAction = &Widget1::sendPassword;
}

//发送密码
void Widget1::sendPassword()
{
    QString str = QString("\r\n").prepend(authCode.toLatin1().toBase64());
    qDebug()<<"向服务器发送：　" + str;
    tcpSocket->write(str.toLatin1());
    this->expectedReply = "235 Authentication successful\r\n";
    this->nextAction = &Widget::sendMailFrom;
}

//发送mail from
void Widget1::sendMailFrom()
{
    QString str = QString("mail from: <%1>\r\n").arg(senderMail);
    qDebug()<<"向服务器发送：　" + str;
    tcpSocket->write(str.toLatin1());
    this->expectedReply = "250 Mail OK\r\n";
    this->nextAction = &Widget1::sendRcptTo;
}

//发送rcpt to
void Widget1::sendRcptTo()
{
    QString str = QString("rcpt to: <%1>\r\n").arg(receiveMail);
    qDebug()<<"向服务器发送：　" + str;
    tcpSocket->write(str.toLatin1());
    this->expectedReply = "250 Mail OK\r\n";
    this->nextAction = &Widget1::sendData;
}

//发送data
void Widget1::sendData()
{
    QString str = "data\r\n";
    qDebug()<<"向服务器发送：　" + str;
    tcpSocket->write(str.toLatin1());
    this->expectedReply = "354 End data with <CR><LF>.<CR><LF>\r\n";
    this->nextAction = &Widget1::sendContent;
}

//发送邮件内容
void Widget1::sendContent()
{
    QString str = QString("from:%1\r\n"
                          "to:%2\r\n"
                          "subject:=?UTF-8?B?%3?=\r\n"
                          "\r\n"
                          "%4\r\n"
                          "\r\n"
                          ".\r\n").arg(senderMail).arg(receiveMail).arg( QString("").append(title.toUtf8().toBase64()) ).arg(content);
    qDebug()<<"向服务器发送：　" + str;
    tcpSocket->write(str.toUtf8());
    this->expectedReply = "250 Mail OK queued as";
    this->nextAction = &Widget1::afterSendSuccess;
}

//发送成功后续操作
void Widget1::afterSendSuccess()
{
    QMessageBox::information(this, "提示", "邮件发送成功!");
}
