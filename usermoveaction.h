#ifndef USERMOVEACTION_H
#define USERMOVEACTION_H

#include <QList>

#include "actions.h"
#include "userinfo.h"

class UserMoveAction
{
private:
    UserInfo user;
    QList<Actions> availableActions;
    long minimumBid;

public:
    UserMoveAction();
    UserMoveAction(UserInfo user,
                   QList<Actions> availableActions,
                   long minimumBid);
    UserInfo getUserInfo();
    long getMinimumBid();
    QList<Actions> getAvailableActions();

    friend QDataStream &operator<<(QDataStream &out, UserMoveAction &action);
    friend QDataStream &operator>>(QDataStream &in, UserMoveAction &action);
};

#endif // USERMOVEACTION_H
