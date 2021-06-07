#include "mainwindow5.h"
#include "ui_mainwindow5.h"
#include "mainwindow2.h"
MainWindow5::MainWindow5(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow5)
{
    ui->setupUi(this);
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


void MainWindow5::on_pushButton_2_clicked()
{
    (new MainWindow2())->show();
    this->hide();
}

