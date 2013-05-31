#ifndef USERCARDSET_H
#define USERCARDSET_H

#include <QList>

#include "card.h"
#include "userinfo.h"

class UserCardSet
{
private:
    Card firstCard;
    Card secondCard;
    UserInfo user;

public:
    UserCardSet() { firstCard = Card(); secondCard = Card(); user = UserInfo(); }
    UserCardSet(UserInfo user,
                Card firstCard,
                Card secondCard);
    Card getFirstCard();
    Card getSecondCard();
    UserInfo getUser();

    friend QDataStream &operator<<(QDataStream &out,UserCardSet &set);
    friend QDataStream &operator>>(QDataStream &in, UserCardSet &set);
};

#endif // USERCARDSET_H
