#ifndef MESSAGEBOARD_H
#define MESSAGEBOARD_H

#include <QMainWindow>
#include "comment.h"
#include "ui_messageBoard.h"
namespace Ui {
class MessageBoard;
}

class MessageBoard : public QMainWindow
{
    Q_OBJECT

public:
    explicit MessageBoard(QWidget *parent = nullptr);
    ~MessageBoard();
    //void sendData(QString data);

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MessageBoard *ui;
    Comment *k;
};

#endif // MESSAGEBOARD_H
