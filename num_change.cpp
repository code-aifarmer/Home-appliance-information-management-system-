#include "num_change.h"
#include "ui_num_change.h"
#include "ui_store.h"
#include "store.h"
#include<QSettings>
#include "mainwindow.h"
#include "store_manage.h"
Num_change::Num_change(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Num_change)
{
    ui->setupUi(this);
    QIcon icon("C:/Users/12234/Desktop/s.jpg");
    setWindowIcon(icon);
    setWindowTitle(QStringLiteral("家电信息管理系统"));
}

Num_change::~Num_change()
{
    delete ui;
}

int Num_change::isDigitStr(QString src)
{
    QByteArray ba = src.toLatin1();//QString 转换为 char*
     const char *s = ba.data();

    while(*s && *s>='0' && *s<='9') s++;

    if (*s)
    { //不是纯数字
        return -1;
    }
    else
    { //纯数字
        return 0;
    }
}
void Num_change::on_pushButton_clicked()
{
    read_change_info = ui->lineEdit->text();
    if(read_change_info.isEmpty())
    {
        QMessageBox::about(NULL,"提示","请填入正确的数量!");
    }
    if(isDigitStr(read_change_info) == -1)
    {
        QMessageBox::about(NULL,"提示","请输入有效的数字！");
        return;
    }
    QString fp=txt_path + "/01/inventory/storehouse.ini";
    QSettings settings(fp, QSettings::IniFormat);
    settings.setIniCodec("UTF-8");
    int num = settings.value("sumnum/number").toInt();
    for(int i = 1; i <= num; i++) {
        QString count;
        count = count.asprintf("%d", i);
        if(settings.value(count + "/id").toString() == index1) {
             settings.setValue(count + "/left", read_change_info);
             break;
        }
    }

    this->hide();
}

