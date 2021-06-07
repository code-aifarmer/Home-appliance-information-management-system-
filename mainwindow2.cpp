#include "mainwindow2.h"
#include "ui_mainwindow2.h"
#include "mainwindow.h"
//MainWindow *main_window;
MainWindow2::MainWindow2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow2)
{
    ui->setupUi(this);


}

MainWindow2::~MainWindow2()
{
    delete ui;
}

void MainWindow2::on_pushButton_clicked()
{
    this->close();
}


void MainWindow2::on_pushButton_3_clicked()
{
    w2.show();
    this->hide();
}


void MainWindow2::on_pushButton_4_clicked()
{
    w3.show();
    this->hide();
}


void MainWindow2::on_pushButton_6_clicked()
{


    (new MainWindow())->show();
    this->hide();


}



