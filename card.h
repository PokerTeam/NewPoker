#ifndef CARD_H
#define CARD_H

#include <QDataStream>
#include "suit.h"

class Card
{
public:
    Card();
    Card(Suit suit, int number);
    Suit getSuit();
    int getCardNumber();

    friend QDataStream &operator<<(QDataStream &out,Card &info);
    friend QDataStream &operator>>(QDataStream &in, Card &info);

private:
    Suit suit;
    int number;
};

#endif // CARD_H
