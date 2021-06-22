#include "mainwindow11.h"
#include "ui_mainwindow11.h"
#include "mainwindow3.h"
#include "mainwindow12.h"
#include "mainwindow13.h"
MainWindow11::MainWindow11(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow11)
{
    ui->setupUi(this);
    QIcon icon("C:/Users/12234/Desktop/s.jpg");
    setWindowIcon(icon);
    setWindowTitle(QStringLiteral("家电信息管理系统"));
}

MainWindow11::~MainWindow11()
{
    delete ui;
}

void MainWindow11::on_pushButton_3_clicked()
{
    (new MainWindow3)->show();
    this->hide();
}


void MainWindow11::on_pushButton_clicked()
{
    (new MainWindow12)->show();
    this->hide();
}


void MainWindow11::on_pushButton_2_clicked()
{
    (new MainWindow13)->show();
    this->hide();
}

