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
#include "mainwindow.h"
#include "QDir"
#include "mainwindow15.h"
#include "widget.h"
MainWindow7::MainWindow7(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow7)
{
    ui->setupUi(this);
    QIcon icon("C:/Users/12234/Desktop/s.jpg");
    setWindowIcon(icon);
    setWindowTitle(QStringLiteral("家电信息管理系统"));
}

MainWindow7::~MainWindow7()
{
    delete ui;
}

void MainWindow7::on_pushButton_clicked()
{

    QString input1 = ui->lineEdit->text();
    QString input2 = ui->lineEdit_2->text();
    QString input3 = ui->lineEdit_3->text();
    QString input4 = ui->lineEdit_4->text();
    QString input5 = ui->lineEdit_5->text();
    QString input6 = ui->lineEdit_6->text();
    if(input1.isEmpty()||input2.isEmpty()||input3.isEmpty()||input4.isEmpty()||input5.isEmpty()||input6.isEmpty())
    {
        QMessageBox::about(NULL,"提示","请补全信息！");
        return;
    }
  /*  QRegExp rx("(\\w[A-z0-9]*|[@_.]*)@(qq|QQ)\\.(com|COM)");
    QRegExpValidator v(rx,0);
    int pos = 0;
    //if (v->validate(ui->lineEdit_3->text(), pos) != QValidator::Acceptable)
    if(v.validate(input3,pos)!=QValidator::Acceptable);
    {
        QMessageBox::about(NULL,"提示","请输入正确的qq邮箱！");
        return;
    }
*/
    QDir dir;
    QString fp="C:/Users/12234/Documents/01/sum_info";
    dir.cd(fp);
    if(!dir.exists(ui->lineEdit_4->text()))
    {
        dir.mkdir(ui->lineEdit_4->text());//创建以账号为名字的文件夹用于储存每个用户的信息
    }
    else
    {
        QMessageBox::about(NULL,"提示","该用户已存在");
                return;
    }

    if(ui->lineEdit_6->text() != yanzheng)
    {
        QMessageBox::about(NULL,"提示","验证码有误");
        return;
    }
    QString filePath = "C:/Users/12234/Documents/01/sum_info/";
    filePath=filePath+ui->lineEdit_4->text()+"/acount_info.txt";
        QFile f(filePath);
        if(!f.open(QIODevice::WriteOnly | QIODevice::Text|QIODevice::Append))
        {
         QMessageBox::about(NULL, "提示", "文件异常");
            return;
        }
        QTextStream txtOutput(&f);
        QString s1=ui->lineEdit->text();
        QString s2=ui->lineEdit_2->text();
        QString s3=ui->lineEdit_3->text();
        QString s4=ui->lineEdit_4->text();
        QString s5=ui->lineEdit_5->text();
        txtOutput <<s1<<s2<<s3<<"%"<<s4<<"#"<<s5<<"%";
        f.close();
        QMessageBox::about(NULL, "提示", "注册成功！");
        yanzheng ="";
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


void MainWindow7::on_pushButton_2_clicked()
{
    (new MainWindow())->show();
    this->hide();
}


void MainWindow7::on_pushButton_3_clicked()
{

    rmail=ui->lineEdit_3->text();
    Widget *s=new Widget();
}

