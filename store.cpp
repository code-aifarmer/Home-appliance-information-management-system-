#include "store.h"
#include "ui_store.h"
#include "QStandardItemModel"
#include "QMessageBox"
#include <QButtonGroup>
#include <QDebug>
#include<QFile>
#include<QFileDialog>
#include<QDir>
#include<QTextStream>
#include <QPlainTextEdit>
#include <QTextStream>
#include <QDir>
#include "mainwindow.h"
#include "QSettings"
#include <QCoreApplication>
#include "num_change.h"
#include "ui_num_change.h"
#include"add_goods.h"
#include "store_manage.h"
#pragma execution_character_set("utf-8")

Store::Store(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Store)
{
    ui->setupUi(this);
    QIcon icon("C:/Users/12234/Desktop/s.jpg");
    setWindowIcon(icon);
    setWindowTitle(QStringLiteral("家电信息管理系统"));


        //QStandardItemModel *model = new QStandardItemModel();
        ui->tableView->setModel(model);





        ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        model->setColumnCount(5);
        model->setHeaderData(0,Qt::Horizontal,"商品编号");
        model->setHeaderData(1,Qt::Horizontal,"商品名称");
        model->setHeaderData(2,Qt::Horizontal,"商品价格");
        model->setHeaderData(3,Qt::Horizontal,"商品库存");
        model->setHeaderData(4,Qt::Horizontal,"采购日期");
         this->ui->tableView->setColumnWidth(0, 100);    //设置列的宽度
         this->ui->tableView->setColumnWidth(1, 100);
         this->ui->tableView->setColumnWidth(2, 100);
         this->ui->tableView->setColumnWidth(3, 100);
         this->ui->tableView->setColumnWidth(4, 150);
         QString fp=txt_path + "/01/inventory/storehouse.ini";
         QSettings settings(fp, QSettings::IniFormat);
         settings.setIniCodec("UTF-8");
         int num = settings.value("sumnum/number").toInt();
         for(int i = 1, id_index = 0; i <= num; i++) {
             QString count;
             count = count.asprintf("%d", i);
             if(settings.value(count + "/type").toInt() == 1) continue;
             model->setItem(id_index, 0, new QStandardItem(settings.value(count + "/id").toString()));
             model->setItem(id_index, 1, new QStandardItem(settings.value(count + "/name").toString()));
             model->setItem(id_index, 2, new QStandardItem(settings.value(count + "/price").toString()));
             model->setItem(id_index, 3, new QStandardItem(settings.value(count + "/left").toString()));
             model->setItem(id_index, 4, new QStandardItem(settings.value(count + "/date").toString()));
             id_index++;
         }
        ui->tableView->setContextMenuPolicy(Qt::CustomContextMenu);
        popMenu = new QMenu(ui->tableView);
        QAction *actionUpdateInfo = new QAction();
        QAction *actionDelInfo = new QAction();
        actionUpdateInfo ->setText(QString("修改"));
        actionDelInfo ->setText(QString("删除"));
        popMenu->addAction(actionUpdateInfo);
        popMenu->addAction(actionDelInfo);
        connect(actionUpdateInfo,&QAction::triggered,this,&Store::update_info);
        connect(actionDelInfo,&QAction::triggered,this,&Store::del_info);
        connect(ui->tableView, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(slotContextMenu(QPoint)));
        //connect(update_info(),&QAction::triggered,this,SLOT(slotContextMenu(QPoint)));
        ui->tableView->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
    //ui->tableView->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
}
void Store::update_info()
{
    //qDebug()<<"1111111";
    //qDebug()<<ui->tableView->indexAt()
    QString index = (model->index(selected_current_row,0)).data().toString();
    //qDebug()<<index;
    index1=index;

    //test=get_change_info->ui->lineEdit->text();






    (new Num_change())->show();
    QString test="";
    //Num_change * get_change_info = new Num_change();
    //qDebug()<<read_change_info;

}
void Store::del_info()
{
    QString index = (model->index(selected_current_row,0)).data().toString();
    //qDebug()<<index;
    index1=index;
    QString fp=txt_path + "/01/inventory/storehouse.ini";
    QSettings settings(fp, QSettings::IniFormat);
    settings.setIniCodec("UTF-8");
    int num = settings.value("sumnum/number").toInt();
    for(int i = 1; i <= num; i++) {
        QString count;
        count = count.asprintf("%d", i);
        if(settings.value(count + "/id").toString() == index1) {
            settings.setValue(count + "/type", 1);
            break;
        }
    }

}
void Store::slotContextMenu(QPoint pos)
{
    //QMenu *popMenu;

   auto index = ui->tableView->indexAt(pos);
   selected_current_row = index.row();
    if (index.isValid())
    {
        popMenu->exec(QCursor::pos()); // 菜单出现的位置为当前鼠标的位置
    }
}

Store::~Store()
{
    delete ui;
}

void Store::on_pushButton_clicked()
{

    real_value = read_change_info;
    (new Store())->show();
    this->hide();

}//刷新


void Store::on_pushButton_2_clicked()
{
    (new Add_goods())->show();
    this->hide();
}


void Store::on_pushButton_3_clicked()
{
    (new Store_manage())->show();
    this->hide();
}

