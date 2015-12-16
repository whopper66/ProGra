QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProGra
TEMPLATE = app
CONFIG += c++11

SOURCES += main.cpp\
    mainwindow.cpp \
    openglwidget.cpp \
    gameplay.cpp \
    number.cpp \
    level.cpp \
    Levels/level1.cpp \
    Levels/level2.cpp \
    Levels/level3.cpp

HEADERS  += mainwindow.h \
    openglwidget.h \
    gameplay.h \
    number.h \
    level.h \
    Levels/level1.h \
    style.h \
    Levels/level2.h \
    Levels/level3.h

FORMS    += \
    mainwindow.ui

DISTFILES +=

RESOURCES += \
    resources.qrc
