#include "firstcardsaction.h"

FirstCardsAction::FirstCardsAction(){
    this->firstCard = Card();
    this->secondCard = Card();
    this->thirdCard = Card();
}

FirstCardsAction::FirstCardsAction(Card firstCard,
                                   Card secondCard,
                                   Card thirdCard)
{
    this->firstCard = firstCard;
    this->secondCard = secondCard;
    this->thirdCard = thirdCard;
}

Card FirstCardsAction::getFirstCard()
{
    return firstCard;
}

Card FirstCardsAction::getSecondCard()
{
    return secondCard;
}

Card FirstCardsAction::getThirdCard()
{
    return thirdCard;
}

QDataStream &operator<<(QDataStream &out,FirstCardsAction &action)
{
    out << action.firstCard << action.secondCard << action.thirdCard;
    return out;
}

QDataStream &operator>>(QDataStream &in, FirstCardsAction &action)
{
    in >> action.firstCard >> action.secondCard >> action.thirdCard;
    return in;
}
