#ifndef USERACTION_H
#define USERACTION_H

#include "actions.h"
#include "userinfo.h"

class UserAction
{
public:
        //We pass User class as argument because we need to verify password.
    UserAction(UserInfo user, Actions action, int money = -1);
    Actions getAction();
    int getMoney();
    UserInfo getUser();

private:
    UserInfo user;
    Actions action;
        //-1 if action is Fold or Check.
    int money;
};

#endif // USERACTION_H
