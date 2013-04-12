#include "gamestartaction.h"

GameStartAction::GameStartAction(UserInfo smallBlind,
                                 UserInfo bigBlind,
                                 UserInfo userWithButton)
{
    this->smallBlind = smallBlind;
    this->bigBlind = bigBlind;
    this->userWithButton = userWithButton;
}

UserInfo GameStartAction::getUserWithButton()
{
    return userWithButton;
}

UserInfo GameStartAction::getSmallBlind()
{
    return smallBlind;
}

UserInfo GameStartAction::getBigBlind()
{
    return bigBlind;
}
