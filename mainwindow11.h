#ifndef MAINWINDOW11_H
#define MAINWINDOW11_H

#include <QMainWindow>

namespace Ui {
class MainWindow11;
}

class MainWindow11 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow11(QWidget *parent = nullptr);
    ~MainWindow11();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow11 *ui;
};

#endif // MAINWINDOW11_H
