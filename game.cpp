#include "game.h"

Game::Game()
{
}

void Game::doAction(UserAction* userAction)
{
}

void Game::joinGame(UserInfo* user)
{

}

QList<User*> Game::getWinner(QList<UserCardSet> cardSets, QList<Card> cardsOnTable)
{
    Winner winners;
    return winners.GetWinner(cardSets, cardsOnTable);
}
