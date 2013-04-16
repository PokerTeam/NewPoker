#include "gamestartaction.h"

GameStartAction::GameStartAction(){
    this->bigBlind = UserInfo();
    this->smallBlind = UserInfo();
    this->userWithButton = UserInfo();
}

GameStartAction::GameStartAction(UserInfo smallBlind,
                                 UserInfo bigBlind,
                                 UserInfo userWithButton,
                                 QList<UserCardSet> cards)
{
    this->smallBlind = smallBlind;
    this->bigBlind = bigBlind;
    this->userWithButton = userWithButton;
    this->cards = cards;
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

QList<UserCardSet> GameStartAction::getCards(){
    return cards;
}

QDataStream &operator<<(QDataStream &out,
                        GameStartAction &action)
{
    out << action.bigBlind
        << action.smallBlind
        << action.userWithButton
        << qint32(action.cards.length());
    foreach(UserCardSet set, action.cards){
        out << set;
    }

    return out;
}

QDataStream &operator>>(QDataStream &in,
                        GameStartAction &action)
{
    qint32 length;
    in >> action.bigBlind
       >> action.smallBlind
       >> action.userWithButton
       >> length;
    for (qint32 i = 0; i < length; i++){
        UserCardSet set;
        in >> set;
        action.cards.push_back(set);
    }

    return in;
}
