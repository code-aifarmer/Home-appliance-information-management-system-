#include "display.h"
#include "ui_display.h"
#include "choose_goods.h"
Display::Display(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Display)
{
    ui->setupUi(this);
    QIcon icon("C:/Users/12234/Desktop/s.jpg");
    setWindowIcon(icon);
    setWindowTitle(QStringLiteral("家电信息管理系统"));
}

Display::~Display()
{
    delete ui;
}

void Display::on_pushButton_5_clicked()
{
    (new Choose_goods())->show();
    this->hide();
}

