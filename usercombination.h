#ifndef USERCOMBINATION_H
#define USERCOMBINATION_H

#include "user.h"
#include "usercardset.h"
#include "combination.h"
#include <QList>
#include <QMap>

class UserCombination
{

public:
    UserCombination(UserCardSet* userCards, QList<Card*> tableCards);
    QList<Card*> GetCardsCombination()
    {
        return cardsCombination;
    }

    Combination GetCombinationValue()
    {
        return combinationValue;
    }

    QList<Card*> GetControversialCards()
    {
        return controversialCards;
    }

    User* GetUser()
    {
        return user;
    }

private:
    UserCardSet* cardSet;
    User* user;
    QList<Card*> cardsOnTable;
    QList<Card*> cardsCombination;
    Combination combinationValue;
    QList<Card*> controversialCards;

    //------------------PAIR COMBINATONS-----------------------------------------------------

    bool checkOnPairs(QMap<int, QList<Card*> > cardsMap,
                      QList<int> setKeys,
                      QList<int> pairKeys);
    void determineTwoPairsFromThreePairs(QMap<int, QList<Card*> > cardsMap,
                                         QList<int> pairKeys);
    void determineTwoPairs(QMap<int, QList<Card*> > cardsMap,
                           QList<int> pairKeys);
    void determinePair(QMap<int, QList<Card*> > cardsMap,
                       QList<int> pairKeys);
    void determineHandCards();

    //------------------SET COMBINATIONS------------------------------------------------------

    bool checkOnSet(QMap<int, QList<Card*> > cardsMap,
                    QList<int> setKeys,
                    QList<int> pairKeys);

    //---------------------SAME KIND COMBINATIONS------------------------------------------------


    bool determineSameCardsValueCombinations();
    QList<Card*> prepareCards();
    void countCardsEntries(QMap<int, QList<Card*> > &map,
                           QList<Card*> cards);


    //-------------------FOUR OF KIND METHODS-----------------------------------------------------

    void determineFourOfKind(QList<Card*> cards,
                             QList<Card*> fourOfKindCards);
    bool checkOnFourOfKind(QMap<int, QList<Card*> > map,
                           QList<Card*> cards);

    //-------------------FULL HOUSE METHODS------------------------------------------------------------------

    void fullHouseFromTwoSets(QMap<int, QList<Card*> > cardsMap,
                              QList<int> setKeys,
                              QList<int> pairKeys);
    void fullHouseFromSetAndPairs(QMap<int, QList<Card*> > cardsMap,
                                  QList<int> setKeys,
                                  QList<int> pairKeys);
    void countAmountOfPairs(QMapIterator<int, QList<Card*> > i,
                            QList<int> &setKeys,
                            QList<int> &pairKeys);
    void determineFullHouse(QList<Card*> setCards,
                            QList<Card*> pairCards);
    bool checkOnFullHouse(QMap<int, QList<Card*> > cardsMap,
                          QList<int> setKeys,
                          QList<int> pairKeys);

    //--------------------STREET COMBINATION------------------------------------------------------

    bool determineStrightCombination();

    //--------------------FLASH COMBINATIONS METHODS-----------------------------------------------

    QList<Card*> checkSameSuit();
    bool determineSameSuitCombination();
    void sortCards(QList<Card*> &cards);
    QList<Card*> checkStrightFollowing(QList<Card*> cards);
    bool checkOnStright(QList<Card*> &cards);
    void determineCombination();
    QList<Card*> addTableCardsOfTheSameSuit(QList<Card*> flashCombination,
                                           QList<Card*> cardsOnTable);
    bool checkOnFlush(QList<Card*> &cards);

    //----------------------------------------------------------------------------------------------

    void determineControversialCard();
    void determineControversialCard(Card* firstCard);
    void determineControversialCard(Card* firstCard,
                                    Card* secondCard);
    void addHandCardsToControversialCards();
};

#endif // USERCOMBINATION_H
