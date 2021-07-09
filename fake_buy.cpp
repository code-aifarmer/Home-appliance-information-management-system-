#include "fake_buy.h"
#include "ui_fake_buy.h"
#include "QMessageBox"
#include "air_conditioner.h"
#include "QMessageBox"
#include <QButtonGroup>
#include <QDebug>
#include<QFile>
#include<QFileDialog>
#include<QDir>
#include<QTextStream>
#include <QPlainTextEdit>
#include <QTextStream>>
#include <QDir>
#include "mainwindow.h"
fake_buy::fake_buy(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::fake_buy)
{
    ui->setupUi(this);
    QIcon icon("C:/Users/12234/Desktop/s.jpg");
    setWindowIcon(icon);
    setWindowTitle(QStringLiteral("家电信息管理系统"));
}

fake_buy::~fake_buy()
{
    delete ui;
}
void fake_buy::show_num()
{
    QString fp=txt_path+"/01/inventory/storehouse.ini";
       QSettings settings(fp, QSettings::IniFormat);
      // TODO;
       QString id = "1";

       int num = settings.value("sumnum/number").toInt();
       for(int i = 0; i < num; i++) {
           QString section = id.asprintf("%d", i);
           if(id == settings.value(section + "/id").toString()) {
               ui->lineEdit->setText(settings.value(section + "/left").toString());
               break;
           }
       }


}

void fake_buy::on_pushButton_2_clicked()
{

    QString fp=txt_path+"/01/inventory/storehouse.ini";
      QSettings settings(fp, QSettings::IniFormat);
      //TODO
      QString id = "1";
      int num = settings.value("sumnum/number").toInt(), left = 0;
      for(int i = 0; i < num; i++) {
          QString section = id.asprintf("%d", i);
          if(id == settings.value(section + "/id").toString()) {
              left = settings.value(section + "/left").toInt() - 1;
              settings.setValue(section + "/left", left);
          }
      }

      QMessageBox::about(NULL,"提示","感谢您的购买");
      ui->lineEdit->setText(QString::number(left));

}


void fake_buy::on_pushButton_3_clicked()
{
    (new Air_conditioner())->show();
    this->hide();
}

