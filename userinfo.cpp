#include "userinfo.h"

UserInfo::UserInfo(User* user, long userMoneyOnTable)
{
    init(user->getUserId(), user->getMoney(), userMoneyOnTable);
}

UserInfo::UserInfo(long userId,
                   long userMoney,
                   long userMoneyOnTable)
{
    init(userId, userMoney, userMoneyOnTable);
}

void UserInfo::init(long userId,
                    long userMoney,
                    long userMoneyOnTable)
{
    this->userId = userId;
    this->userMoney = userMoney;
    this->userMoneyOnTable = userMoneyOnTable;
}

bool UserInfo::isAllIn()
{
    return (userMoneyOnTable != 0) && (userMoney == 0);
}

void UserInfo::clearMoneyOnTable()
{
    userMoneyOnTable = 0;
}

void UserInfo::putOnTable(long value)
{
    userMoney = userMoney - value;
    if (userMoney < 0)
    {
        userMoney = 0;
    }
    userMoneyOnTable += value;
}

long UserInfo::getUserId()
{
    return userId;
}

long UserInfo::getUserMoney()
{
    return userMoney;
}

long UserInfo::getUserMoneyOnTable()
{
    return userMoneyOnTable;
}

QDataStream &operator<<(QDataStream &out, UserInfo *&info)
{
    out << quint32(info->getUserId())
        << quint32(info->getUserMoney())
        << quint32(info->getUserMoneyOnTable());
    return out;
}

QDataStream &operator>>(QDataStream &in, UserInfo *&info)
{
    quint32 userId;
    quint32 money;
    quint32 moneyOnTable;
    in >> userId >> money >> moneyOnTable;
    info = new UserInfo(userId, money, moneyOnTable);
    return in;
}
