#include "maintenanceInquiry.h"
#include "ui_maintenanceInquiry.h"
#include "customerChannel.h"
#include "login.h"
#include "QMessageBox"
MaintenanceInquiry::MaintenanceInquiry(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MaintenanceInquiry)
{
    ui->setupUi(this);
     QStringList theStrList;
     QString fp=FILEPATH;
     fp=fp+"sum_info/" + now_username+"/fix_goods_info.txt";
     QFile f(fp);
     if(!f.open(QIODevice::ReadOnly | QIODevice::Text))
     {
         //qDebug()<<fp;
         QMessageBox::about(NULL, "提示", "文件异常");
         return;
     }
     while (!f.atEnd())
     {
          QStringList list;
          QByteArray line = f.readLine();
          QString s(line);
          QList<QString>lst;
          lst.clear();
          lst =s.split(',');
          //QString a="sssss";
          QString name=lst[0];
          QString goods_num=lst[1];
          QString fix_data = lst[2];
          QString money = lst[3];
          theStrList<<"待处理:   姓名："+name+" 订单编号："+goods_num+" 维修日期："+fix_data+" 预估费用"+money<<"\r\n";



     }



    theModel=new QStringListModel(this);
    theModel->setStringList(theStrList);
    ui->listView->setModel(theModel);
    ui->listView->setEditTriggers(QAbstractItemView::DoubleClicked|QAbstractItemView::SelectedClicked);
}

MaintenanceInquiry::~MaintenanceInquiry()
{
    delete ui;
}

void MaintenanceInquiry::on_pushButton_clicked()
{
    w4.show();
    this->hide();
}
void MaintenanceInquiry::ask_result()
{

}

void MaintenanceInquiry::on_pushButton_2_clicked()
{
    (new CustomerChannel())->show();
    this->hide();
}

