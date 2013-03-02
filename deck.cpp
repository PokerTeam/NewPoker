#include "deck.h"
#include <QtGlobal>
#include <QDateTime>
Deck::Deck(){
    resetDeck();
}

void Deck::pushInitialCards(Suit suit){
    for (char i = 2; i <= 14; i++){
        availableCards.push_back(new Card(suit, i));
    }
}

Card Deck::getNextCard(){
    return availableCards[qsrand(QDateTime::currentMSecsSinceEpoch()) % availableCards.length()];
}

void Deck::resetDeck(){
    dealtCards.clear();
    availableCards.clear();
    pushInitialCards(HEARTS);
    pushInitialCards(SPADES);
    pushInitialCards(CLUBS);
    pushInitialCards(DIAMONDS);
}
