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

    Commands();
};

#endif // COMMANDS_H
