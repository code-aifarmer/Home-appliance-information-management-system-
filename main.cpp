#include "mainwindow.h"
#include <QFile>
#include <QApplication>
#include <QLocale>
#include <QTranslator>

#include <QDebug>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QtDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <Qimage>
#pragma execution_character_set("utf-8")
extern MainWindow *main_window;
QString now_username;
QString find_username;
QString yanzheng;
QString rmail;
QString txt_path = "C:/Users/12234/Documents";
QString read_change_info;
QString index1;
//QString pic_path = "";
//QString back_ground_image_path= "C:/Users/12234/Documents/01/9.jpg";
int main(int argc, char *argv[])
{
/*
    //QApplication::addLibraryPath("./plugins");
    QSqlDatabase db =QSqlDatabase::addDatabase("QMYSQL");

    //连接数据库

    db.setHostName("127.0.0.1");

    db.setUserName("root");

    db.setPassword("ljq1223419806");

    db.setDatabaseName("fchomework");//使用的数据库

    //打开数据库

    if(!db.open())

    {

    QMessageBox::warning(NULL,"错误",db.lastError().text());

    return 0;

    }
*/

 //setAttribute(Qt::WA_TranslucentBackground, true );

 //   MainWindow *main_window = new MainWindow;
    QApplication a(argc, argv);
    QTextCodec *codec=QTextCodec::codecForName("utf-8");
    QTextCodec::setCodecForLocale(codec);

    //main_window->show();
    //main_window->show();
    QFile qss(":/Dark1.qss");
    if(qss.open(QFile::ReadOnly))
    {
        qDebug("open success");
        QString style = QLatin1String(qss.readAll());
        a.setStyleSheet(style);
        qss.close();
    }
    else
    {
        qDebug("Open failed");
    }
    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "01_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    MainWindow w;
    w.show();
    return a.exec();
}
