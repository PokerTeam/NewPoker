#ifndef USERINFO_H
#define USERINFO_H

#include <QDataStream>
#include "user.h"

class UserInfo
{
public:
    UserInfo(){ username = ""; userId = 0; userMoney = 0; userMoneyOnTable = 0;}
    UserInfo(QString username, long userId, long userMoney, long userMoneyOnTable);
        //If money on table <> 0 and userMoney = 0
    bool isAllIn();
    void putOnTable(long value);
    long getUserId();
    QString getUsername();
    long getUserMoney();
    long getUserMoneyOnTable();
    void clearMoneyOnTable();

    friend QDataStream &operator<<(QDataStream &out,UserInfo &info);
    friend QDataStream &operator>>(QDataStream &in, UserInfo &info);

private:
    QString username;
    long userId;
    long userMoney;
    long userMoneyOnTable;

    void init(QString username, long userId, long userMoney, long userMoneyOnTable);
};


#endif // USERINFO_H
