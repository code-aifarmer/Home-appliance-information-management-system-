#ifndef MAINWINDOW9_H
#define MAINWINDOW9_H

#include <QMainWindow>
#include "mainwindow.h"
#include "ui_mainwindow.h"
namespace Ui {
class MainWindow9;
}

class MainWindow9 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow9(QWidget *parent = nullptr);
    ~MainWindow9();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow9 *ui;
    MainWindow *p1;
};

#endif // MAINWINDOW9_H
