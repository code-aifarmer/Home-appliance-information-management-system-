#ifndef MAINWINDOW15_H
#define MAINWINDOW15_H

#include <QMainWindow>
#include "smtp.h"
namespace Ui {
class MainWindow15;
}

class MainWindow15 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow15(QWidget *parent = nullptr);
    ~MainWindow15();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow15 *ui;
};

#endif // MAINWINDOW15_H
