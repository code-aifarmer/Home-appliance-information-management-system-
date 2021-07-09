#ifndef ADD_GOODS_H
#define ADD_GOODS_H

#include <QMainWindow>

namespace Ui {
class Add_goods;
}

class Add_goods : public QMainWindow
{
    Q_OBJECT

public:
    explicit Add_goods(QWidget *parent = nullptr);
    int isDigitStr(QString src);
    ~Add_goods();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Add_goods *ui;
};

#endif // ADD_GOODS_H
