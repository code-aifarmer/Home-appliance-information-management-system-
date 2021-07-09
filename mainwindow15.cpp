#include "mainwindow15.h"
#include "ui_mainwindow15.h"
#include "smtp.h"
#include "widget.h"
#include "QMessageBox"
#include "mainwindow.h"
#include<QFile>
#include<QFileDialog>
#include<QDir>
#include<QTextStream>
#include <QPlainTextEdit>
#include <QTextStream>>
MainWindow15::MainWindow15(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow15)
{
    ui->setupUi(this);
    QIcon icon("C:/Users/12234/Desktop/s.jpg");
    setWindowIcon(icon);
    setWindowTitle(QStringLiteral("家电信息管理系统"));
}

MainWindow15::~MainWindow15()
{
    delete ui;
}
//wavqnexaaypbjici  POP3/SMTP服务密码
//eouidnvznwawhehc  IMAP/SMTP服务密码
void MainWindow15::on_pushButton_2_clicked()
{
    /*
    Smtp *sendmail=new Smtp("smtp.qq.com","1223419806@qq.com","wavqnexaaypbjici");
    if(sendmail->Send("1223419806@qq.com","11","11"))
     {
          if(sendmail->PutSendLine())
     {
             qDebug() <<"发送成功.";
     }
          else
     {
             qDebug() << "发送失败.";
     }
     }
     */
    bool judge=0;
    QString now_user = ui->lineEdit->text();
    QString now_qmail = ui->lineEdit_2->text();
    QString input3 = ui->lineEdit_3->text();
    QString input4 = ui->lineEdit_4->text();
    if(now_user.isEmpty()||now_qmail.isEmpty()||input3.isEmpty()||input4.isEmpty())
    {
        QMessageBox::about(NULL,"提示","请输入完整的信息!");
        return;
    }
    QString folderpath=txt_path+"/01/sum_info";
    QDir dir(folderpath);
    if(!dir.exists())
    {
        return;
    }
    dir.setFilter(QDir::Dirs|QDir::Files);//除了目录和文件，其他的过滤掉
    dir.setSorting(QDir::DirsFirst);//优先显示目录
    QFileInfoList list1 = dir.entryInfoList();//获取文件信息列表
    int i=0;
    do
    {
        QFileInfo fileInfo = list1.at(i);
        qDebug()<<fileInfo.fileName();
        if(fileInfo.fileName().contains(now_user,Qt::CaseSensitive)==true)
        {
            //QMessageBox::about(NULL, "提示", "找到啦");
            QString fp=txt_path + "/01/sum_info/";
            fp=fp+fileInfo.fileName()+"/acount_info.txt";
            QFile f(fp);
            if(!f.open(QIODevice::ReadOnly | QIODevice::Text))
            {
                //qDebug()<<fp;
                QMessageBox::about(NULL, "提示", "文件异常");
                return;
            }
            int t=0;

            while (!f.atEnd())
            {
                 QStringList list;
                 QByteArray line = f.readLine();
                 //qDebug()<<line.toInt()<<"00000000000";
                // qDebug()<<t;
                 QString s(line);
                //qDebug()<<s<<"6666";
                 if(s.contains(now_qmail,Qt::CaseSensitive)==true)
                 {
                     judge=1;
                 }


                    t++;
            }




        }
        //qDebug()<<fileInfo.fileName()<<custom_user_name;
        i++;
    }
    while(i<list1.size());


if(judge == 1){
    rmail=ui->lineEdit_2->text();
    Widget *s=new Widget();
}
else
{
    QMessageBox::about(NULL,"提示","您输入的邮箱与注册邮箱不匹配");
}

}


void MainWindow15::on_pushButton_clicked()
{
    bool judge=0;
    QString input1 = ui->lineEdit->text();
    QString input2 = ui->lineEdit_2->text();
    QString input3 = ui->lineEdit_3->text();
    QString input4 = ui->lineEdit_4->text();
    QString input5 = ui->lineEdit_5->text();
    if(input1.isEmpty()||input2.isEmpty()||input3.isEmpty()||input4.isEmpty()||input5.isEmpty())
    {
        QMessageBox::about(NULL,"提示","请补全信息！");
        return;
    }
        if(ui->lineEdit_5->text()!=yanzheng)
        {
           QMessageBox::about(NULL,"提示","验证码有误,请重新获取验证码!");
           yanzheng="";
        }
        if(ui->lineEdit_3->text()!=ui->lineEdit_4->text())
        {
            QMessageBox::about(NULL,"提示","两次输入的密码不一致");
            judge=1;

        }
        if(ui->lineEdit_3->text()==ui->lineEdit_4->text())judge=0;
        if(ui->lineEdit_3->text()==ui->lineEdit_4->text()&&ui->lineEdit_5->text()==yanzheng&&judge==0)
        {
            QString filePath = txt_path + "/01/sum_info/";
            filePath=filePath+ui->lineEdit->text()+"/acount_info.txt";
            QFile f(filePath);
            if(!f.open(QIODevice::WriteOnly | QIODevice::ReadOnly|QIODevice::Text|QIODevice::Append))
            {
             QMessageBox::about(NULL, "提示", "文件异常");
                return;
            }
            QTextStream txtOutput(&f);

            QString info=f.readAll();

            QStringList strList;
            QString s1=ui->lineEdit->text();
            QString s2=ui->lineEdit_3->text();
            txtOutput <<"%"<<s1<<"#"<<s2<<"%";
            QMessageBox::about(NULL,"提示","密码修改成功！");
        }
}


void MainWindow15::on_pushButton_3_clicked()
{
    (new MainWindow())->show();
    this->hide();
}

