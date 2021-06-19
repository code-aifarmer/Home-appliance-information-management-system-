#ifndef MAINWINDOW6_H
#define MAINWINDOW6_H

#include <QMainWindow>
#include "mainwindow10.h"
#include "ui_mainwindow10.h"
namespace Ui {
class MainWindow6;
}

class MainWindow6 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow6(QWidget *parent = nullptr);
    ~MainWindow6();
    //void sendData(QString data);

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow6 *ui;
    MainWindow10 *k;
};

#endif // MAINWINDOW6_H
