#include "register.h"
#include "ui_register.h"
#include <QMessageBox>
#include<QMessageBox>
#include<QDebug>
#include<QMainWindow>
#include<QFile>
#include<QFileDialog>
#include<QDir>
#include<QTextStream>
#include <QPlainTextEdit>
#include "login.h"
#include "QDir"
Register::Register(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
}

Register::~Register()
{
    delete ui;
}

void Register::on_pushButton_clicked()
{
    QDir dir;
    QString fp=FILEPATH;
    fp+="sum_info";
    dir.cd(fp);
    QString password = ui->lineEdit_5->text(),
            account = ui->lineEdit_4->text(),
            phone = ui->lineEdit_3->text();

    if(!dir.exists(ui->lineEdit_4->text()))
    {
        dir.mkdir(ui->lineEdit_4->text());//创建以账号为名字的文件夹用于储存每个用户的信息
    }
    else
    {
        QMessageBox::about(NULL,"提示","该用户已存在");
                return;
    }
    QString filePath = FILEPATH;
    filePath+="sum_info/";
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
        (new Login())->show();
        this->hide();


}//注册提交


void Register::on_comboBox_currentIndexChanged()
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


void Register::on_pushButton_2_clicked()
{
    (new Login())->show();
    this->hide();
}

