#include "managerChannel.h"
#include "ui_managerChannel.h"
#include "login.h"
#include "situation.h"
ManagerChannel::ManagerChannel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ManagerChannel)
{
    ui->setupUi(this);


    QStringList theStrList;
    QString folderpath=FILEPATH;
    folderpath+="sum_info";
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

ManagerChannel::~ManagerChannel()
{
    delete ui;
}

void ManagerChannel::on_pushButton_5_clicked()
{
    (new Login)->show();
    this->hide();
}



void ManagerChannel::on_pushButton_clicked()
{
    QModelIndex index;
    index=ui->listView->currentIndex();
    find_username=index.data().toString();
    qDebug()<<find_username;
    m11.show();
    this->hide();
}

