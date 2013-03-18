#ifndef USERINFO_H
#define USERINFO_H
#include "user.h"
#include <QDataStream>
class UserInfo
{
public:
    UserInfo(User* user, long usersMoneyOnTable = 0);
    UserInfo(long userId, long userMoney, long userMoneyOnTable);
    bool isAllIn(); //If money on table <> 0 and userMoney = 0
    void putOnTable(long value);
    long getUserId();
    long getUserMoney();
    long getUserMoneyOnTable();
    void clearMoneyOnTable();
private:
    void init(long userId, long userMoney, long userMoneyOnTable);
    long userId;
    long userMoney;
    long userMoneyOnTable;
};

QDataStream &operator<<(QDataStream &out, UserInfo *&info);
QDataStream &operator>>(QDataStream &in, UserInfo *&info);

#endif // USERINFO_H
