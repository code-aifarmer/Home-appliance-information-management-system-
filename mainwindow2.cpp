#include "mainwindow2.h"
#include "ui_mainwindow2.h"
#include "mainwindow.h"
#include "mainwindow8.h"
#include "mainwindow9.h"
#include "choose_goods.h"
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
#include "mainwindow5.h"
#include "iostream"
using namespace std;
MainWindow2::MainWindow2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow2)
{
    ui->setupUi(this);
    QIcon icon("C:/Users/12234/Desktop/s.jpg");
    setWindowIcon(icon);
    setWindowTitle(QStringLiteral("家电信息管理系统"));


}

MainWindow2::~MainWindow2()
{
    delete ui;
}

void MainWindow2::on_pushButton_clicked()
{
    this->close();
}


void MainWindow2::on_pushButton_3_clicked()
{
    w2.show();
    this->hide();
}


void MainWindow2::on_pushButton_4_clicked()
{


    QStringList theStrList;
    QString fp=txt_path + "/01/sum_info/";
    fp=fp+now_username+"/fix_goods_info.txt";
    QFile f(fp);
   // QString reader = new QString[100];
    //for(int i=0;i<9999;i++)
    //{

    //}
    if(!f.open(QIODevice::ReadOnly | QIODevice::Text))
    {

        QMessageBox::about(NULL, "提示", "您有0条维修申请");
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
     (new MainWindow5())->show();
     this->hide();
}


void MainWindow2::on_pushButton_6_clicked()
{


    (new MainWindow())->show();
    this->hide();


}




void MainWindow2::on_pushButton_5_clicked()
{
    w5.show();
    this->hide();
}


void MainWindow2::on_pushButton_2_clicked()
{
   // w6.show();
    (new MainWindow9())->show();
    this->hide();
}


void MainWindow2::on_pushButton_7_clicked()
{
    (new Choose_goods())->show();
    this->hide();
}

