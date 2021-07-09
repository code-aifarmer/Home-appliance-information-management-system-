#ifndef FAKE_BUY_H
#define FAKE_BUY_H

#include <QMainWindow>

namespace Ui {
class fake_buy;
}

class fake_buy : public QMainWindow
{
    Q_OBJECT

public:
    explicit fake_buy(QWidget *parent = nullptr);
    void show_num();
    ~fake_buy();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::fake_buy *ui;

};

#endif // FAKE_BUY_H
