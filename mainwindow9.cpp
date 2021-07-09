#include "mainwindow9.h"
#include "ui_mainwindow9.h"
#include "mainwindow2.h"
#include "QMessageBox"
#include "mainwindow.h"
#include "QMessageBox"
#include <QButtonGroup>
#include <QDebug>
#include<QFile>
#include<QFileDialog>
#include<QDir>
#include <QPlainTextEdit>
#include <QTextStream>
#include <iostream>
#include "ui_mainwindow.h"
#include "mainwindow.h"
using namespace std;
MainWindow9::MainWindow9(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow9)
{
    ui->setupUi(this);
    QIcon icon("C:/Users/12234/Desktop/s.jpg");
    setWindowIcon(icon);
    setWindowTitle(QStringLiteral("家电信息管理系统"));
    p1 = new MainWindow(this);
}

MainWindow9::~MainWindow9()
{
    delete ui;
}

void MainWindow9::on_pushButton_clicked()
{
    (new MainWindow2())->show();
    this->hide();
}


void MainWindow9::on_pushButton_2_clicked()
{
    QString a1=ui->lineEdit->text();
    QString a2=ui->lineEdit_2->text();
    QString a3=ui->lineEdit_3->text();
    if(a1.isEmpty()||a2.isEmpty()||a3.isEmpty())
    {
        QMessageBox::about(NULL,"提示","请填入完整的信息！");
        return;
    }
    QString filePath = txt_path + "/01/sum_info/";
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
        (new MainWindow2())->show();
        this->hide();

    //qDebug()<<now_username;

}

