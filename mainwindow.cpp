#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include <QButtonGroup>
#include <QDebug>
#include<QFile>
#include<QFileDialog>
#include<QDir>
#include<QTextStream>
#include <QPlainTextEdit>
#include <QTextStream>>
#include <QDir>
#include <iostream>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //mainwindow = new MainWindow;
    //connect(mainwindow,SIGNAL(signal_ui_switch()),this,SLOT(slot_ui_switch()));
    // connect(this,SIGNAL(signal_Test()),mainwindow,SLOT(slot_slot_Test()));
    //connect(mainwindow,SIGNAL(signal_ipdisconnect()),this,SLOT(slot_ipdisconnect()));
    groupButton1=new QButtonGroup(this);
    groupButton1->addButton(ui->radioButton,0);
    //groupButton2=new QButtonGroup(this);
    groupButton1->addButton(ui->radioButton_2,1);
    groupButton1->setExclusive(true);
}
//QString MainWindow::now_username=ui->lineEdit->text();
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    w4.show();
    this->hide();
}


void MainWindow::on_label_linkActivated(const QString &link)
{

}


void MainWindow::on_pushButton_2_clicked()
{
   // ui->pushButton_2->setIcon(QIcon("C:/Users/12234/Desktop/1.png"));
    bool judge=0;

    QString custom_user_name = ui->lineEdit->text();
    QString custom_password = ui->lineEdit_2->text();
    now_username=ui->lineEdit->text();
    custom_user_name="%"+custom_user_name+"#";
    custom_password=custom_password+"%";
    QString use_judege = custom_user_name+custom_password;
    //QRadioButton *rbutton;
    QString folderpath="C:/Users/12234/Documents/01/sum_info";
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
        if(custom_user_name.contains(fileInfo.fileName(),Qt::CaseSensitive)==true)
        {
            //QMessageBox::about(NULL, "提示", "找到啦");
            QString fp="C:/Users/12234/Documents/01/sum_info/";
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
                 if(s.contains(use_judege,Qt::CaseSensitive)==true)
                 {
                     judge=1;
                 }
                 else if(s.contains(use_judege,Qt::CaseSensitive)==true)
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
 //qDebug()<<custom_user_name<<custom_password;
    if(custom_user_name!="%admin#"&&judge==0)
    {
        QMessageBox msgBox;
       // msgBox.setText("用户名或密码错误，请重试！");
        qDebug()<<custom_user_name<<custom_password;
        QMessageBox::about(NULL, "提示", "用户名或密码错误，请重试！");

    }
    else if(judge==1&&ui->radioButton_2->isChecked())
    {
        w.show();
        this->hide();

    }
    else if(ui->radioButton->isChecked()&&custom_user_name=="%admin#"&&custom_password=="123%")
    {
        w1.show();
        this->hide();
    }
     else
    {
        QMessageBox msgBox;
       // msgBox.setText("用户名或密码错误，请重试！");
        qDebug()<<custom_user_name<<custom_password;
        QMessageBox::about(NULL, "提示", "用户名或密码错误，请重试！");
    }





}
