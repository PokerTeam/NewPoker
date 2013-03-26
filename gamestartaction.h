#ifndef GAMESTARTACTION_H
#define GAMESTARTACTION_H

#include "userinfo.h"

class GameStartAction
{
public:
    GameStartAction(UserInfo* smallBlind, UserInfo* bigBlind, UserInfo* userWithButton);
    UserInfo* getUserWithButton();
    UserInfo* getSmallBlind();
    UserInfo* getBigBlind();

private:
    UserInfo* smallBlind;
    UserInfo* bigBlind;
    UserInfo* userWithButton;
};

#endif // GAMESTARTACTION_H
