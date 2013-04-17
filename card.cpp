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

int Card::getCardImage(Card card)
{
    int delta = 0;
    switch (card.getSuit())
    {
        case HEARTS:
            delta = 14;
            break;

        case SPADES:
            delta = 0;
            break;

        case DIAMONDS:
            delta = 28;
            break;

        case CLUBS:
            delta = 42;
            break;
    }
    return delta + 14 - card.getCardNumber();
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
