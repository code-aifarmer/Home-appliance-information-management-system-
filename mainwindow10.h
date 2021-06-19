#ifndef MAINWINDOW10_H
#define MAINWINDOW10_H

#include <QMainWindow>

namespace Ui {
class MainWindow10;
}

class MainWindow10 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow10(QWidget *parent = nullptr);
    ~MainWindow10();
    //void sendData(QString data);
public slots:
    void show_comment();
private slots:
    void on_pushButton_clicked();

public:
    Ui::MainWindow10 *ui;
};

#endif // MAINWINDOW10_H
