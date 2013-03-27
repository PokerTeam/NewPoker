#-------------------------------------------------
#
# Project created by QtCreator 2013-02-24T18:42:25
#
#-------------------------------------------------

QT       += core
QT += network
QT       -= gui

TARGET = Poker
CONFIG += qt
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    user.cpp \
    card.cpp \
    accountmanager.cpp \
    game.cpp \
    usercardset.cpp \
    deck.cpp \
    useraction.cpp \
    client.cpp \
    server.cpp \
    gamestartaction.cpp \
    userinfo.cpp \
    firstcardsaction.cpp \
    userleaveaction.cpp \
    bankchangeaction.cpp \
    usermoveaction.cpp \
    clientsocket.cpp \
    loginresult.cpp
HEADERS += \
    user.h \
    suit.h \
    card.h \
    accountmanager.h \
    game.h \
    usercardset.h \
    deck.h \
    actions.h \
    useraction.h \
    client.h \
    server.h \
    gamestartaction.h \
    userinfo.h \
    firstcardsaction.h \
    userleaveaction.h \
    bankchangeaction.h \
    usermoveaction.h \
    commands.h \
    clientsocket.h \
    loginresult.h
