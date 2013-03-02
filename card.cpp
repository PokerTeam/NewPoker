#include "card.h"
Card::Card(Suit suit, char number){
    this->suit = suit;
    this->number = number;
}

Suit Card::getSuit(){
    return suit;
}

char Card::getCardNumber(){
    return number;
}
