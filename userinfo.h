#ifndef USERINFO_H
#define USERINFO_H
#include "user.h"
class UserInfo
{
public:
    UserInfo(User* user, long usersMoneyOnTable = 0);
    UserInfo(long userId, long userMoney, long userMoneyOnTable);
    bool isAllIn(); //If money on table <> 0 and userMoney = 0
private:
    void init(long userId, long userMoney, long userMoneyOnTable);
    long userId;
    long userMoney;
    long userMoneyOnTable;
};

#endif // USERINFO_H
