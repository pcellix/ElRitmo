#-------------------------------------------------
#
# Project created by QtCreator 2015-10-13T14:34:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets webkitwidgets

TARGET = ElRitmo
TEMPLATE = app


SOURCES += main.cpp\
    partyinfo.cpp \
    mainpartywidget.cpp \
    mainwindow.cpp \
    jsonparser.cpp

HEADERS  += mainwindow.h \
    partyinfo.h \
    mainpartywidget.h \
    jsonparser.h
