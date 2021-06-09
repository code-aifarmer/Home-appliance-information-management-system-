#ifndef MAINWINDOW2_H
#define MAINWINDOW2_H

#include <QMainWindow>
#include <mainwindow4.h>
#include <mainwindow5.h>
#include <mainwindow8.h>
namespace Ui {
class MainWindow2;
}

class MainWindow2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow2(QWidget *parent = nullptr);
    ~MainWindow2();
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

private:
    Ui::MainWindow2 *ui;
     MainWindow4 w2;
     MainWindow5 w3;
     MainWindow8 w5;



};

#endif // MAINWINDOW2_H
