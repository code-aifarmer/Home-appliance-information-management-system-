#include "situation.h"
#include "ui_situation.h"
#include "managerChannel.h"
#include "returnSituation.h"
#include "maintenanceSituation.h"
Situation::Situation(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Situation)
{
    ui->setupUi(this);
}

Situation::~Situation()
{
    delete ui;
}

void Situation::on_pushButton_3_clicked()
{
    (new ManagerChannel)->show();
    this->hide();
}


void Situation::on_pushButton_clicked()
{
    (new ReturnSituation)->show();
    this->hide();
}


void Situation::on_pushButton_2_clicked()
{
    (new MaintenanceSituation)->show();
    this->hide();
}

