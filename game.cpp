#include "game.h"

Game::Game(AccountManager* accountManager){
    this->accountManager = accountManager;
    this->deck = new Deck();
}

void Game::doAction(UserAction* userAction){
    lastUserAction[userAction->getUser()->getUserId()] = userAction;
    switch(userAction->getAction()){
        case FOLD:

            break;
    }
}

void Game::joinGame(User* user){
    if (accountManager->isPasswordCorrect(user->getUserId(), user->getPassword()) || usersInGame.length() == 6){
        UserInfo* userInfo = new UserInfo(user);
        usersInGame.push_back(userInfo);
        emit onUserJoinGame(userInfo);
        if (usersInGame.length() == 4){
            start();
        }
    }else{
        emit onJoinUserFailed(user->getUserId());
    }
}

void Game::start(){
    maximumBid = BIG_BLIND_BID;
    emit gameStarted(new GameStartAction(getSmallBlind(), getBigBlind(), getUserWithButton()));
    askForUserMove(true);
}

UserInfo* Game::getUserWithButton(){
    return usersInGame[getCursor(buttonOnUserWithIndex)];
}

UserInfo* Game::getBigBlind(){
    UserInfo* user = usersInGame[getCursor(buttonOnUserWithIndex + 2)];
    user->putOnTable(BIG_BLIND_BID);
    return user;
}

long Game::getCursor(long cursorValue){
    return cursorValue % usersInGame.length();
}

UserInfo* Game::getSmallBlind(){
    UserInfo* user = usersInGame[getCursor(buttonOnUserWithIndex + 1)];
    user->putOnTable(SMALL_BLIND_BID);
    return user;
}

UserInfo* Game::currentCursorOnUser(){
    return usersInGame[getCursor(cursorOnUserWithIndex)];
}

void Game::moveCurrentCursor(long offset){
    cursorOnUserWithIndex = getCursor(cursorOnUserWithIndex + offset);
}

void Game::askForUserMove(bool isFirstStep){
    moveCurrentCursor(isFirstStep ? 3 : 1);
    UserInfo* currentUser = currentCursorOnUser();
    emit onUserMove(new UserMoveAction(
                        currentUser,
                        getAvailableActions(currentUser->getUserId()),
                        getMinimumBid(currentUser->getUserId())));
    //TODO:Add 60 sec. timer.
}

QList<Actions> Game::getAvailableActions(long userId){
    long minimumBid = getMinimumBid(userId);
    QList<Actions> actions;
    actions.push_back(FOLD);
    actions.push_back(RAISE);
    if (minimumBid == 0){
        actions.push_back(CHECK);
    }

    return actions;
}

long Game::getMinimumBid(long userId){
    UserInfo* user = getUserInGame(userId);
    return maximumBid - user->getUserMoneyOnTable();
}

UserInfo* Game::getUserInGame(long userId){
    foreach(UserInfo* user, usersInGame){
        if (user->getUserId() == userId){
            return user;
        }
    }

    return NULL;
}

bool Game::isAllUserBidsAreEqual(){
    if (usersInGame.length() > 1){
        for (int i = 1; i < usersInGame.length(); i++){
            if (usersInGame[i]->getUserMoneyOnTable() != usersInGame[i - 1]->getUserMoneyOnTable()){
                return false;
            }
        }
    }
    return true;
}

// When first three cards dealed.
void onFirstCardsDealed(FirstCardsAction* firstCardsAction);

void onNextCardDealed(Card* nextCard);// For 4th and 5th cards.


void onGameFinished(UserInfo* winner);
//Occurs when gameStartedAction occured and less then 3 users in game.
void onGameStopped();

void onUserAction(UserAction* userAction);

//Occures after 60 seconds without response.
void onUserLeaveGame(UserLeaveAction* userLeaveAction);

void onBankChanged(BankChangeAction* bankChangeAction); //Occurs when bank value changed.
