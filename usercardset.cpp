#include "usercardset.h"

UserCardSet::UserCardSet(User *user, Card* firstCard, Card* secondCard)
{
    this->user = user;
    this->firstCard = firstCard;
    this->secondCard = secondCard;
}

