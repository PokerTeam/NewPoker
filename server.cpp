#include "server.h"

Server::Server()
{

}

void Server::start()
{
    Game* game = new Game();

    connect(this, SIGNAL(joinGame(UserInfo*)),game, SLOT(joinGame(UserInfo*)));
    emit joinGame(new UserInfo(1,2,3));
}

void Server::onUserJoinGame(UserInfo* user){

}

void Server::onGameStarted(GameStartAction* gameStartAction){

}

void Server::onUserMove(UserMoveAction* userMoveAction){

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

}

void Server::onUserLeaveGame(UserLeaveAction* userLeaveAction){

}

void Server::onBankChanged(BankChangeAction* bankChangeAction){

}
