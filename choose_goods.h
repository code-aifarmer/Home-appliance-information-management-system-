#ifndef CHOOSE_GOODS_H
#define CHOOSE_GOODS_H

#include <QMainWindow>

namespace Ui {
class Choose_goods;
}

class Choose_goods : public QMainWindow
{
    Q_OBJECT

public:
    explicit Choose_goods(QWidget *parent = nullptr);
    ~Choose_goods();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Choose_goods *ui;
};

#endif // CHOOSE_GOODS_H
