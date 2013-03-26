#include "firstcardsaction.h"

FirstCardsAction::FirstCardsAction(Card* firstCard, Card* secondCard, Card* thirdCard){
    this->firstCard = firstCard;
    this->secondCard = secondCard;
    this->thirdCard = thirdCard;
}

Card* FirstCardsAction::getFirstCard(){
    return firstCard;
}

Card* FirstCardsAction::getSecondCard(){
    return secondCard;
}

Card* FirstCardsAction::getThirdCard(){
    return thirdCard;
}
