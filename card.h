#ifndef CARD_H
#define CARD_H
#include "Suit.h"

class Card
{
public:
    Card(Suit suit, int number);
    Suit getSuit(){ return suit; }
    int getCardNumber(){ return number; }

private:
    Suit suit;
    int number;
};

#endif // CARD_H
