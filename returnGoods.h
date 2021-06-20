#ifndef RETURNGOODS_H
#define RETURNGOODS_H

#include <QMainWindow>
#include "login.h"
#include "ui_login.h"
namespace Ui {
class ReturnGoods;
}

class ReturnGoods : public QMainWindow
{
    Q_OBJECT

public:
    explicit ReturnGoods(QWidget *parent = nullptr);
    ~ReturnGoods();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::ReturnGoods *ui;
    Login *p1;
};

#endif // RETURNGOODS_H
