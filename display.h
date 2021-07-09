#ifndef DISPLAY_H
#define DISPLAY_H

#include <QMainWindow>

namespace Ui {
class Display;
}

class Display : public QMainWindow
{
    Q_OBJECT

public:
    explicit Display(QWidget *parent = nullptr);
    ~Display();

private slots:
    void on_pushButton_5_clicked();

private:
    Ui::Display *ui;
};

#endif // DISPLAY_H
