#include "returnGoods.h"
#include "ui_returnGoods.h"
#include "customerChannel.h"
#include "QMessageBox"
#include "login.h"
#include "QMessageBox"
#include <QButtonGroup>
#include <QDebug>
#include<QFile>
#include<QFileDialog>
#include<QDir>
#include <QPlainTextEdit>
#include <QTextStream>
#include <iostream>
#include "ui_login.h"
using namespace std;
ReturnGoods::ReturnGoods(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ReturnGoods)
{
    ui->setupUi(this);
    p1 = new Login(this);
}

ReturnGoods::~ReturnGoods()
{
    delete ui;
}

void ReturnGoods::on_pushButton_clicked()
{
    (new CustomerChannel())->show();
    this->hide();
}


void ReturnGoods::on_pushButton_2_clicked()
{
    QString a1=ui->lineEdit->text();
    QString a2=ui->lineEdit_2->text();
    QString a3=ui->lineEdit_3->text();
    QString filePath = FILEPATH;
    filePath+="sum_info/";
    filePath=filePath+now_username+"/return_goods_info.txt";
    qDebug()<<filePath;
        QFile f(filePath);
        if(!f.open(QIODevice::WriteOnly | QIODevice::Text|QIODevice::Append))
        {
         QMessageBox::about(NULL, "提示", "文件异常");
            return;
        }
        QTextStream txtOutput(&f);
        txtOutput <<a1<<","<<a2<<","<<a3<<"\n";
        f.close();
        QMessageBox::about(NULL, "提示", "您已成功提交申请！");

    //qDebug()<<now_username;

}

