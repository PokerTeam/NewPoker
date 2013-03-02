#ifndef USERACTION_H
#define USERACTION_H
#include <actions.h>
#include <user.h>
class UserAction
{
public:
    //We pass User class as argument because we need to verify password.
    UserAction(User *user, Actions action, int money = -1);
    Actions getAction();
    int getMoney();
    User* getUser();
private:
    User* user;
    Actions action;
    int money; //-1 if action is Fold or Check.
};

#endif // USERACTION_H
