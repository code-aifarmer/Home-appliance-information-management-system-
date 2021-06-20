#ifndef CUSTOMERCHANNEL_H
#define CUSTOMERCHANNEL_H

#include <QMainWindow>
#include <maintenance.h>
//#include <mainwindow5.h>
#include <customerService.h>
#include "QStringListModel"
namespace Ui {
class CustomerChannel;
}

class CustomerChannel : public QMainWindow
{
    Q_OBJECT

public:
    explicit CustomerChannel(QWidget *parent = nullptr);
    ~CustomerChannel();
//signals:
    //void signal_ui_switch();
    //void signal_ipdisconnect();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();


    //void returnMainwindow();

    //void slot_ui_switch();
    void on_pushButton_5_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::CustomerChannel *ui;
     Maintenance w2;
     //MainWindow5 w3;
     CustomerService w5;
    QStringListModel *theModel;


};

#endif // CUSTOMERCHANNEL_H
