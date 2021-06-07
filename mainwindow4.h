#ifndef MAINWINDOW4_H
#define MAINWINDOW4_H

#include <QMainWindow>

namespace Ui {
class MainWindow4;
}

class MainWindow4 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow4(QWidget *parent = nullptr);
    ~MainWindow4();

private slots:
    void on_comboBox_currentIndexChanged();

    void on_pushButton_clicked();

private:
    Ui::MainWindow4 *ui;
};

#endif // MAINWINDOW4_H
