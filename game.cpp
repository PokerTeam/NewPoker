#include "game.h"
#include "QDebug"
Game::Game(AccountManager* accountManager){
    this->accountManager = accountManager;
    this->deck = new Deck();
}

void Game::doAction(UserAction* userAction){
    lastUserAction[userAction->getUser()->getUserId()] = userAction;
    incrementLoopCounter(userAction->getUser()->getUserId());
    UserInfo* user = getUserInGame(userAction->getUser()->getUserId());
    switch(userAction->getAction()){
        case CALL:
        case RAISE:
            qDebug() << user->getUserMoneyOnTable();
            user->putOnTable(userAction->getMoney());
            qDebug() << "Call/Raise " << user->getUserId() << " with money on table :" << user->getUserMoneyOnTable();
            break;
    }
    emit onUserAction(userAction);
    askForUserMove();
}

void Game::incrementLoopCounter(long userId){
    if (userMoveCounter.keys().contains(userId)){
        userMoveCounter[userId]++;
    }else{
        userMoveCounter[userId] = 0;
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

void Game::resetLoopCounter(){
    userMoveCounter.clear();
}

void Game::start(){
    resetLoopCounter();
    emit gameStarted(new GameStartAction(getSmallBlind(), getBigBlind(), getUserWithButton()));
    askForUserMove(true);
}

long Game::getMaximumBid(){
    long maximumBid = 0;
    foreach (UserInfo* user, usersInGame){
        if (user->getUserMoneyOnTable() > maximumBid){
            maximumBid = user->getUserMoneyOnTable();
        }
    }
    return maximumBid;
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
    if (!isFirstStep && isLoopFinished()){
        emit onBankChanged(new BankChangeAction(moveFromTableToBank()));
        switch(cardsOnTable.length()){
            case 0:
                dealFirstThreeCards();
                break;
            case 3:
            case 4:
                dealNextCard();
                break;
            case 5:
                //TODO: check winner;
                clearBank();
                break;
        }
    }
    moveCurrentCursor(isFirstStep ? 3 : 1);
    UserInfo* currentUser = currentCursorOnUser();
    emit onUserMove(new UserMoveAction(
                        currentUser,
                        getAvailableActions(currentUser->getUserId()),
                        getMinimumBid(currentUser->getUserId())));
    //TODO:Add 60 sec. timer.
}

long Game::getBankValue(){
    return bankValue;
}

void Game::clearBank(){
    bankValue = 0;
}

long Game::moveFromTableToBank(){
    foreach(UserInfo* user, usersInGame){
        bankValue += user->getUserMoneyOnTable();
        user->clearMoneyOnTable();
    }
    return bankValue;
}

void Game::dealFirstThreeCards(){
    QList<Card*> newCards = addCardsOnTable(3);
    emit onFirstCardsDealed(new FirstCardsAction(newCards[0], newCards[1], newCards[2]));
}

void Game::dealNextCard(){
    Card* newCard = addCardsOnTable(1).first();
    emit onNextCardDealed(newCard);
}

QList<Card*> Game::addCardsOnTable(int count){
    QList<Card*> cardsToInsert;
    for (int i = 0; i < count; i++){
        cardsToInsert.push_back(deck->getNextCard());
    }
    cardsOnTable.append(cardsToInsert);
    return cardsToInsert;
}

QList<Actions> Game::getAvailableActions(long userId){
    long minimumBid = getMinimumBid(userId);
    QList<Actions> actions;
    actions.push_back(FOLD);
    actions.push_back(CALL);
    actions.push_back(RAISE);
    if (minimumBid == 0){
        actions.push_back(CHECK);
    }

    return actions;
}

long Game::getMinimumBid(long userId){
    UserInfo* user = getUserInGame(userId);
    return getMaximumBid() - user->getUserMoneyOnTable();
}

UserInfo* Game::getUserInGame(long userId){
    foreach(UserInfo* user, usersInGame){
        if (user->getUserId() == userId){
            return user;
        }
    }

    return NULL;
}

bool Game::isLoopFinished(){
    //This method makes me crazy. I need to rewrite it.
    long previous = -1;
    foreach(UserInfo* user, usersInGame){
        long key = user->getUserId();
        if (!lastUserAction.keys().contains(key)){
            return false;
        }
        if (lastUserAction[key]->getAction() != FOLD &&
            !user->isAllIn()){
            if (previous == -1){
                previous = user->getUserMoneyOnTable();
            }else{
                if (previous != user->getUserMoneyOnTable()){
                    return false;
                }
            }
        }
        previous = -1;
        if (lastUserAction[key]->getAction() != FOLD &&
            !user->isAllIn()){
            if (previous == -1){
                previous = userMoveCounter[key];
            }else{
                if (previous != userMoveCounter[key]){
                    return false;
                }
            }
        }
    }
    return true;
}

/*
bool Game::isAllUserBidsAreEqual(){
    long bid = -1;
    foreach(UserInfo* user, usersInGame){
        if (lastUserAction.keys().contains(user->getUserId())){
            UserAction* action = lastUserAction[user->getUserId()];
            if (action->getAction() != FOLD && !user->isAllIn()){
                if (bid == -1){
                    bid = user->getUserMoneyOnTable();
                }else{
                    if (bid != user->getUserMoneyOnTable()){
                        return false;
                    }
                }
            }
        }else{
            return false;
        }

    }

    return true;
}
*/
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
