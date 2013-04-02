#ifndef USERINFO_H
#define USERINFO_H

#include <QDataStream>
#include "user.h"

class UserInfo
{
public:
    UserInfo(){ userId = 0; userMoney = 0; userMoneyOnTable = 0;}
    UserInfo(User* user, long usersMoneyOnTable = 0);
    UserInfo(long userId, long userMoney, long userMoneyOnTable);
        //If money on table <> 0 and userMoney = 0
    bool isAllIn();
    void putOnTable(long value);
    long getUserId();
    long getUserMoney();
    long getUserMoneyOnTable();
    void clearMoneyOnTable();

    friend QDataStream &operator<<(QDataStream &out, UserInfo &info);
    friend QDataStream &operator>>(QDataStream &in, UserInfo &info);

private:
    long userId;
    long userMoney;
    long userMoneyOnTable;

    void init(long userId, long userMoney, long userMoneyOnTable);    
};


#endif // USERINFO_H
