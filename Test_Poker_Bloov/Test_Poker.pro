#-------------------------------------------------
#
# Project created by QtCreator 2013-05-14T22:28:53
#
#-------------------------------------------------

QT       += core
QT += network
QT += sql
QT       -= gui

TARGET = Test_Poker
CONFIG   += console
CONFIG   -= app_bundle
CONFIG += qtestlib

TEMPLATE = app


SOURCES += main.cpp \
    ../card.cpp \
    test_card.cpp

HEADERS += \
    ../card.h \
    ../card.h \
    test_card.h \
    ../suit.h
