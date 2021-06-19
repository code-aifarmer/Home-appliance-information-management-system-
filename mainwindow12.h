#ifndef MAINWINDOW12_H
#define MAINWINDOW12_H

#include <QMainWindow>
#include "QStringListModel"
namespace Ui {
class MainWindow12;
}

class MainWindow12 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow12(QWidget *parent = nullptr);
    ~MainWindow12();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow12 *ui;
     QStringListModel *theModel;
};

#endif // MAINWINDOW12_H
