QT       +=sql
QT       +=network
QT       += core gui multimedia
QT       +=script
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    add_goods.cpp \
    air_conditioner.cpp \
    audio.cpp \
    choose_goods.cpp \
    display.cpp \
    fake_buy.cpp \
    http.cpp \
    main.cpp \
    mainwindow.cpp \
    mainwindow10.cpp \
    mainwindow11.cpp \
    mainwindow12.cpp \
    mainwindow13.cpp \
    mainwindow14.cpp \
    mainwindow15.cpp \
    mainwindow2.cpp \
    mainwindow3.cpp \
    mainwindow4.cpp \
    mainwindow5.cpp \
    mainwindow6.cpp \
    mainwindow7.cpp \
    mainwindow8.cpp \
    mainwindow9.cpp \
    num_change.cpp \
    speech.cpp \
    store.cpp \
    store_manage.cpp \
    widget.cpp

HEADERS += \
    add_goods.h \
    air_conditioner.h \
    audio.h \
    choose_goods.h \
    display.h \
    fake_buy.h \
    http.h \
    mainwindow.h \
    mainwindow10.h \
    mainwindow11.h \
    mainwindow12.h \
    mainwindow13.h \
    mainwindow14.h \
    mainwindow15.h \
    mainwindow2.h \
    mainwindow3.h \
    mainwindow4.h \
    mainwindow5.h \
    mainwindow6.h \
    mainwindow7.h \
    mainwindow8.h \
    mainwindow9.h \
    num_change.h \
    speech.h \
    store.h \
    store_manage.h \
    widget.h

FORMS += \
    add_goods.ui \
    air_conditioner.ui \
    choose_goods.ui \
    display.ui \
    fake_buy.ui \
    mainwindow.ui \
    mainwindow10.ui \
    mainwindow11.ui \
    mainwindow12.ui \
    mainwindow13.ui \
    mainwindow14.ui \
    mainwindow15.ui \
    mainwindow2.ui \
    mainwindow3.ui \
    mainwindow4.ui \
    mainwindow5.ui \
    mainwindow6.ui \
    mainwindow7.ui \
    mainwindow8.ui \
    mainwindow9.ui \
    num_change.ui \
    store.ui \
    store_manage.ui \
    widget.ui

TRANSLATIONS += \
    01_zh_CN.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    ../image.qrc \
    qss.qrc
