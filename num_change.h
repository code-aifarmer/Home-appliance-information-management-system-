#ifndef NUM_CHANGE_H
#define NUM_CHANGE_H

#include <QMainWindow>

namespace Ui {
class Num_change;
}

class Num_change : public QMainWindow
{
    Q_OBJECT

public:
    explicit Num_change(QWidget *parent = nullptr);
    int isDigitStr(QString src);
    ~Num_change();

public:
    Ui::Num_change *ui;

private slots:
    void on_pushButton_clicked();
};
extern QString read_change_info;
#endif // NUM_CHANGE_H
