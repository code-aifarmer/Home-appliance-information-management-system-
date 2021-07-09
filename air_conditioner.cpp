#include "air_conditioner.h"
#include "ui_air_conditioner.h"
#include "choose_goods.h"
#include "fake_buy.h"
Air_conditioner::Air_conditioner(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Air_conditioner)
{
    ui->setupUi(this);
    QIcon icon("C:/Users/12234/Desktop/s.jpg");
    setWindowIcon(icon);
    setWindowTitle(QStringLiteral("家电信息管理系统"));
}

Air_conditioner::~Air_conditioner()
{
    delete ui;
}

void Air_conditioner::on_pushButton_5_clicked()
{
    (new Choose_goods())->show();
    this->hide();
}


void Air_conditioner::on_pushButton_clicked()
{

    x.show();
    x.show_num();
    this->hide();
}

