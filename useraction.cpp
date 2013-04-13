#include "useraction.h"

UserAction::UserAction(UserInfo user,
                       Actions action,
                       int money)
{
    this->user = user;
    this->action = action;
    this->money = money;
}

UserAction::UserAction()
{
    this->user = UserInfo();
    this->action = FOLD;
    this->money = 0;
}

Actions UserAction::getAction()
{
    return action;
}

int UserAction::getMoney()
{
    return money;
}

UserInfo UserAction::getUser()
{
    return user;
}

QDataStream &operator<<(QDataStream &out,UserAction &action)
{
    out << quint32(action.money)
        << quint32(action.action)
        << action.user;
    return out;
}

QDataStream &operator>>(QDataStream &in, UserAction &action)
{
    quint32 money;
    quint32 act;
    UserInfo user;
    in >> money >> act >> user;
    action.action = (Actions)act;
    action.user = user;
    action.money = money;
    return in;
}
