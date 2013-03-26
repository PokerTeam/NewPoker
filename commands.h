#ifndef COMMANDS_H
#define COMMANDS_H

#include <QObject>

class Commands
{
public:
    static const quint16 registerNewUser = 1;
    static const quint16 loginUser = 2;
    static const quint16 loginResult = 3;
    static const quint16 joinGame = 4;

    Commands();
};

#endif // COMMANDS_H
