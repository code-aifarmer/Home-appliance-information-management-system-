#ifndef COMMENT_H
#define COMMENT_H

#include <QMainWindow>

namespace Ui {
class Comment;
}

class Comment : public QMainWindow
{
    Q_OBJECT

public:
    explicit Comment(QWidget *parent = nullptr);
    ~Comment();
    //void sendData(QString data);
public slots:
    void show_comment();
private slots:
    void on_pushButton_clicked();

public:
    Ui::Comment *ui;
};

#endif // COMMENT_H
