#ifndef USERMOVEACTION_H
#define USERMOVEACTION_H
#include "actions.h"
#include "userinfo.h"
#include <QList>
class UserMoveAction
{
public:
    UserMoveAction(UserInfo* user, QList<Actions> availableActions, long minimumBid);
    UserInfo* getUserInfo();
    long getMinimumBid();
    QList<Actions> getAvailableActions();
private:
    UserInfo* user;
    QList<Actions> availableActions;
    long minimumBid;
};

#endif // USERMOVEACTION_H
