#ifndef MAINTENANCE_H
#define MAINTENANCE_H

#include <QMainWindow>

namespace Ui {
class Maintenance;
}

class Maintenance : public QMainWindow
{
    Q_OBJECT

public:
    explicit Maintenance(QWidget *parent = nullptr);
    ~Maintenance();

private slots:
    void on_comboBox_currentIndexChanged();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Maintenance *ui;
};

#endif // MAINTENANCE_H
