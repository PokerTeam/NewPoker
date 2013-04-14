#ifndef COMMANDS_H
#define COMMANDS_H

#include <QObject>

class Commands
{
public:
    static const quint16 comAutchReq = 1;
    static const quint16 comRegAcc = 2;
    static const quint16 comResultLogin = 3;
    static const quint16 comResultReg = 4;
    static const quint16 comSendList = 5;
    static const quint16 registerNewUser = 6;
    static const quint16 loginUser = 7;
    static const quint16 loginResult = 8;
    static const quint16 joinGame = 9;
    static const quint16 gameStart = 10;
    static const quint16 userMove = 11;
    static const quint16 userAction = 12;
    static const quint16 bankChange = 13;

    Commands();
};

#endif // COMMANDS_H
