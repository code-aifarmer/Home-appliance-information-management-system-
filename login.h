#ifndef LOGIN_H
#define LOGIN_H
#include <QButtonGroup>
#include <QDebug>
#include <QMainWindow>
#include <customerChannel.h>
#include <managerChannel.h>
#include <register.h>
#include <QSql>
#include <QSqlDatabase>

#define FILEPATH "E:/QT/project/01/"

QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QMainWindow
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();
    void back_to_main_mainwindow2();
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



public:
    Ui::Login *ui;
    CustomerChannel w;
    ManagerChannel w1;
    Register w4;
    QButtonGroup *groupButton1;
    QButtonGroup *groupButton2;
    //MainWindow *mainwindow;

};
extern QString now_username;
extern QString find_username;
#endif // LOGIN_H
