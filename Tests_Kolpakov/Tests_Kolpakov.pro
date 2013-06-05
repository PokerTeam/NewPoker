#-------------------------------------------------
#
# Project created by QtCreator 2013-06-05T23:34:17
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_user_test
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += tst_user_test.cpp \
    ../user.cpp \
    ../userinfo.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
    ../user.h \
    ../userinfo.h
