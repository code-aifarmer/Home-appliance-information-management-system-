#pragma execution_character_set("utf-8")
#include "widget.h"
#include "ui_widget.h"
#include <ctime>
#include<QTime>

QString getRandomString(int length)
{
    qsrand(QDateTime::currentMSecsSinceEpoch());//为随机值设定一个seed

    const char chrs[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    int chrs_size = sizeof(chrs);

    char* ch = new char[length + 1];
    memset(ch, 0, length + 1);
    int randomx = 0;
    for (int i = 0; i < length; ++i)
    {
        randomx= rand() % (chrs_size - 1);
        ch[i] = chrs[randomx];
    }

    QString ret(ch);
    delete[] ch;
    return ret;
}
void get_email()
{

}
Widget::Widget(QWidget *parent): QWidget(parent), ui(new Ui::Widget),
    senderMail("1223419806@qq.com"), authCode("wavqnexaaypbjici"), receiveMail(rmail),
    expectedReply(""), nextAction(&Widget::checkConnectState)
{
   // qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    //int n=qrand()%100000;
    //ui->setupUi(this);

    //设置邮件的标题和正文
    this->title = "家电信息管理系统修改密码";
    yanzheng=getRandomString(5);
    this->content = "验证码为"+yanzheng;
    //qDebug()<<n<<" 00000000000000000000";
    //tcpSocket初始化
    this->tcpSocket = new QTcpSocket(this);
    tcpSocket->connectToHost("smtp.qq.com", 25);
    connect(tcpSocket, &QTcpSocket::readyRead,this, &Widget::readyReadSlot);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::readyReadSlot()
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
void Widget::checkConnectState()
{
    if(tcpSocket->state() == QAbstractSocket::ConnectedState){
        sendHelo();
    }
    else{
        QMessageBox::warning(this, "提示", "连接失败！");
    }
}

//发送helo
void Widget::sendHelo()
{
    QString str = "helo sis\r\n";
    qDebug()<<"向服务器发送：　" + str;
    tcpSocket->write(str.toLatin1());
    this->expectedReply = "250 OK\r\n";
    this->nextAction = &Widget::sendAuthLogin;
}

//发送auth login
void Widget::sendAuthLogin()
{
    QString str = "auth login\r\n";
    qDebug()<<"向服务器发送：　" + str;
    tcpSocket->write(str.toLatin1());
    this->expectedReply = "334 VXNlcm5hbWU6\r\n";
    this->nextAction = &Widget::sendUser;
}

//发送用户名
void Widget::sendUser()
{
    QString str = QString("\r\n").prepend(senderMail.toLatin1().toBase64());
    qDebug()<<"向服务器发送：　" + str;
    tcpSocket->write(str.toLatin1());
    this->expectedReply = "334 UGFzc3dvcmQ6\r\n";
    this->nextAction = &Widget::sendPassword;
}

//发送密码
void Widget::sendPassword()
{
    QString str = QString("\r\n").prepend(authCode.toLatin1().toBase64());
    qDebug()<<"向服务器发送：　" + str;
    tcpSocket->write(str.toLatin1());
    qDebug()<<"!!!!"<<str;
    this->expectedReply = "235 Authentication successful\r\n";
    this->nextAction = &Widget::sendMailFrom;
}

//发送mail from
void Widget::sendMailFrom()
{
    QString str = QString("MAIL FROM: <%1>\r\n").arg(senderMail);
    qDebug()<<"向服务器发送：　" + str;
    tcpSocket->write(str.toLatin1());
    this->expectedReply = "250 OK.\r\n";
    this->nextAction = &Widget::sendRcptTo;
}

//发送rcpt to
void Widget::sendRcptTo()
{
    QString str = QString("RCPT TO: <%1>\r\n").arg(receiveMail);
    qDebug()<<"向服务器发送：　" + str;
    tcpSocket->write(str.toLatin1());
    this->expectedReply = "250 OK\r\n";
    this->nextAction = &Widget::sendData;
}

//发送data
void Widget::sendData()
{
    QString str = "data\r\n";
    qDebug()<<"向服务器发送：　" + str;
    tcpSocket->write(str.toLatin1());
    this->expectedReply = "354 End data with <CR><LF>.<CR><LF>.\r\n";
    this->nextAction = &Widget::sendContent;
}

//发送邮件内容
void Widget::sendContent()
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
    this->expectedReply = "250 OK: queued as";
    this->nextAction = &Widget::afterSendSuccess;
}

//发送成功后续操作
void Widget::afterSendSuccess()
{
    QMessageBox::information(this, "提示", "邮件发送成功!请及时查看");
}

void Widget::on_pushButton_clicked()
{

}

