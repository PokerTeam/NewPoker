#include "user.h"

User::User(long userId,
           QString username,
           QString password,
           long money)
{
    this->userId = userId;
    this->username = username;
    this->password = password;
    this->money = money;
}

User::User(QString username, QString password, long money)
{
    this->username = username;
    this->password = password;
    this->money = money;
}

long User::getUserId()
{
    return this->userId;
}

QString User::getUsername()
{
    return this->username;
}

QString User::getPassword()
{
    return this->password;
}

long User::getMoney()
{
    return money;
}

long User::setMoney(long newValue)
{
    money = newValue;
    return money;
}

