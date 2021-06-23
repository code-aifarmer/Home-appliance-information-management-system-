#include "mainwindow3.h"
#include "ui_mainwindow3.h"
#include "mainwindow.h"
#include "mainwindow11.h"
MainWindow3::MainWindow3(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow3)
{
    ui->setupUi(this);
    QIcon icon("C:/Users/12234/Desktop/s.jpg");
    setWindowIcon(icon);
    setWindowTitle(QStringLiteral("家电信息管理系统"));


    QStringList theStrList;
    QString folderpath="C:/Users/12234/Documents/01/sum_info";
    QDir dir(folderpath);
    if(!dir.exists())
    {
        return;
    }
    dir.setFilter(QDir::Dirs|QDir::Files);//除了目录和文件，其他的过滤掉
    dir.setSorting(QDir::DirsFirst);//优先显示目录
    QFileInfoList list1 = dir.entryInfoList();//获取文件信息列表
    int i=2;
    do
    {
        QFileInfo fileInfo = list1.at(i);
        theStrList<<"用户名："<<fileInfo.fileName();



        i++;
     }
        //qDebug()<<fileInfo.fileName()<<custom_user_name;

        while(i<list1.size());








    //theStrList<<"1"<<"2";
    theModel=new QStringListModel(this);
    theModel->setStringList(theStrList);
    ui->listView->setModel(theModel);
    ui->listView->setEditTriggers(QAbstractItemView::DoubleClicked|QAbstractItemView::SelectedClicked);
}

MainWindow3::~MainWindow3()
{
    delete ui;
}

void MainWindow3::on_pushButton_5_clicked()
{
    (new MainWindow)->show();
    this->hide();
}



void MainWindow3::on_pushButton_clicked()
{
    QModelIndex index;
    index=ui->listView->currentIndex();
    find_username=index.data().toString();
    qDebug()<<find_username;
    m11.show();
    this->hide();
}

