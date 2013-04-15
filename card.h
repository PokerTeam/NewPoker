#ifndef CARD_H
#define CARD_H

#include "suit.h"

class Card
{
public:
    Card();
    Card(Suit suit, int number);
    Suit getSuit();
    int getCardNumber();

private:
    Suit suit;
    int number;
};

#endif // CARD_H
