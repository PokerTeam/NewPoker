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

QDataStream &operator<<(QDataStream &out,
                        UserCardSet &set)
{
    out << set.firstCard
        << set.secondCard
        << set.user;

    return out;
}

QDataStream &operator>>(QDataStream &in,
                        UserCardSet &set)
{
    in >> set.firstCard
       >> set.secondCard
       >> set.user;

    return in;
}
