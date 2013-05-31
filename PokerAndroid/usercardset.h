#ifndef USERCARDSET_H
#define USERCARDSET_H

#include <QList>
#include "card.h"
#include "userinfo.h"

class UserCardSet
{
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

private:
    Card firstCard;
    Card secondCard;
    UserInfo user;
};

#endif // USERCARDSET_H
