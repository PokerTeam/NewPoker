#include "gamestartaction.h"

GameStartAction::GameStartAction(){
    this->bigBlind = UserInfo();
    this->smallBlind = UserInfo();
    this->userWithButton = UserInfo();
}

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

QDataStream &operator<<(QDataStream &out,
                        GameStartAction &action)
{
    out << action.bigBlind
        << action.smallBlind
        << action.userWithButton;
    return out;
}

QDataStream &operator>>(QDataStream &in,
                        GameStartAction &action)
{
    in >> action.bigBlind
       >> action.smallBlind
       >> action.userWithButton;
    return in;
}
