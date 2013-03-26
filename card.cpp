#include "card.h"

Card::Card(Suit suit, int number){
    this->suit = suit;
    this->number = number;
}

Suit Card::getSuit(){
    return suit;
}

int Card::getCardNumber(){
    return number;
}
