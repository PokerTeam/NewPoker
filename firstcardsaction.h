#ifndef FIRSTCARDSACTION_H
#define FIRSTCARDSACTION_H

#include "card.h"

class FirstCardsAction
{
public:
    FirstCardsAction();
    FirstCardsAction(Card firstCard, Card secondCard, Card thirdCard);
    Card getFirstCard();
    Card getSecondCard();
    Card getThirdCard();

    friend QDataStream &operator<<(QDataStream &out,FirstCardsAction &info);
    friend QDataStream &operator>>(QDataStream &in, FirstCardsAction &info);

private:
    Card firstCard;
    Card secondCard;
    Card thirdCard;
};

#endif // FIRSTCARDSACTION_H
