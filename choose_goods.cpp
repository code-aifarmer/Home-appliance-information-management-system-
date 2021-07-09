#include "choose_goods.h"
#include "ui_choose_goods.h"
#include "air_conditioner.h"
#include "display.h"
#include "mainwindow2.h"
Choose_goods::Choose_goods(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Choose_goods)
{
    ui->setupUi(this);
    QIcon icon("C:/Users/12234/Desktop/s.jpg");
    setWindowIcon(icon);
    setWindowTitle(QStringLiteral("家电信息管理系统"));
}

Choose_goods::~Choose_goods()
{
    delete ui;
}

void Choose_goods::on_pushButton_clicked()
{
    (new Air_conditioner())->show();
    this->hide();
}


void Choose_goods::on_pushButton_2_clicked()
{
    (new Display())->show();
    this->hide();
}


void Choose_goods::on_pushButton_3_clicked()
{
    (new MainWindow2())->show();
    this->hide();
}

