#ifndef MAINWINDOW14_H
#define MAINWINDOW14_H

#include <QMainWindow>
#include "audio.h"
#include "speech.h"
namespace Ui {
class MainWindow14;
}

class MainWindow14 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow14(QWidget *parent = nullptr);
    explicit MainWindow14(QMainWindow* parent);
    ~MainWindow14();

private slots:
    void on_pushButton_pressed();

    void on_pushButton_released();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

public:
    Ui::MainWindow14 *ui;
    audio* Audio;
    QMainWindow* parent;

};

#endif // MAINWINDOW14_H
