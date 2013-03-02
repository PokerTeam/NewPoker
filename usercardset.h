#ifndef USERCARDSET_H
#define USERCARDSET_H
#include "card.h"
#include "user.h"
#include <QList>

class UserCardSet
{
public:
    UserCardSet(User *user, Card* firstCard, Card* secondCard);
    Card* getFirstCard();
    Card* getSecondCard();
    User* getUser();
private:
    Card* firstCard;
    Card* secondCard;
    User* user;
};

#endif // USERCARDSET_H
