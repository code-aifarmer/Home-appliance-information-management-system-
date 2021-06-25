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
extern MainWindow *main_window;
QString now_username;
QString find_username;
int main(int argc, char *argv[])
{





 //setAttribute(Qt::WA_TranslucentBackground, true );

 //   MainWindow *main_window = new MainWindow;
    QApplication a(argc, argv);

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
