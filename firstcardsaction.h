#ifndef FIRSTCARDSACTION_H
#define FIRSTCARDSACTION_H

#include "card.h"

class FirstCardsAction
{
private:
    Card firstCard;
    Card secondCard;
    Card thirdCard;

public:
    FirstCardsAction();
    FirstCardsAction(Card firstCard, Card secondCard, Card thirdCard);
    Card getFirstCard();
    Card getSecondCard();
    Card getThirdCard();

    friend QDataStream &operator<<(QDataStream &out,FirstCardsAction &info);
    friend QDataStream &operator>>(QDataStream &in, FirstCardsAction &info);
};

#endif // FIRSTCARDSACTION_H
