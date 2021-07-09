#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QButtonGroup>
#include <QDebug>
#include <QMainWindow>
#include <mainwindow2.h>
#include <mainwindow3.h>
#include <mainwindow7.h>
#include <QSql>
#include <QSqlDatabase>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void back_to_main_mainwindow2();
    //void paintEvent(QPaintEvent *event);
    //static QString now_username;
//signals:
    //void signal_Test();
private slots:
    void on_pushButton_clicked();

    void on_label_linkActivated(const QString &link);

    void on_pushButton_2_clicked();
    //void closeAllWidgets();
    //void on_radioButton_2_clicked(bool checked);
    // void on_radioButton_clicked(bool checked);
    //void reshowMainwindow();





    void on_pushButton_3_clicked();

public:
    Ui::MainWindow *ui;
    MainWindow2 w;
    MainWindow3 w1;
    MainWindow7 w4;
    QButtonGroup *groupButton1;
    QButtonGroup *groupButton2;
    //MainWindow *mainwindow;

};
extern QString now_username;
extern QString find_username;
extern QString txt_path;

#endif // MAINWINDOW_H
