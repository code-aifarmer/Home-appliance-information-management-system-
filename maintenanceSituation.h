#ifndef MAINTENANCESITUATION_H
#define MAINTENANCESITUATION_H

#include <QMainWindow>
#include "QStringListModel"
namespace Ui {
class MaintenanceSituation;
}

class MaintenanceSituation : public QMainWindow
{
    Q_OBJECT

public:
    explicit MaintenanceSituation(QWidget *parent = nullptr);
    ~MaintenanceSituation();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MaintenanceSituation *ui;
    QStringListModel *theModel;
};

#endif // MAINTENANCESITUATION_H
