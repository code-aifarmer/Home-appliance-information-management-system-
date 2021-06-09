#ifndef MAINWINDOW8_H
#define MAINWINDOW8_H

#include <QMainWindow>
#include <QUrl>
#include  <QtNetwork>
#include  <QNetworkAccessManager>
namespace Ui {
class MainWindow8;
}

class MainWindow8 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow8(QWidget *parent = nullptr);
    ~MainWindow8();
public slots:
     void Tuling_replyFinish(QNetworkReply* reply);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow8 *ui;
    QString tuling_get_ans;
    QString voice_get_ans;
    QString UI_ANS_String;
};

#endif // MAINWINDOW8_H
