#ifndef AIR_CONDITIONER_H
#define AIR_CONDITIONER_H

#include <QMainWindow>
#include "fake_buy.h"
namespace Ui {
class Air_conditioner;
}

class Air_conditioner : public QMainWindow
{
    Q_OBJECT

public:
    explicit Air_conditioner(QWidget *parent = nullptr);
    ~Air_conditioner();

private slots:
    void on_pushButton_5_clicked();

    void on_pushButton_clicked();

private:
    Ui::Air_conditioner *ui;
    fake_buy x;
};

#endif // AIR_CONDITIONER_H
