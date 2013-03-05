#include "user.h"

User::User(long userId, QString username, QString password, long money)
{
    this->userId = userId;
    this->username = username;
    this->password = password;
    this->money = money;
}
