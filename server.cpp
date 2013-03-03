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
    //DEal 4th card. 9 + 10 + 10 = 19
    game->doAction(new UserAction(user3, CHECK));
    game->doAction(new UserAction(user4, RAISE, 1));
    game->doAction(new UserAction(user3, CALL, 1));
    game->doAction(new UserAction(user4, CHECK));
    //Deal 5th card. 19 + 1 + 1 = 21
    game->doAction(new UserAction(user3, CHECK));
    game->doAction(new UserAction(user4, CHECK));
    // 21 + 0 = 21
    //Check cards.
    //user3 Wins.
    // 21 to user3.
    //New Loop. Move button.
}

void Server::onUserJoinGame(UserInfo* user){
    qDebug() << user->getUserId() << " Joined Game \n";
}

void Server::onGameStarted(GameStartAction* gameStartAction){
    qDebug() << gameStartAction->getUserWithButton()->getUserId() << gameStartAction->getUserWithButton()->getUserMoneyOnTable()
             << " "
             << gameStartAction->getSmallBlind()->getUserId() << gameStartAction->getSmallBlind()->getUserMoneyOnTable()
             << " "
             << gameStartAction->getBigBlind()->getUserId() << gameStartAction->getBigBlind()->getUserMoneyOnTable();

}

void Server::onUserMove(UserMoveAction* userMoveAction){
    qDebug() << "On user Move "
             << userMoveAction->getAvailableActions() << " "
             << userMoveAction->getMinimumBid() << " "
             << userMoveAction->getUserInfo()->getUserId();
}

void Server::onFirstCardsDealed(FirstCardsAction* firstCardsAction){

}

void Server::onNextCardDealed(Card* nextCard){

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

}
