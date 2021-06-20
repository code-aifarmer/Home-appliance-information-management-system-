#ifndef CUSTOMERSERVICE_H
#define CUSTOMERSERVICE_H

#include <QMainWindow>
#include <QUrl>
#include  <QtNetwork>
#include  <QNetworkAccessManager>
namespace Ui {
class CustomerService;
}

class CustomerService : public QMainWindow
{
    Q_OBJECT

public:
    explicit CustomerService(QWidget *parent = nullptr);
    ~CustomerService();
public slots:
     void Tuling_replyFinish(QNetworkReply* reply);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::CustomerService *ui;
    QString tuling_get_ans;
    QString voice_get_ans;
    QString UI_ANS_String;
};

#endif // CUSTOMERSERVICE_H
