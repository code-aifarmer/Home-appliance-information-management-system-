#include "mainwindow4.h"
#include "ui_mainwindow4.h"
#include "mainwindow2.h"
MainWindow4::MainWindow4(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow4)
{
    ui->setupUi(this);

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

