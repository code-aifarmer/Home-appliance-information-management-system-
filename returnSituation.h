#ifndef RETURNSITUATION_H
#define RETURNSITUATION_H

#include <QMainWindow>
#include "QStringListModel"
namespace Ui {
class ReturnSituation;
}

class ReturnSituation : public QMainWindow
{
    Q_OBJECT

public:
    explicit ReturnSituation(QWidget *parent = nullptr);
    ~ReturnSituation();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::ReturnSituation *ui;
    QStringListModel *theModel;
};

#endif // RETURNSITUATION_H
