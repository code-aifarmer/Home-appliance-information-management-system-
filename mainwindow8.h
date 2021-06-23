#ifndef MAINWINDOW8_H
#define MAINWINDOW8_H

#include<QtNetwork>

#include <QMainWindow>
#include <QUrl>
#include  <QtNetwork>
#include  <QNetworkAccessManager>
#include "mainwindow14.h"
namespace Ui {
class MainWindow8;
}

class MainWindow8 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow8(QWidget *parent = nullptr);
    // void getText(QString para_API_id, QString para_API_access_token,QString para_API_language, QString para_API_record_path);
    ~MainWindow8();
public slots:
     void Tuling_replyFinish(QNetworkReply* reply);
private slots:
    void on_pushButton_clicked();
    //void replyFinish(QNetworkReply *);
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

public:
    Ui::MainWindow8 *ui;
    QString tuling_get_ans;
    QString voice_get_ans;
    QString UI_ANS_String;
    MainWindow14 o;

};

#endif // MAINWINDOW8_H
