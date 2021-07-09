#include "add_goods.h"
#include "ui_add_goods.h"
#include "mainwindow.h"
#include<QSettings>
#include<QDate>
#include "store.h"
#include "store.h"
#include "QTextStream"
#include "fstream"
#include<iomanip>
#include<fstream>
#include<QTextCodec>
#include "iostream"
using namespace std;
Add_goods::Add_goods(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Add_goods)
{
    ui->setupUi(this);
    QIcon icon("C:/Users/12234/Desktop/s.jpg");
    setWindowIcon(icon);
    setWindowTitle(QStringLiteral("家电信息管理系统"));
}

Add_goods::~Add_goods()
{
    delete ui;
}
int Add_goods::isDigitStr(QString src)
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
void Add_goods::on_pushButton_clicked()
{
    QString input1 = ui->left->text();
    QString input2 = ui->price->text();
    QString input3 = ui->name->text();
    if(isDigitStr(input1) == -1||isDigitStr(input2) == -1)
    {
        QMessageBox::about(NULL,"提示","请输入有效的数字！");
        return;
    }
    if(input1.isEmpty()||input2.isEmpty()||input3.isEmpty())
    {
        QMessageBox::about(NULL,"提示","请填入完整的信息！");
        return;
    }
    QString fp=txt_path + "/01/inventory/storehouse.ini";
    //QString filename = QCoreApplication::applicationDirPath();
    //ifstream fin(filename.toStdString()+"/database/info.txt");
    QSettings settings(fp, QSettings::IniFormat);
    settings.setIniCodec("UTF-8");
    int num = settings.value("sumnum/number").toInt() + 1;
    QString section = fp.asprintf("%d", num);
    settings.setValue(section + "/id", num);
    settings.setValue(section + "/name", ui->name->text());
    settings.setValue(section + "/price", ui->price->text());
    settings.setValue(section + "/left", ui->left->text());
    QString date = fp.asprintf("%d.%d.%d  %d:%d:%d", QDate::currentDate().year(),  QDate::currentDate().month(),  QDate::currentDate().day(),QTime::currentTime().hour(),QTime::currentTime().minute(),QTime::currentTime().second());
    settings.setValue(section + "/date", date);
    settings.setValue(section + "/type", 0);
    settings.setValue("sumnum/number", num);

    QMessageBox::about(NULL,"提示","增加成功！");
    (new Store())->show();
    this->hide();
}


void Add_goods::on_pushButton_2_clicked()
{
    (new Store())->show();
    this->hide();
}

