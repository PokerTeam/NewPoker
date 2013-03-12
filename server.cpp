#include "server.h"
#include <QDebug>
Server::Server()
{

}

void Server::start(){
    game = new Game(new AccountManager());
    connect(game, SIGNAL(onUserJoinGame(UserInfo*)), this, SLOT(onUserJoinGame(UserInfo*)));
    connect(game, SIGNAL(gameStarted(GameStartAction*)), this, SLOT(onGameStarted(GameStartAction*)));
    connect(game, SIGNAL(onUserMove(UserMoveAction*)), this, SLOT(onUserMove(UserMoveAction*)));
    connect(game, SIGNAL(onUserAction(UserAction*)), this, SLOT(onUserAction(UserAction*)));
    connect(game, SIGNAL(onFirstCardsDealed(FirstCardsAction*)), this, SLOT(onFirstCardsDealed(FirstCardsAction*)));
    connect(game, SIGNAL(onNextCardDealed(Card*)), this, SLOT(onNextCardDealed(Card*)));
    connect(game, SIGNAL(onBankChanged(BankChangeAction*)), this, SLOT(onBankChanged(BankChangeAction*)));
    User* user1 = new User(1, "1", "123", 100);
    User* user2 = new User(2, "2", "123", 100);
    User* user3 = new User(3, "3", "123", 100);
    User* user4 = new User(4, "4", "123", 100);
    game->joinGame(user1);
    game->joinGame(user2);
    game->joinGame(user3);
    game->joinGame(user4);
    game->doAction(new UserAction(user4, CALL, 2));
    game->doAction(new UserAction(user1, FOLD));
    game->doAction(new UserAction(user2, RAISE, 2));
    game->doAction(new UserAction(user3, CALL, 1));
    game->doAction(new UserAction(user4, CALL, 1));
    //Deal 3 cards.
    //Money to bank. 1 + 2 + 2 + 2 + 1 + 1 = 9
    game->doAction(new UserAction(user2, FOLD));
    game->doAction(new UserAction(user3, RAISE, 10));
    game->doAction(new UserAction(user4, CALL, 10));
    //DEal 4th card. 9 + 10 + 10 = 29
    game->doAction(new UserAction(user3, CHECK));
    game->doAction(new UserAction(user4, RAISE, 1));
    game->doAction(new UserAction(user3, CALL, 1));
    game->doAction(new UserAction(user4, CHECK));
    //Deal 5th card. 19 + 1 + 1 = 31
    game->doAction(new UserAction(user3, CHECK));
    game->doAction(new UserAction(user4, CHECK));
    // 31 + 0 = 31
    //Check cards.
    //user3 Wins.
    // 31 to user3.
    //New Loop. Move button.
}

void Server::onUserJoinGame(UserInfo* user){
    qDebug() << user->getUserId() << " Joined Game \n";
}

void Server::onGameStarted(GameStartAction* gameStartAction){
    qDebug() << "Button on user " << gameStartAction->getUserWithButton()->getUserId() << " money on table " << gameStartAction->getUserWithButton()->getUserMoneyOnTable()
             << endl
             << "Small blind on user " << gameStartAction->getSmallBlind()->getUserId() << " money on table " << gameStartAction->getSmallBlind()->getUserMoneyOnTable()
             << endl
             << "Big blind on user " << gameStartAction->getBigBlind()->getUserId() << " money on table " << gameStartAction->getBigBlind()->getUserMoneyOnTable();

}

void Server::onUserMove(UserMoveAction* userMoveAction){
    qDebug() << "On user Move "
             << userMoveAction->getAvailableActions() << " "
             << userMoveAction->getMinimumBid() << " as minimumBid; "
             << userMoveAction->getUserInfo()->getUserId() << " as userId";
}

void Server::onFirstCardsDealed(FirstCardsAction* firstCardsAction){
    qDebug() << "On first cards dealed "
             << firstCardsAction->getFirstCard()->getCardNumber() << " " << firstCardsAction->getFirstCard()->getSuit() << " | "
             << firstCardsAction->getSecondCard()->getCardNumber() << " " << firstCardsAction->getSecondCard()->getSuit() << " | "
             << firstCardsAction->getThirdCard()->getCardNumber() << " " << firstCardsAction->getThirdCard()->getSuit();
}

void Server::onNextCardDealed(Card* nextCard){
    qDebug() << "On next card "
             << nextCard->getCardNumber() << " " << nextCard->getSuit();
}

void Server::onGameFinished(UserInfo* winner){

}

void Server::onGameStopped(){

}

void Server::onUserAction(UserAction* userAction){
    qDebug() << "On User Action "
             << userAction->getAction() << " as Action, "
             << userAction->getMoney() << " as Money, "
             << userAction->getUser()->getUserId() << " as UserId";
}

void Server::onUserLeaveGame(UserLeaveAction* userLeaveAction){

}

void Server::onBankChanged(BankChangeAction* bankChangeAction){
    qDebug() << "On Bank changed: " << bankChangeAction->getBankValue();
}
