#include "mainwindow4.h"
#include "ui_mainwindow4.h"
#include "mainwindow2.h"
#include "mainwindow.h"
#include "QMessageBox"
MainWindow4::MainWindow4(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow4)
{
    ui->setupUi(this);
    QIcon icon("C:/Users/12234/Desktop/s.jpg");
    setWindowIcon(icon);
    setWindowTitle(QStringLiteral("家电信息管理系统"));

    QObject::connect(ui->comboBox,SIGNAL(currentIndexChanged(QString)),this,SLOT(on_comboBox_currentIndexChanged()));
}

MainWindow4::~MainWindow4()
{
    delete ui;
}



void MainWindow4::on_comboBox_currentIndexChanged()
{
   if(ui->comboBox->currentIndex()==0)
   {
        ui->lineEdit_3->setText("三日内完成检修");
   }
   if(ui->comboBox->currentIndex()==1)
   {
       ui->lineEdit_3->setText("五日内完成检修");
   }
   if(ui->comboBox->currentIndex()==2)
   {
       ui->lineEdit_3->setText("一周内完成检修");
   }
   if(ui->comboBox->currentIndex()==0)
   {
        ui->lineEdit_4->setText("1000￥");
   }
   if(ui->comboBox->currentIndex()==1)
   {
       ui->lineEdit_4->setText("2000￥");
   }
   if(ui->comboBox->currentIndex()==2)
   {
       ui->lineEdit_4->setText("5000￥");
   }
}


void MainWindow4::on_pushButton_clicked()
{

    (new MainWindow2())->show();
    this->hide();
}


void MainWindow4::on_pushButton_2_clicked()
{
    //QString fix_info=ui->lineEdit->text()+"1";
    //fix_info.append(ui->lineEdit_2->text())+"2";
    //fix_info.append(ui->lineEdit_3->text())+"3";
    //fix_info.append(ui->lineEdit_4->text())+"4";

    QString a1=ui->lineEdit->text();
    QString a2=ui->lineEdit_2->text();
    QString a3=ui->lineEdit_3->text();
    QString a4=ui->lineEdit_4->text();
    if(a1.isEmpty()||a2.isEmpty())
    {
        QMessageBox::about(NULL,"提示","请输入完整的信息!");
        return;
    }
    QString filePath = txt_path + "/01/sum_info/";
    filePath=filePath+now_username+"/fix_goods_info.txt";
    qDebug()<<filePath;
        QFile f(filePath);
        if(!f.open(QIODevice::WriteOnly | QIODevice::Text|QIODevice::Append))
        {
         QMessageBox::about(NULL, "提示", "文件异常");
            return;
        }
        QTextStream txtOutput(&f);
        txtOutput <<a1<<","<<a2<<","<<a3<<","<<a4<<"\n";
        f.close();
        QMessageBox::about(NULL, "提示", "您已成功提交申请！");
        (new MainWindow2())->show();
        this->hide();

    //qDebug()<<now_username;

}

