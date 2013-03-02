#include "game.h"

Game::Game(AccountManager* accountManager)
{
    this->accountManager = accountManager;
}

void Game::doAction(UserAction* userAction)
{
}

void Game::joinGame(User* user)
{
    if (accountManager->isPasswordCorrect(user->getUserId(), user->getPassword())){
        UserInfo* userInfo = new UserInfo(user);
        usersInGame.push_back(userInfo);
        emit onUserJoinGame(userInfo);
    }else{
        emit onJoinUserFailed(user->getUserId());
    }

}
