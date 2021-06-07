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
    ui->pushButton_2->setIcon(QIcon("C:/Users/12234/Desktop/1.png"));


    QString custom_user_name = ui->lineEdit->text();
    QString custom_password = ui->lineEdit_2->text();
    custom_user_name="%"+custom_user_name+"#";
    custom_password=custom_password+"%";
    QString use_judege = custom_user_name+custom_password;
    QRadioButton *rbutton;



        //QStringList fileList = QFileDialog::getOpenFileNames(nullptr,"select",QApplication::applicationDirPath(),"*.txt");
        //QString fileName = fileList.at(0);
        //QFile file(fileName);
        QString filePath = "C:/Users/12234/Desktop/2.txt";
        QFile f(filePath);
        if(!f.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            return;
        }

        while (!f.atEnd()) {
             QStringList list;
             QByteArray line = f.readLine();

             QString s(line);

             if(s.contains(use_judege,Qt::CaseSensitive)==true&&ui->radioButton_2->isChecked())
             {
                 //MainWindow2 *t =new MainWindow2;
                 w.show();
                 this->hide();
             }
             else if(s.contains(use_judege,Qt::CaseSensitive)==true&&ui->radioButton->isChecked())
             {
                 w1.show();
                 this->hide();
             }
             else
             {
                 QMessageBox msgBox;
                // msgBox.setText("用户名或密码错误，请重试！");
                 QMessageBox::about(NULL, "提示", "用户名或密码错误，请重试！");

             }

}
}
/*
void MainWindow::on_radioButton_2_clicked(bool checked)
{
    if(checked==true)
    {

    }
}//我是客户


void MainWindow::on_radioButton_clicked(bool checked)
{

}//我是经理

*/
