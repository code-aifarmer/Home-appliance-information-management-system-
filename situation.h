#ifndef SITUATION_H
#define SITUATION_H

#include <QMainWindow>

namespace Ui {
class Situation;
}

class Situation : public QMainWindow
{
    Q_OBJECT

public:
    explicit Situation(QWidget *parent = nullptr);
    ~Situation();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Situation *ui;
};

#endif // SITUATION_H
