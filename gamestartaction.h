#ifndef GAMESTARTACTION_H
#define GAMESTARTACTION_H

#include "userinfo.h"
#include "usercardset.h"

class GameStartAction
{    
private:
    UserInfo smallBlind;
    UserInfo bigBlind;
    UserInfo userWithButton;
    QList<UserCardSet> cards;

public:
    GameStartAction();
    GameStartAction(UserInfo smallBlind, UserInfo bigBlind, UserInfo userWithButton, QList<UserCardSet> cards);
    UserInfo getUserWithButton();
    UserInfo getSmallBlind();
    UserInfo getBigBlind();
    QList<UserCardSet> getCards();

    friend QDataStream &operator<<(QDataStream &out, GameStartAction &action);
    friend QDataStream &operator>>(QDataStream &in, GameStartAction &action);
};

#endif // GAMESTARTACTION_H
