#include "usercardset.h"

UserCardSet::UserCardSet(UserInfo user,
                         Card firstCard,
                         Card secondCard)
{
    this->user = user;
    this->firstCard = firstCard;
    this->secondCard = secondCard;
}

Card UserCardSet::getFirstCard()
{
    return firstCard;
}

Card UserCardSet::getSecondCard()
{
    return secondCard;
}

UserInfo UserCardSet::getUser()
{
    return user;
}
