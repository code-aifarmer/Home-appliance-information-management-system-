#ifndef STORE_H
#define STORE_H

#include <QMainWindow>
#include "QStandardItemModel"
#include "num_change.h"
namespace Ui {
class Store;
}

class Store : public QMainWindow
{
    Q_OBJECT

public:
    explicit Store(QWidget *parent = nullptr);
    ~Store();
public slots:
    //void contextMenuEvent(QContextMenuEvent *event); //右键默认槽
    //void actionClick();
private slots:
    //void on_tableView_customContextMenuRequested(QContextMenuEvent *event);
    void slotContextMenu(QPoint pos);
    void update_info();
    void del_info();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

public:
    Ui::Store *ui;
    QMenu *popMenu;
    QStandardItemModel *model = new QStandardItemModel();
    int selected_current_row;
    Num_change * get_change_info;
    QString real_value;


};
extern QString index1;
#endif // STORE_H
