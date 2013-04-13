#ifndef GAMESTARTACTION_H
#define GAMESTARTACTION_H

#include "userinfo.h"

class GameStartAction
{
public:
    GameStartAction();//I hate QT.
    GameStartAction(UserInfo smallBlind, UserInfo bigBlind, UserInfo userWithButton);
    UserInfo getUserWithButton();
    UserInfo getSmallBlind();
    UserInfo getBigBlind();

    friend QDataStream &operator<<(QDataStream &out, GameStartAction &action);
    friend QDataStream &operator>>(QDataStream &in, GameStartAction &action);
private:
    UserInfo smallBlind;
    UserInfo bigBlind;
    UserInfo userWithButton;
};

#endif // GAMESTARTACTION_H
