#ifndef GAMESTARTACTION_H
#define GAMESTARTACTION_H

#include "userinfo.h"
#include "usercardset.h"

class GameStartAction
{
public:
    GameStartAction();//I hate QT.
    GameStartAction(UserInfo smallBlind, UserInfo bigBlind, UserInfo userWithButton, QList<UserCardSet> cards);
    UserInfo getUserWithButton();
    UserInfo getSmallBlind();
    UserInfo getBigBlind();
    QList<UserCardSet> getCards();

    friend QDataStream &operator<<(QDataStream &out, GameStartAction &action);
    friend QDataStream &operator>>(QDataStream &in, GameStartAction &action);

private:
    UserInfo smallBlind;
    UserInfo bigBlind;
    UserInfo userWithButton;
    QList<UserCardSet> cards;
};

#endif // GAMESTARTACTION_H
