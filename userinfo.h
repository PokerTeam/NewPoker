#ifndef USERINFO_H
#define USERINFO_H

#include <QDataStream>
#include "user.h"

class UserInfo
{
public:
    UserInfo(User* user, long usersMoneyOnTable = 0);
    UserInfo(long userId, long userMoney, long userMoneyOnTable);
        //If money on table <> 0 and userMoney = 0
    bool isAllIn();
    void putOnTable(long value);
    long getUserId();
    long getUserMoney();
    long getUserMoneyOnTable();
    void clearMoneyOnTable();

private:
    long userId;
    long userMoney;
    long userMoneyOnTable;

    void init(long userId, long userMoney, long userMoneyOnTable);    
};

QDataStream &operator<<(QDataStream &out, UserInfo *&info);
QDataStream &operator>>(QDataStream &in, UserInfo *&info);

#endif // USERINFO_H
