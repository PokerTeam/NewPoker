#include "usermoveaction.h"

UserMoveAction::UserMoveAction(UserInfo user,
                               QList<Actions> availableActions,
                               long minimumBid)
{
    this->user = user;
    this->availableActions = availableActions;
    this->minimumBid = minimumBid;
}

UserMoveAction::UserMoveAction()
{
    this->user = UserInfo();
    this->availableActions = QList<Actions>();
    this->minimumBid = 0;
}

UserInfo UserMoveAction::getUserInfo()
{
    return user;
}

long UserMoveAction::getMinimumBid()
{
    return minimumBid;
}

QList<Actions> UserMoveAction::getAvailableActions()
{
    return availableActions;
}

QDataStream &operator<<(QDataStream &out,
                        UserMoveAction &action)
{
    out << action.user
        << qint64(action.minimumBid)
        << action.availableActions.length();
    foreach(Actions item, action.availableActions){
        out << qint64(item);
    }

    return out;
}

QDataStream &operator>>(QDataStream &in,
                        UserMoveAction &action)
{
    int length = 0;
    qint64 bid = 0;
    in >> action.user
       >> bid
       >> length;
    action.minimumBid = bid;
    for (int i = 0; i < length; i++){
        Actions item;
        qint64 it;
        in >> it;
        action.availableActions.push_back((Actions)it);
    }
    return in;
}
