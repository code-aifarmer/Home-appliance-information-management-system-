#ifndef MAINWINDOW13_H
#define MAINWINDOW13_H

#include <QMainWindow>
#include "QStringListModel"
namespace Ui {
class MainWindow13;
}

class MainWindow13 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow13(QWidget *parent = nullptr);
    ~MainWindow13();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow13 *ui;
    QStringListModel *theModel;
};

#endif // MAINWINDOW13_H
