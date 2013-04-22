#-------------------------------------------------
#
# Project created by QtCreator 2013-03-02T17:03:27
#
#-------------------------------------------------

QT       += core gui
QT       += core gui declarative
QT       += core gui network

TARGET = PokerGUI
TEMPLATE = app

SOURCES += main.cpp\
    mainwindow.cpp \
    client.cpp \
    ../userinfo.cpp \
    ../user.cpp \
    ../loginresult.cpp \
    ../gamestartaction.cpp \
    ../usermoveaction.cpp \
    ../useraction.cpp \
    ../bankchangeaction.cpp \
    ../firstcardsaction.cpp \
    ../card.cpp \
    ../usercardset.cpp \
    ../gamefinish.cpp

HEADERS  += mainwindow.h \
    client.h \
    ../loginresult.h \
    ../commands.h \
    ../userinfo.h \
    ../user.h \
    ../gamestartaction.h \
    ../usermoveaction.h \
    ../useraction.h \
    ../bankchangeaction.h \
    ../firstcardsaction.h \
    ../card.h \
    ../suit.h \
    ../usercardset.h \
    ../gamefinish.h

OTHER_FILES += \
    login.qml \
    game.qml \
    Button.qml \
    TextArea.qml \
    CardImage.qml \
    UserBlock.qml

RESOURCES += \
    resources.qrc
