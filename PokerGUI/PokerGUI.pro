#-------------------------------------------------
#
# Project created by QtCreator 2013-03-02T17:03:27
#
#-------------------------------------------------

QT       += core gui network

TARGET = PokerGUI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    client.cpp \
    ../userinfo.cpp \
    ../user.cpp \
    ../loginresult.cpp

HEADERS  += mainwindow.h \
    client.h \
    ../loginresult.h \
    ../commands.h \
    ../userinfo.h \
    ../user.h
