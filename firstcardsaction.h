#ifndef FIRSTCARDSACTION_H
#define FIRSTCARDSACTION_H
#include "card.h"
class FirstCardsAction
{
public:
    FirstCardsAction(Card* firstCard, Card* secondCard, Card* thirdCard);
private:
    Card* firstCard;
    Card* secondCard;
    Card* thirdCard;
};

#endif // FIRSTCARDSACTION_H
