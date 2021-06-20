#include "customerChannel.h"
#include "ui_customerChannel.h"
#include "login.h"
#include "customerService.h"
#include "returnGoods.h"
//MainWindow *main_window;
#include "QMessageBox"
#include <QDebug>
#include<QFile>
#include<QFileDialog>
#include<QDir>
#include<QTextStream>
#include <QPlainTextEdit>
#include <QTextStream>
#include <QDir>
#include "maintenanceInquiry.h"
#include "iostream"
using namespace std;
CustomerChannel::CustomerChannel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CustomerChannel)
{
    ui->setupUi(this);


}

CustomerChannel::~CustomerChannel()
{
    delete ui;
}

void CustomerChannel::on_pushButton_clicked()
{
    this->close();
}


void CustomerChannel::on_pushButton_3_clicked()
{
    w2.show();
    this->hide();
}


void CustomerChannel::on_pushButton_4_clicked()
{


    QStringList theStrList;
    QString fp=FILEPATH;
    fp=fp+"sum_info/"+now_username+"/fix_goods_info.txt";
    QFile f(fp);
   // QString reader = new QString[100];
    //for(int i=0;i<9999;i++)
    //{

    //}
    if(!f.open(QIODevice::ReadOnly | QIODevice::Text))
    {

        QMessageBox::about(NULL, "提示", "您没有维修申请");
        return;
    }
    qDebug()<<fp;
    //QByteArray line = f.readLine();
    int count=0;
    while (!f.atEnd())
    {

        QByteArray line = f.readLine();
        //QString s(line);
        //qDebug()<<now_username<<count;
        count++;
    }

     QMessageBox::about(NULL, "提示", "您有"+QString::number(count)+"条维修申请！");
     (new MaintenanceInquiry())->show();
     this->hide();
}


void CustomerChannel::on_pushButton_6_clicked()
{


    (new Login())->show();
    this->hide();


}




void CustomerChannel::on_pushButton_5_clicked()
{
    w5.show();
    this->hide();
}


void CustomerChannel::on_pushButton_2_clicked()
{
   // w6.show();
    (new ReturnGoods())->show();
    this->hide();
}

