#include "card.h"

Card::Card(){
    this->suit = HEARTS;
    this->number = 0;
}

Card::Card(Suit suit, int number){
    this->suit = suit;
    this->number = number;
}

Suit Card::getSuit()
{
    return suit;
}

int Card::getCardNumber()
{
    return number;
}

QDataStream &operator<<(QDataStream &out,Card &card)
{
    out << quint32(card.suit)
        << quint32(card.number);
    return out;
}

QDataStream &operator>>(QDataStream &in, Card &card)
{
    quint32 suitInt;
    quint32 number;
    in >> suitInt >> number;
    card.suit = (Suit)suitInt;
    card.number = number;
    return in;
}
