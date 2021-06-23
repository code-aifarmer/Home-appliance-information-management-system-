#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QtNetwork>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    void getText(QString para_API_id, QString para_API_access_token,QString para_API_language, QString para_API_record_path);
    ~Widget();

private slots:
    void replyFinish(QNetworkReply *);

    void on_pushButton_clicked();

private:
    Ui::Widget *ui;

    QNetworkAccessManager *manager;
    QNetworkRequest *req;
    QString API_access_token;
    QString API_id;
    QString API_key;
    QString API_secret_key;
    QString API_record_path;
    //QString  API_record_format;
   // QString API_record_HZ;
    QString API_language;
    char * m_buf;
    int flag;

};

#endif // WIDGET_H
