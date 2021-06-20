#ifndef MAINTENANCEINQUIRY_H
#define MAINTENANCEINQUIRY_H

#include <QMainWindow>
#include <messageBoard.h>
#include "QStringListModel"
namespace Ui {
class MaintenanceInquiry;
}

class MaintenanceInquiry : public QMainWindow
{
    Q_OBJECT

public:
    explicit MaintenanceInquiry(QWidget *parent = nullptr);
    ~MaintenanceInquiry();
public slots:
    void ask_result();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MaintenanceInquiry *ui;
    MessageBoard w4;
    QStringListModel *theModel;
};

#endif // MAINTENANCEINQUIRY_H
