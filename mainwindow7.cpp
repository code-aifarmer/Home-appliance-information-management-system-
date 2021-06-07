#include "mainwindow7.h"
#include "ui_mainwindow7.h"
#include <QMessageBox>
#include<QMessageBox>
#include<QDebug>
#include<QMainWindow>
#include<QFile>
#include<QFileDialog>
#include<QDir>
#include<QTextStream>
#include <QPlainTextEdit>
#include <QTextStream>>
#include "mainwindow.h"
MainWindow7::MainWindow7(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow7)
{
    ui->setupUi(this);
}

MainWindow7::~MainWindow7()
{
    delete ui;
}

void MainWindow7::on_pushButton_clicked()
{
    QString filePath = "C:/Users/12234/Desktop/2.txt";
        QFile f(filePath);
        if(!f.open(QIODevice::WriteOnly | QIODevice::Text|QIODevice::Append))
        {
            return;
        }
        QTextStream txtOutput(&f);
        QString s1=ui->lineEdit->text();
        QString s2=ui->lineEdit_2->text();
        QString s3=ui->lineEdit_3->text();
        QString s4=ui->lineEdit_4->text();
        QString s5=ui->lineEdit_5->text();
        txtOutput <<s1<<s2<<s3<<s4<<s5;
        f.close();
        QMessageBox::about(NULL, "提示", "注册成功！");
        (new MainWindow())->show();
        this->hide();


}//注册提交


void MainWindow7::on_comboBox_currentIndexChanged()
{
    if(ui->comboBox->currentIndex()==0)
    {
         ui->lineEdit_2->setText("男");
    }
    if(ui->comboBox->currentIndex()==1)
    {
        ui->lineEdit_2->setText("女");
    }
}

