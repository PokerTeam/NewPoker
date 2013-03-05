#include "UserCombination.h"

UserCombination::UserCombination(UserCardSet *cardSet, QList<Card> cardsOnTable)
{
    this->cardSet = cardSet;
    this->cardsOnTable = cardsOnTable;
    user = cardSet->getUser();
    determineCombination();
}

void UserCombination::determineCombination()
{
    if(determineSameSuitCombination())
    {
        determineControversialCard();
        return;
    }

    if(determineStrightCombination())
    {
        determineControversialCard();
        return;
    }

    if(determineSameCardsValueCombinations())
    {
        return;
    }


}

bool UserCombination::determineSameCardsValueCombinations()
{
    QList<Card> cards = prepareCards();
    QMap<int, QList<Card> > cardsMap;
    countCardsEntries(cardsMap, cards);

    QMapIterator<int, QList<Card> > i(cardsMap);
    QList<int> setKeys;
    QList<int> pairKeys;
    countAmountOfPairs(i, setKeys, pairKeys);

    if(checkOnFourOfKind(cardsMap, cards))
    {
        return true;
    }

    if(checkOnFullHouse(cardsMap, setKeys, pairKeys))
    {
        return true;
    }

    if(checkOnSet(cardsMap, setKeys, pairKeys))
    {
        return true;
    }

    if(checkOnPairs(cardsMap, setKeys, pairKeys))
    {
        return true;
    }

    return false;

}

bool UserCombination::checkOnPairs(QMap<int, QList<Card> > cardsMap, QList<int> setKeys, QList<int> pairKeys)
{
    if(setKeys.length() == 0)
    {
        switch(pairKeys.length())
        {
        case 3:
        {
            determineTwoPairsFromThreePairs(cardsMap, pairKeys);
            return true;
            break;
        }
        case 2:
        {
            determineTwoPairs(cardsMap, pairKeys);
            return true;
            break;
        }
        case 1:
        {
            determinePair(cardsMap, pairKeys);
            return true;
            break;
        }
        case 0:
        {
            determineHandCards();
            return true;
            break;
        }
        }
    }

    return false;
}

void UserCombination::determineHandCards()
{
    QList<Card> cards;
    cards.append(*cardSet->getFirstCard());
    cards.append(*cardSet->getSecondCard());
    sortCards(cards);
    cardsCombination = cards;
    addHandCardsToControversialCards();
    combinationValue = HAND_CARDS;
}

void UserCombination::determinePair(QMap<int, QList<Card> > cardsMap, QList<int> pairKeys)
{
    cardsCombination.clear();
    cardsCombination.append(cardsMap[pairKeys[0]]);
    determineControversialCard(cardsCombination[0]);
    combinationValue = PAIR;
}

void UserCombination::determineTwoPairs(QMap<int, QList<Card> > cardsMap, QList<int> pairKeys)
{
    QList<Card> twoPairsCards;
    twoPairsCards.append(cardsMap[pairKeys[0]]);
    twoPairsCards.append(cardsMap[pairKeys[1]]);
    sortCards(twoPairsCards);
    cardsCombination = twoPairsCards;
    combinationValue = TWO_PAIR;
}

void UserCombination::determineTwoPairsFromThreePairs(QMap<int, QList<Card> > cardsMap, QList<int> pairKeys)
{
    QList<Card> cards;
    cards.append(cardsMap[pairKeys[0]]);
    cards.append(cardsMap[pairKeys[1]]);
    cards.append(cardsMap[pairKeys[2]]);
    sortCards(cards);

    for(int i = 0; i< 2; i++)
    {
        cards.removeAt(cards.length()-1);
    }

    cardsCombination = cards;
    determineControversialCard(cardsCombination[0], cardsCombination[1]);
    combinationValue = TWO_PAIR;
}

bool UserCombination::checkOnSet(QMap<int, QList<Card> > cardsMap, QList<int> setKeys, QList<int> pairKeys)
{
    if((setKeys.length() == 1) && (pairKeys.length() == 0))
    {
        cardsCombination.clear();
        cardsCombination = cardsMap[setKeys[0]];
        combinationValue = SET;
        determineControversialCard();
        return true;
    }

    return false;
}

bool UserCombination::checkOnFullHouse(QMap<int, QList<Card> > cardsMap, QList<int> setKeys, QList<int> pairKeys)
{
    if(setKeys.length() == 2)
    {
       fullHouseFromTwoSets(cardsMap, setKeys, pairKeys);
       return true;
    }

    if((setKeys.length() == 1) && (pairKeys.length() > 0))
    {
       fullHouseFromSetAndPairs(cardsMap, setKeys, pairKeys);
       return true;
    }

    return false;
}

void UserCombination::fullHouseFromTwoSets(QMap<int, QList<Card> > cardsMap, QList<int> setKeys, QList<int> pairKeys)
{
    if(cardsMap[setKeys[0]].first().getCardNumber() > cardsMap[setKeys[1]].first().getCardNumber())
    {
        cardsMap[setKeys[1]].removeLast();
        determineFullHouse(cardsMap[setKeys[0]], cardsMap[setKeys[1]]);
    }
    else
    {
        cardsMap[setKeys[0]].removeLast();
        determineFullHouse(cardsMap[setKeys[1]], cardsMap[setKeys[0]]);
    }

}

void UserCombination::fullHouseFromSetAndPairs(QMap<int, QList<Card> > cardsMap, QList<int> setKeys, QList<int> pairKeys)
{
    QList<Card> fullHouseSet = cardsMap[setKeys[0]];

    if(pairKeys.length() == 2)
    {
        int firstPairValue = cardsMap[pairKeys[0]][0].getCardNumber();
        int secondPairValue = cardsMap[pairKeys[0]][1].getCardNumber();

        if(firstPairValue > secondPairValue)
        {
            determineFullHouse(fullHouseSet, cardsMap[pairKeys[0]]);
        }
        else
        {
            determineFullHouse(fullHouseSet, cardsMap[pairKeys[1]]);
        }
    }
    else
    {
        determineFullHouse(fullHouseSet, cardsMap[pairKeys[0]]);
    }
}

void UserCombination::determineFullHouse(QList<Card> setCards, QList<Card> pairCards)
{
    cardsCombination.clear();
    cardsCombination.append(setCards);
    cardsCombination.append(pairCards);
    determineControversialCard(setCards.first(), pairCards.first());
    combinationValue = FULL_HOUSE;
}

void UserCombination::countAmountOfPairs(QMapIterator<int, QList<Card> > i ,QList<int> &setKeys, QList<int> &pairKeys)
{
    while (i.hasNext())
    {
        i.next();
        if(i.value().length()== 3)
        {
            Card keyCard = i.value()[0];
            setKeys.append(keyCard.getCardNumber());
        }

        if(i.value().length()== 2)
        {
            Card keyCard = i.value()[0];
            pairKeys.append(keyCard.getCardNumber());
        }
    }
}

//----------------------FOUR OF KIND COMBINATION---------------------------------------------

bool UserCombination::checkOnFourOfKind(QMap<int, QList<Card> > cardsMap, QList<Card> cards)
{
    QMapIterator<int, QList<Card> > i(cardsMap);
    while (i.hasNext())
    {
        i.next();
        if(i.value().length() == 4)
        {
            determineFourOfKind(cards, i.value());
            combinationValue = FOUR_OF_KIND;

            return true;
        }
    }

    return false;
}

void UserCombination::determineFourOfKind(QList<Card> cards, QList<Card> fourOfKindCards)
{
    QList<Card> fourOfKindCombination;
    QList<Card> otherCards;

    fourOfKindCombination.append(fourOfKindCards);


    foreach (Card card, cards)
    {
        if(fourOfKindCombination[0].getCardNumber()!= card.getCardNumber())
        {
            otherCards.append(card);
        }
    }

    sortCards(otherCards);

    fourOfKindCombination.append(otherCards.first());
    cardsCombination = fourOfKindCombination;
    determineControversialCard(fourOfKindCards.first(), otherCards.first());
}

void UserCombination::countCardsEntries(QMap<int, QList<Card> > &cardsMap, QList<Card> cards)
{
    foreach (Card card, cards)
    {
        if(cardsMap.contains(card.getCardNumber()) )
        {
            cardsMap[card.getCardNumber()].append(card);
        }
        else
        {
            QList<Card> cardsList;
            cardsList.append(card);

            cardsMap.insert(card.getCardNumber(), cardsList);

        }
    }
}

QList<Card> UserCombination::prepareCards()
{
    QList<Card> cards;
    cards.append(*cardSet->getFirstCard());
    cards.append(*cardSet->getSecondCard());
    cards.append(cardsOnTable);

    sortCards(cards);

    return cards;
}

//--------------------STRIGHT COMBINATION---------------------------------------------------------

bool UserCombination::determineStrightCombination()
{
    QList<Card> cards;
    cards.append(*cardSet->getFirstCard());
    cards.append(*cardSet->getSecondCard());
    cards.append(cardsOnTable);

    bool isStright = checkOnStright(cards);

    if(isStright)
    {
        cardsCombination = cards;
        determineControversialCard();
        combinationValue = STRIGHT;
        return true;
    }

    return false;
}

//----------------------FLUSH COMBINATIONS--------------------------------------------------------

bool UserCombination::checkOnFlush(QList<Card> &flushCombination)
{
    if(flushCombination.length()>=5)
    {
        sortCards(flushCombination);
        int length = flushCombination.length()-5;
        for(int i = 0; i< length ; i++)
        {
            flushCombination.removeAt(flushCombination.length()-1);
        }

        return true;
    }

    return false;
}

QList<Card> UserCombination::checkSameSuit()
{
    Card firstCard = *(*cardSet).getFirstCard();
    Card secondCard = *(*cardSet).getSecondCard();
    QList<Card> flashCombination;

    if(firstCard.getSuit() == secondCard.getSuit())
    {
        flashCombination.append(firstCard);
        flashCombination.append(secondCard);
        flashCombination = addTableCardsOfTheSameSuit(flashCombination, cardsOnTable);
        return flashCombination;
    }
    else
    {
        flashCombination.append(firstCard);
        flashCombination = addTableCardsOfTheSameSuit(flashCombination, cardsOnTable);

        if(flashCombination.length()>=5)
        {
            return flashCombination;
        }
        else
        {
            flashCombination.clear();
            flashCombination.append(secondCard);
            flashCombination = addTableCardsOfTheSameSuit(flashCombination, cardsOnTable);
            return flashCombination;
        }
    }
}

QList<Card> UserCombination::addTableCardsOfTheSameSuit(QList<Card> flushCombination, QList<Card> cardsOnTable)
{
    Suit flashSuit = flushCombination[0].getSuit();
    foreach (Card card, cardsOnTable)
    {
        if(flashSuit == card.getSuit())
        {
            flushCombination.append(card);
        }
    }

    return flushCombination;
}

bool UserCombination::determineSameSuitCombination()
{
    QList<Card> flushCombination = checkSameSuit();

    if(checkOnFlush(flushCombination))
    {
        bool isStright = checkOnStright(flushCombination);
        cardsCombination = flushCombination;


        if(isStright)
        {
            if(flushCombination.first().getCardNumber() == 14)
            {
                combinationValue = ROYAL_FLUSH;

            }
            else
            {
                combinationValue = STRIGHT_FLUSH;
            }
        }
        else
        {
            combinationValue = FLUSH;
        }

        return true;
    }

    return false;
}

bool UserCombination::checkOnStright(QList<Card> &cards)
{
    QList<Card> strightFollowing = checkStrightFollowing(cards);

    if(strightFollowing.length() >= 5)
    {
        cards = strightFollowing;

        int length = cards.length()-5;
        for(int i = 0; i< length; i++)
        {
            cards.removeAt(cards.length()-1);
        }

         return true;
    }

    return false;
}

QList<Card> UserCombination::checkStrightFollowing(QList<Card> cards)
{
   sortCards(cards);
   QList<Card> strightCombination;
   strightCombination.append(cards[0]);
   for(int i = 0; i < cards.length()-1; i++ )
   {
       if( (cards[i+1].getCardNumber() - cards[i].getCardNumber())== -1 )
       {
           strightCombination.append(cards[i+1]);
       }
       else
       {
           if(strightCombination.length()<5)
           {
               strightCombination.clear();
               strightCombination.append(cards[i+1]);
           }
           else
           {
               return strightCombination;
           }
       }

   }

   return strightCombination;
}


//-----------------------END FLUSH COMBINATIONS----------------------------------------

void UserCombination::determineControversialCard(Card firstCard)
{
    controversialCards.clear();
    controversialCards.append(firstCard);
    addHandCardsToControversialCards();
}

void UserCombination::determineControversialCard(Card firstCard, Card secondCard)
{
    controversialCards.clear();
    QList<Card> highCards;
    highCards.append(firstCard);
    highCards.append(secondCard);
    controversialCards.append(highCards);
    addHandCardsToControversialCards();
}

void UserCombination::determineControversialCard()
{
    controversialCards.clear();
    controversialCards.append(cardsCombination.first());
    addHandCardsToControversialCards();
}

void UserCombination::addHandCardsToControversialCards()
{
    QList<Card> handCards;
    handCards.append(*cardSet->getFirstCard());
    handCards.append(*cardSet->getSecondCard());
    sortCards(handCards);
    controversialCards.append(handCards);
}

void UserCombination::sortCards(QList<Card> &cards)
{
    bool exit = false;

    while (exit!= true)
    {
        exit = true;

        for(int i = 0; i< cards.length()-1; i++)
        {
            if(cards[i].getCardNumber()< cards[i+1].getCardNumber())
            {
                exit = false;
                Card tempCard = cards[i];
                cards[i] = cards[i+1];
                cards[i+1] = tempCard;
            }
        }
    }
}
