#include "maintenance.h"
#include "ui_maintenance.h"
#include "customerChannel.h"
#include "login.h"
#include "QMessageBox"
Maintenance::Maintenance(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Maintenance)
{
    ui->setupUi(this);

    QObject::connect(ui->comboBox,SIGNAL(currentIndexChanged(QString)),this,SLOT(on_comboBox_currentIndexChanged()));
}

Maintenance::~Maintenance()
{
    delete ui;
}



void Maintenance::on_comboBox_currentIndexChanged()
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


void Maintenance::on_pushButton_clicked()
{

    (new CustomerChannel())->show();
    this->hide();
}


void Maintenance::on_pushButton_2_clicked()
{
    //QString fix_info=ui->lineEdit->text()+"1";
    //fix_info.append(ui->lineEdit_2->text())+"2";
    //fix_info.append(ui->lineEdit_3->text())+"3";
    //fix_info.append(ui->lineEdit_4->text())+"4";
    QString a1=ui->lineEdit->text();
    QString a2=ui->lineEdit_2->text();
    QString a3=ui->lineEdit_3->text();
    QString a4=ui->lineEdit_4->text();
    QString filePath = FILEPATH;
    filePath += "sum_info/";
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

    //qDebug()<<now_username;

}

