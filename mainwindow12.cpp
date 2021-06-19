#include "mainwindow12.h"
#include "ui_mainwindow12.h"
#include "mainwindow.h"
#include "QMessageBox"
#include "stdio.h"
#include "string"
#include "iostream"
#include "mainwindow3.h"
using namespace std;
MainWindow12::MainWindow12(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow12)
{
    ui->setupUi(this);
    QStringList theStrList;

    QString fp="C:/Users/12234/Documents/01/sum_info/";
    fp=fp+find_username+"/return_goods_info.txt";
    QFile f(fp);
    if(!f.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        //qDebug()<<fp;
        QMessageBox::about(NULL, "提示", "该用户无退货申请！");
        return;
    }


    while (!f.atEnd())
    {
         QStringList list;
         QByteArray line = f.readLine();
         QString s(line);
         QList<QString>lst;
         lst.clear();
         lst =s.split(',');
         //QString a="sssss";
         QString reason_return=lst[0];
         QString goods_num=lst[1];
         QString note = lst[2];
         theStrList<<"退货原因："+reason_return+" 商品编号："+goods_num+" 备注："+note<<"\n";



    }





    //theStrList<<"用户名："<<fileInfo.fileName();
    theModel=new QStringListModel(this);
    theModel->setStringList(theStrList);
    ui->listView->setModel(theModel);
    ui->listView->setEditTriggers(QAbstractItemView::DoubleClicked|QAbstractItemView::SelectedClicked);
}
MainWindow12::~MainWindow12()
{
    delete ui;
}

void MainWindow12::on_pushButton_clicked()
{
    (new MainWindow3)->show();
    this->hide();
}

void DeleteOneline(int nNum, QString &strall)//
{
    int nLine=0;
    int Index=0;
    //算出行数nLine
    while(Index!=-1)
    {
        Index=strall.indexOf('\n',Index+1);
        nLine++;
    }

    //如果是直接从位置0开始删除\n算一个字符"abc\nme\ndo" \n的index是3要删除3+1个字符，即index+1个
    if(nNum==0)
    {
        int nIndex=strall.indexOf('\n');
        strall.remove(0,nIndex+1);
    }
    else
    {
        int nTemp=nNum;
        int nIndex=0,nIndex2=0;
        while(nTemp--)
        {
            //
            nIndex=strall.indexOf('\n',nIndex+1);//这里会更新nIndex
            if(nIndex!=-1)//说明是有效的
            {
                nIndex2=strall.indexOf('\n',nIndex+1);
            }
        }
        //删除的行不是最后一行（从nIndex+1这个位置起nIndex2-nIndex个字符全部抹去）
        if(nNum<nLine-1)
        {
            strall.remove(nIndex+1, nIndex2-nIndex);//不用减一
        }
        //删除的是最后一行（从nIndex起始len-nIndex个字符全抹去）
        //不能从nIndex+1处开始，
        else if(nNum==nLine-1)
        {
            int len=strall.length();
            strall.remove(nIndex,len-nIndex);
        }
        else
        {

        }

    }
}
void deleteOnelineInFile(int nNumLine, QString &filename)
{
    QString strall;
    QFile readfile(filename);
    if(readfile.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&readfile);
        strall=stream.readAll();
    }
    readfile.close();
    DeleteOneline(nNumLine, strall);

    QFile writefile(filename);
    if(writefile.open(QIODevice::WriteOnly))
    {
        QTextStream wrtstream(&writefile);
        wrtstream<<strall;
    }
    writefile.close();


}
void MainWindow12::on_pushButton_2_clicked()
{
    QString fp="C:/Users/12234/Documents/01/sum_info/";
    fp=fp+find_username+"/return_goods_info.txt";
    QModelIndex index;
    index=ui->listView->currentIndex();
    theModel->removeRow(index.row());
    //deleteOnelineInFile(3,QString(“c:\delline.txt”));
    deleteOnelineInFile(index.data().toInt(),fp);
    qDebug()<<index.data().toInt();
    QMessageBox::about(NULL,"提示","已拒绝该申请！");
}


void MainWindow12::on_pushButton_3_clicked()
{
    QString fp="C:/Users/12234/Documents/01/sum_info/";
    fp=fp+find_username+"/return_goods_info.txt";
    QModelIndex index;
    index=ui->listView->currentIndex();
    theModel->removeRow(index.row());
    //deleteOnelineInFile(3,QString(“c:\delline.txt”));
    deleteOnelineInFile(index.data().toInt(),fp);
    qDebug()<<index.data().toInt();
    QMessageBox::about(NULL,"提示","已批准该申请！");
}

