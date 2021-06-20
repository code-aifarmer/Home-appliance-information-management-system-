#ifndef MANAGERCHANNEL_H
#define MANAGERCHANNEL_H
#include "situation.h"
#include <QMainWindow>
#include "QStringListModel"
namespace Ui {
class ManagerChannel;
}

class ManagerChannel : public QMainWindow
{
    Q_OBJECT

public:
    explicit ManagerChannel(QWidget *parent = nullptr);
    ~ManagerChannel();

private slots:
    void on_pushButton_5_clicked();

   // void on_listView_indexesMoved(const QModelIndexList &indexes);

    void on_pushButton_clicked();

private:
    Ui::ManagerChannel *ui;
    QStringListModel *theModel;
    Situation m11;
};

#endif // MANAGERCHANNEL_H
