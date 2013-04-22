#-------------------------------------------------
#
# Project created by QtCreator 2013-02-24T18:42:25
#
#-------------------------------------------------

QT       += core
QT += network
QT       -= gui
QT += sql

TARGET = Poker
CONFIG += qt
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    winner.cpp \
    usermoveaction.cpp \
    userleaveaction.cpp \
    userinfo.cpp \
    usercombination.cpp \
    usercardset.cpp \
    useraction.cpp \
    user.cpp \
    server.cpp \
    loginresult.cpp \
    gamestartaction.cpp \
    gameaction.cpp \
    game.cpp \
    firstcardsaction.cpp \
    deck.cpp \
    clientsocket.cpp \
    client.cpp \
    card.cpp \
    bankchangeaction.cpp \
    accountmanager.cpp \
    gamefinish.cpp

HEADERS += \
    winner.h \
    usermoveaction.h \
    userleaveaction.h \
    userinfo.h \
    usercombination.h \
    usercardset.h \
    useraction.h \
    user.h \
    suit.h \
    server.h \
    loginresult.h \
    gamestartaction.h \
    gameaction.h \
    game.h \
    firstcardsaction.h \
    deck.h \
    commands.h \
    combination.h \
    clientsocket.h \
    client.h \
    card.h \
    bankchangeaction.h \
    actions.h \
    accountmanager.h \
    gamefinish.h
