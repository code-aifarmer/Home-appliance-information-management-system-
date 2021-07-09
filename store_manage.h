#ifndef STORE_MANAGE_H
#define STORE_MANAGE_H

#include <QMainWindow>
#include "store.h"
namespace Ui {
class Store_manage;
}

class Store_manage : public QMainWindow
{
    Q_OBJECT

public:
    explicit Store_manage(QWidget *parent = nullptr);
    ~Store_manage();
    Store s;

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Store_manage *ui;

};

#endif // STORE_MANAGE_H
