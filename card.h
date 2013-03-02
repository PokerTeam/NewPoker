#ifndef CARD_H
#define CARD_H
#include <suit.h>
class Card
{
public:
    Card(Suit suit, char number);
    Suit getSuit();
    char getCardNumber();
private:
    Suit suit;
    char number;
};

#endif // CARD_H
