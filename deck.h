#ifndef DECK_H
#define DECK_H

#include <QList>
#include "card.h"

class Deck
{
private:
    void pushInitialCards(Suit suit);
    QList<Card*> availableCards;
    QList<Card*> dealtCards;

public:
    Deck();
    Card* getNextCard();
    void resetDeck();
};

#endif // DECK_H
