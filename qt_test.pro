#-------------------------------------------------
#
# Project created by QtCreator 2017-11-20T09:59:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qt_test
TEMPLATE = app

#LIBS=-lrt

SOURCES += main.cpp\
        mainwindow.cpp \
    welcome/welcome.cpp \
    chooce/chooce.cpp \
    work/work.cpp \
    stat_show/stat_show.cpp \
    confige/confige.cpp \
    motor_debug/motor_debug.cpp \
    motor_y_debug/motot_y_debug.cpp \
    diancifa/diancifa.cpp \
    numpad/numpad.cpp \
    my_lineedit/my_lineedit.cpp \
    load/load_debug.cpp \
    includes.cpp \
    load/psword_change.cpp \
    confige/config_manage.cpp \

HEADERS  += mainwindow.h \
    welcome/welcome.h \
    chooce/chooce.h \
    work/work.h \
    stat_show/stat_show.h \
    confige/confige.h \
    motor_debug/motor_debug.h \
    motor_y_debug/motot_y_debug.h \
    diancifa/diancifa.h \
    numpad/numpad.h \
    my_lineedit/my_lineedit.h \
    includes.h \
    load/load_debug.h \
    load/psword_change.h \
    confige/config_manage.h \

FORMS    += \
    welcome/welcome.ui \
    chooce/chooce.ui \
    work/work.ui \
    stat_show/stat_show.ui \
    confige/confige.ui \
    motor_debug/motor_debug.ui \
    motor_y_debug/motot_y_debug.ui \
    diancifa/diancifa.ui \
    numpad/numpad.ui \

RESOURCES += \
    image.qrc
