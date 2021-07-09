#include "mainwindow6.h"
#include "ui_mainwindow6.h"
#include "mainwindow2.h"
#include "mainwindow10.h"
#include "QMessageBox"
#include "QtDebug"
#include "mainwindow.h"
MainWindow6::MainWindow6(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow6)
{
    ui->setupUi(this);
    QIcon icon("C:/Users/12234/Desktop/s.jpg");
    setWindowIcon(icon);
    setWindowTitle(QStringLiteral("家电信息管理系统"));
    // ui->textEdit->setTextColor(Qt::white);
    k = new MainWindow10(this);
}

MainWindow6::~MainWindow6()
{
    delete ui;
}

void MainWindow6::on_pushButton_2_clicked()
{
    (new MainWindow2())->show();
    this->hide();
}

void MainWindow6::on_pushButton_clicked()
{
    //k->ui->textEdit->textCursor().insertText(ui->lineEdit->text()+"\n\n");


    //k->sendData(ui->lineEdit->text());
    //k->sendData(ui->lineEdit->text());
    //k->show();
    //qDebug()<<ui->lineEdit->text()<<k->ui->textEdit->toPlainText();
    QString input = ui->textEdit->toPlainText();
    if(input.isEmpty())
    {
        QMessageBox::about(NULL,"提示","评论内容不能为空！");
        return;
    }
    QString filePath = txt_path + "/01/comment.txt";
    QFile f(filePath);
    if(!f.open(QIODevice::WriteOnly | QIODevice::Text|QIODevice::Append))
    {
     QMessageBox::about(NULL, "提示", "文件异常");
        return;
    }
    QTextStream txtOutput(&f);
   // QString s1=ui->lineEdit->text();
    QString s2=ui->textEdit->toPlainText();
    QString a="的评论：";
    txtOutput <<now_username<<a<<s2<<"\r\n";
    f.close();
    ui->textEdit->clear();
    QMessageBox::about(NULL,"提示","评论成功！");
}


void MainWindow6::on_pushButton_3_clicked()
{

    //qDebug()<<(unsigned long long)k;
    if(k)
    {
    k->show_comment();
    k->show();
    this->hide();
    }
}

