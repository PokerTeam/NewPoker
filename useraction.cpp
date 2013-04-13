#include "useraction.h"

UserAction::UserAction(UserInfo user,
                       Actions action,
                       int money)
{
    this->user = user;
    this->action = action;
    this->money = money;
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
