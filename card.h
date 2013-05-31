#ifndef CARD_H
#define CARD_H

#include <QDataStream>
#include "suit.h"

class Card
{
private:
    Suit suit;
    int number;

public:
    Card();
    Card(Suit suit, int number);
    Suit getSuit();
    int getCardNumber();
    bool isEquals(Card* other);
    int compare(Card* other);
    bool isOrdered(Card* other);

    static int getCardImage(Card card);

    friend QDataStream &operator<<(QDataStream &out,Card &info);
    friend QDataStream &operator>>(QDataStream &in, Card &info);
};

#endif // CARD_H
