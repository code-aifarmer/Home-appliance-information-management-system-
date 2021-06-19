#include "mainwindow8.h"
#include "ui_mainwindow8.h"
#include <QDesktopServices>
#include <QUrl>
#include  <QtNetwork>
#include  <QNetworkAccessManager>
#include "mainwindow2.h"
MainWindow8::MainWindow8(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow8)
{
    ui->setupUi(this);
}

MainWindow8::~MainWindow8()
{
    delete ui;
}

void MainWindow8::on_pushButton_clicked()
{
    ui->textEdit->textCursor().insertText("我："+ui->lineEdit->text()+"\n\n");
    QString Url="http://api.qingyunke.com/api.php?key=free&appid=0&msg="+ui->lineEdit->text();
    ui->lineEdit->clear();
       QUrl url;
       url.setUrl(Url);
       QNetworkRequest request(url);
       QNetworkAccessManager *manager=new QNetworkAccessManager(this);
       connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(Tuling_replyFinish(QNetworkReply*)));
       manager->get(request);

}
void MainWindow8::Tuling_replyFinish(QNetworkReply *reply)
{

    QString data=reply->readAll();
    QJsonParseError json_error;
    QJsonDocument json=QJsonDocument::fromJson(data.toUtf8(),&json_error);
    //判断有没有错
    if(json_error.error==QJsonParseError::NoError)
    {
        if(json.isObject())
        {
            QJsonObject jsonObj=json.object();
            if(jsonObj.contains("content"))
            {
                //qDebug()<<"成功获取text";
                QJsonValue text_value=jsonObj.take("content");
                if(text_value.isString())
                {
                    tuling_get_ans=text_value.toVariant().toString();
                    tuling_get_ans.replace("br","\n");
                    //qDebug()<<"!!!返回的ans:"<<tuling_get_ans;
                }
            }
        }
    }
    reply->deleteLater();
    ui->textEdit->textCursor().insertText("客服："+tuling_get_ans+"\n\n");
    //QString content = ui.contentTextEdit->append(message+"\n");
}


void MainWindow8::on_pushButton_2_clicked()
{
    (new MainWindow2())->show();
    this->hide();
}

