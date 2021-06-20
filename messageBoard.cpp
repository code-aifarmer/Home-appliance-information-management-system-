#include "messageBoard.h"
#include "ui_messageBoard.h"
#include "customerChannel.h"
#include "comment.h"
#include "QMessageBox"
#include "QtDebug"
#include "login.h"
MessageBoard::MessageBoard(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MessageBoard)
{
    ui->setupUi(this);
    k = new Comment(this);
}

MessageBoard::~MessageBoard()
{
    delete ui;
}

void MessageBoard::on_pushButton_2_clicked()
{
    (new CustomerChannel())->show();
    this->hide();
}

void MessageBoard::on_pushButton_clicked()
{
    //k->ui->textEdit->textCursor().insertText(ui->lineEdit->text()+"\n\n");


    //k->sendData(ui->lineEdit->text());
    //k->sendData(ui->lineEdit->text());
    //k->show();
    //qDebug()<<ui->lineEdit->text()<<k->ui->textEdit->toPlainText();
    QString filePath = FILEPATH;
    filePath+="comment.txt";
    QFile f(filePath);
    if(!f.open(QIODevice::WriteOnly | QIODevice::Text|QIODevice::Append))
    {
     QMessageBox::about(NULL, "提示", "文件异常");
        return;
    }
    QTextStream txtOutput(&f);
   // QString s1=ui->lineEdit->text();
    QString s2=ui->textEdit->toPlainText();
    txtOutput <<now_username<<"的评论:"<<s2<<"\r\n";
    f.close();
    ui->textEdit->clear();
    QMessageBox::about(NULL,"提示","评论成功！");
}


void MessageBoard::on_pushButton_3_clicked()
{

    //qDebug()<<(unsigned long long)k;
    if(k)
    {
    k->show_comment();
    k->show();
    this->hide();
    }
}

