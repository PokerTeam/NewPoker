#ifndef USERCARDSET_H
#define USERCARDSET_H
#include "card.h"
#include "user.h"
#include <QList>

class UserCardSet
{
public:
    UserCardSet(User *user, Card* firstCard, Card* secondCard);
    Card* getFirstCard(){ return firstCard; }
    Card* getSecondCard(){ return secondCard; }
    User* getUser(){ return user; }
private:
    Card* firstCard;
    Card* secondCard;
    User* user;
};

#endif // USERCARDSET_H
