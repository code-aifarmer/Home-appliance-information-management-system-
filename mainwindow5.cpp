#include "mainwindow5.h"
#include "ui_mainwindow5.h"
#include "mainwindow2.h"
#include "mainwindow.h"
#include "QMessageBox"
MainWindow5::MainWindow5(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow5)
{
    ui->setupUi(this);
    QIcon icon("C:/Users/12234/Desktop/s.jpg");
    setWindowIcon(icon);
    setWindowTitle(QStringLiteral("家电信息管理系统"));
    // ui->listView->setTextColor(Qt::red);
     QStringList theStrList;
     QString fp=txt_path + "/01/sum_info/";
     fp=fp+now_username+"/fix_goods_info.txt";
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

MainWindow5::~MainWindow5()
{
    delete ui;
}

void MainWindow5::on_pushButton_clicked()
{
    w4.show();
    this->hide();
}
void MainWindow5::ask_result()
{

}

void MainWindow5::on_pushButton_2_clicked()
{
    (new MainWindow2())->show();
    this->hide();
}

