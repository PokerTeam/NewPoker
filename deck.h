#ifndef DECK_H
#define DECK_H
#include <card.h>
#include <QList>
class Deck
{
public:
    Deck();
    Card getNextCard();
    void resetDeck();
private:
    QList<Card> availableCards;
    QList<Card> dealtCards;

};

#endif // DECK_H
