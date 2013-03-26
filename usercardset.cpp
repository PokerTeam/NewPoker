#include "usercardset.h"

UserCardSet::UserCardSet(User *user, Card* firstCard, Card* secondCard){
    this->user = user;
    this->firstCard = firstCard;
    this->secondCard = secondCard;
}

Card* UserCardSet::getFirstCard(){
    return firstCard;
}

Card* UserCardSet::getSecondCard(){
    return secondCard;
}

User* UserCardSet::getUser(){
    return user;
}
