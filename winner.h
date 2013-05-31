#ifndef WINNER_H
#define WINNER_H

#include <QObject>
#include <QList>

#include "user.h"
#include "usercardset.h"
#include "usercombination.h"

class Winner
{
private:
    QList<UserCombination> determineWinners(QList<UserCombination> &usersCombination);
    QList<UserCombination> getBestCombinations(QList<UserCombination> &usersCombination);
    int compareTwoTheSameCombinations(UserCombination firstCombination,
                                      UserCombination secondCombination);

public:
    Winner();
    QList<UserInfo> GetWinner(QList<UserCardSet> &cardSets,
                              QList<Card> &cardsOnTable);
};

#endif // WINNER_H
