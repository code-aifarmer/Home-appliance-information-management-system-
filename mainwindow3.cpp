#include "mainwindow3.h"
#include "ui_mainwindow3.h"
#include "mainwindow.h"

MainWindow3::MainWindow3(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow3)
{
    ui->setupUi(this);
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

