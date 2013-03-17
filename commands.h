#ifndef COMMANDS_H
#define COMMANDS_H
#include <QObject>
class Commands
{

public:
    static const quint8 comAutchReq = 1;
    static const quint8 comRegAcc = 2;
    static const quint8 comResultLogin = 3;
    static const quint8 comResultReg = 4;
    static const quint8 comSendList = 5;

    Commands();
};

#endif // COMMANDS_H
