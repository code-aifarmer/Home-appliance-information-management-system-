#include "maintenanceSituation.h"
#include "ui_maintenanceSituation.h"
#include "managerChannel.h"
#include "returnSituation.h"
#include "login.h"
#include "QMessageBox"
#include "stdio.h"
#include "string"
#include "iostream"
#include "managerChannel.h"
#include "situation.h"
using namespace std;
MaintenanceSituation::MaintenanceSituation(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MaintenanceSituation)
{
    ui->setupUi(this);
    QStringList theStrList;

    QString fp=FILEPATH;
    fp=fp+"sum_info/"+find_username+"/fix_goods_info.txt";
    QFile f(fp);
    if(!f.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        //qDebug()<<fp;
        QMessageBox::about(NULL, "提示", "该用户无维修申请！");
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
         QString name=lst[0];
         QString goods_num=lst[1];
         QString fix_data = lst[2];
         QString money = lst[3];
         theStrList<<"姓名："+name+" 订单编号："+goods_num+" 维修日期："+fix_data+" 预估费用"+money<<"\n";



    }





    //theStrList<<"用户名："<<fileInfo.fileName();
    theModel=new QStringListModel(this);
    theModel->setStringList(theStrList);
    ui->listView->setModel(theModel);
    ui->listView->setEditTriggers(QAbstractItemView::DoubleClicked|QAbstractItemView::SelectedClicked);
}

MaintenanceSituation::~MaintenanceSituation()
{
    delete ui;
}

void MaintenanceSituation::on_pushButton_clicked()
{
    (new ManagerChannel)->show();
    this->hide();
}
void DeleteOneline1(int nNum, QString &strall)//
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
void deleteOnelineInFile1(int nNumLine, QString &filename)
{
    QString strall;
    QFile readfile(filename);
    if(readfile.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&readfile);
        strall=stream.readAll();
    }
    readfile.close();
    DeleteOneline1(nNumLine, strall);

    QFile writefile(filename);
    if(writefile.open(QIODevice::WriteOnly))
    {
        QTextStream wrtstream(&writefile);
        wrtstream<<strall;
    }
    writefile.close();


}
void MaintenanceSituation::on_pushButton_2_clicked()
{
    QString fp=FILEPATH;
    fp=fp+"sum_info/"+find_username+"/fix_goods_info.txt";
    QModelIndex index;
    index=ui->listView->currentIndex();
    theModel->removeRow(index.row());
    //deleteOnelineInFile(3,QString(“c:\delline.txt”));
    deleteOnelineInFile1(index.data().toInt(),fp);
    qDebug()<<index.data().toInt();
    QMessageBox::about(NULL,"提示","已拒绝该申请！");

}


void MaintenanceSituation::on_pushButton_3_clicked()
{
    QString fp=FILEPATH;
    fp+="sum_info/";
    fp=fp+find_username+"/fix_goods_info.txt";
    QModelIndex index;
    index=ui->listView->currentIndex();
    theModel->removeRow(index.row());
    //deleteOnelineInFile(3,QString(“c:\delline.txt”));
    deleteOnelineInFile1(index.data().toInt(),fp);
    qDebug()<<index.data().toInt();
    QMessageBox::about(NULL,"提示","已批准该申请！");
}

