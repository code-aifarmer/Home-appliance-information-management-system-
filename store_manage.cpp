#include "store_manage.h"
#include "ui_store_manage.h"
#include "mainwindow3.h"
#include "mainwindow.h"
#include "store.h"
Store_manage::Store_manage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Store_manage)
{
    ui->setupUi(this);
    QIcon icon("C:/Users/12234/Desktop/s.jpg");
    setWindowIcon(icon);
    setWindowTitle(QStringLiteral("家电信息管理系统"));
}

Store_manage::~Store_manage()
{
    delete ui;
}

void Store_manage::on_pushButton_2_clicked()
{
    (new MainWindow3())->show();
    this->hide();
}


void Store_manage::on_pushButton_clicked()
{
    (new MainWindow())->show();
    this->hide();
}


void Store_manage::on_pushButton_3_clicked()
{
    s.show();
    this->hide();
}

