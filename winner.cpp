#include "winner.h"

Winner::Winner()
{
}

QList<UserInfo> Winner::GetWinner(QList<UserCardSet> &cardSets, QList<Card> &cardsOnTable)
{
    QList<UserCombination> combinations;

    foreach (UserCardSet handCards, cardSets)
    {
        UserCombination usersCombination(handCards, cardsOnTable);
        combinations.append(usersCombination);
    }

    QList<UserCombination> winners = determineWinners(combinations);
    QList<UserInfo> users;

    foreach (UserCombination winnerCombination, winners)
    {
        users.append(winnerCombination.GetUser());
    }

    return users;
}

QList<UserCombination> Winner::determineWinners(QList<UserCombination> &usersCombination)
{
    QList<UserCombination> winners;
    QList<UserCombination> bestCombinations = getBestCombinations(usersCombination);

    if (bestCombinations.length() == 1)
    {
        winners.append(bestCombinations[0]);
        return winners;
    }
    else
    {
        winners.append(bestCombinations[0]);

        for (int i = 1; i< bestCombinations.length(); i++)
        {
            int compareResult = compareTwoTheSameCombinations(winners.last(), bestCombinations[i]);

            if (compareResult == -1)
            {
                winners.clear();
                winners.append(bestCombinations[i]);
            }

            if (compareResult == 0)
            {
                winners.append(bestCombinations[i]);
            }

        }
    }

    return winners;
}

int Winner::compareTwoTheSameCombinations(UserCombination firstCombination,
                                          UserCombination secondCombination)
{
    QList<Card> firstControversialCards = firstCombination.GetControversialCards();
    QList<Card> secondControversialCards = secondCombination.GetControversialCards();

    for (int i = 0; i < firstControversialCards.length(); i++)
    {
        if (firstControversialCards[i].getCardNumber() > secondControversialCards[i].getCardNumber())
        {
            return 1;
        }

        if (firstControversialCards[i].getCardNumber() < secondControversialCards[i].getCardNumber())
        {
            return -1;
        }
    }
    return 0;
}

QList<UserCombination> Winner::getBestCombinations(QList<UserCombination> &usersCombination)
{
    QList<UserCombination> bestCombinations;
    bestCombinations.append(usersCombination[0]);

    for (int i = 1; i< usersCombination.length(); i++)
    {
        if (usersCombination[i].GetCombinationValue() > bestCombinations[0].GetCombinationValue())
        {
            bestCombinations.clear();
            bestCombinations.append(usersCombination[i]);
        }
        else
        {
            if (usersCombination[i].GetCombinationValue() == bestCombinations[0].GetCombinationValue())
            {
                bestCombinations.append(usersCombination[i]);
            }
        }
    }

    return bestCombinations;
}
