#include "mainwindow10.h"
#include "ui_mainwindow10.h"
#include "mainwindow6.h"
#include "mainwindow.h"
#include "QMessageBox"
MainWindow10::MainWindow10(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow10)
{
    ui->setupUi(this);
    QIcon icon("C:/Users/12234/Desktop/s.jpg");
    setWindowIcon(icon);
    setWindowTitle(QStringLiteral("家电信息管理系统"));
}

MainWindow10::~MainWindow10()
{
    delete ui;
}


void MainWindow10::show_comment()
{
    QString fp=txt_path+"/01/comment.txt";
    QFile f(fp);
    if(!f.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        //qDebug()<<fp;
        QMessageBox::about(NULL, "提示", "文件异常");
        return;
    }
    while (!f.atEnd())
    {
         //QStringList list;
         QByteArray line = f.readLine();
         QString s(line);
        qDebug()<<s;
        ui->textEdit->textCursor().insertText(s+"\n");
    }


     //ui->textEdit->textCursor().insertText("客服："+tuling_get_ans+"\n\n");

}
void MainWindow10::on_pushButton_clicked()
{
    (new MainWindow6())->show();
    this->hide();
}
