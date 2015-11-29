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
    level.cpp

HEADERS  += mainwindow.h \
    openglwidget.h \
    gameplay.h \
    number.h \
    level.h

FORMS    += \
    mainwindow.ui
