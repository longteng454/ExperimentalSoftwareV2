#-------------------------------------------------
#
# Project created by QtCreator 2016-09-07T17:32:11
#
#-------------------------------------------------

QT       += core gui

QT       += serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MeasureQT
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    triopc.cpp

HEADERS  += widget.h \
    triopc.h

FORMS    += widget.ui
