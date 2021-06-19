#ifndef MAINWINDOW3_H
#define MAINWINDOW3_H
#include "mainwindow11.h"
#include <QMainWindow>
#include "QStringListModel"
namespace Ui {
class MainWindow3;
}

class MainWindow3 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow3(QWidget *parent = nullptr);
    ~MainWindow3();

private slots:
    void on_pushButton_5_clicked();

   // void on_listView_indexesMoved(const QModelIndexList &indexes);

    void on_pushButton_clicked();

private:
    Ui::MainWindow3 *ui;
    QStringListModel *theModel;
    MainWindow11 m11;
};

#endif // MAINWINDOW3_H
