#include "game.h"
#include "QDebug"

Game::Game(AccountManager* accountManager)
{
    this->accountManager = accountManager;
    this->deck = new Deck();
    activeUsersCountOnStartLoop = currentLoopStep = 0;
    bankValue = 0;
    lastBid = 0;
    currentUserCursor = 0;
    buttonOnUserWithIndex = 0;
    cursorOnUserWithIndex = 0;
    activeUsersCountOnStartLoop = 0;
    currentLoopStep = 0;
}

void Game::doAction(UserAction userAction)
{
    lastUserAction[userAction.getUser().getUserId()] = &userAction;
    incrementLoopCounter(userAction.getUser().getUserId());
    UserInfo user = getUserInGame(userAction.getUser().getUserId());
    switch(userAction.getAction())
    {
        case CALL:
        case RAISE:
            user.putOnTable(userAction.getMoney());
            break;

        case FOLD:
        case CHECK:
            break;
    }
    emit onUserAction(UserAction(user, userAction.getAction(), userAction.getMoney()));
    askForUserMove();
}

void Game::incrementLoopCounter(long userId)
{
    if (userMoveCounter.keys().contains(userId))
    {
        userMoveCounter[userId]++;
    }
    else
    {
        userMoveCounter[userId] = 0;
    }
}

void Game::joinGame(UserInfo* user)
{
    if (usersInGame.length() <= 4)
    {
        usersInGame.push_back(*user);
        emit onUserJoinGame(usersInGame);
        if (usersInGame.length() == 2)
        {
            start();
        }
    }
    else
    {
        emit onJoinUserFailed(user->getUserId());
    }
}

void Game::resetLoopCounter()
{
    userMoveCounter.clear();
}

void Game::start()
{
    resetLoopCounter();
    UserInfo smallBlind = getSmallBlind();
    UserInfo bigBlind = getBigBlind();
    UserInfo userWithButton = getUserWithButton();
    emit gameStarted(GameStartAction(smallBlind,
                                     bigBlind,
                                     userWithButton));
    askForUserMove(true);
}

long Game::getMaximumBid()
{
    long maximumBid = 0;
    foreach (UserInfo user, usersInGame)
    {
        if (user.getUserMoneyOnTable() > maximumBid)
        {
            maximumBid = user.getUserMoneyOnTable();
        }
    }
    return maximumBid;
}

UserInfo Game::getUserWithButton()
{
    return usersInGame[getCursor(buttonOnUserWithIndex)];
}

UserInfo Game::getBigBlind()
{
    long index = getCursor(buttonOnUserWithIndex + 2);
    UserInfo* user = &usersInGame[index];
    user->putOnTable(BIG_BLIND_BID);
    lastUserAction[user->getUserId()] =
            new UserAction(*user,
                           RAISE,
                           BIG_BLIND_BID);
    incrementLoopCounter(user->getUserId()); //TODO: move from this method.
    return *user;
}

long Game::getCursor(long cursorValue)
{
    long length = usersInGame.length();
    return cursorValue % usersInGame.length();
}

UserInfo Game::getSmallBlind()
{
    UserInfo* user = &usersInGame[getCursor(buttonOnUserWithIndex + 1)];
    user->putOnTable(SMALL_BLIND_BID);
    lastUserAction[user->getUserId()] =
            new UserAction(*user,
                           RAISE,
                           SMALL_BLIND_BID);
    incrementLoopCounter(user->getUserId());
    return *user;
}

UserInfo Game::currentCursorOnUser()
{
    return usersInGame[getCursor(cursorOnUserWithIndex)];
}

void Game::moveCurrentCursor(long offset)
{
    cursorOnUserWithIndex = getCursor(cursorOnUserWithIndex + offset);
    UserInfo user = usersInGame[cursorOnUserWithIndex];
    bool lastActonFold = isLastActionExists(user.getUserId()) &&
                         (lastUserAction[usersInGame[cursorOnUserWithIndex].getUserId()]->getAction() == FOLD);
    if (lastActonFold ||
        usersInGame[cursorOnUserWithIndex].isAllIn())
    {
        moveCurrentCursor(cursorOnUserWithIndex + 1);
    }
}

void Game::askForUserMove(bool isFirstStep)
{
    if (!isFirstStep && isLoopFinished())
    {
        emit onBankChanged(BankChangeAction(moveFromTableToBank()));
        switch(cardsOnTable.length())
        {
            case 0:
                dealFirstThreeCards();
                break;

            case 3:
            case 4:
                dealNextCard();
                break;

            case 5:
                //TODO: check winner;
                qDebug() << "Winner";
                clearBank();
                start();
                return;
        }
    }

    if (isAllMovesEquals())
    {
        activeUsersCountOnStartLoop = currentLoopStep = 0;
        foreach(UserInfo user, usersInGame)
        {
            if (isUserActiveForBids(user.getUserId()))
            {
                activeUsersCountOnStartLoop++;
            }
        }
    }
    currentLoopStep += isFirstStep ? 2 : 1;
    moveCurrentCursor(isFirstStep ? 3 : 1);
    UserInfo currentUser = currentCursorOnUser();
    UserMoveAction action = UserMoveAction(currentUser,
                                           getAvailableActions(currentUser.getUserId()),
                                           getMinimumBid(currentUser.getUserId()));
    emit onUserMove(action);
    //TODO:Add 60 sec. timer.
}

long Game::getBankValue()
{
    return bankValue;
}

void Game::clearBank()
{
    bankValue = 0;
}

long Game::moveFromTableToBank()
{
    foreach(UserInfo user, usersInGame)
    {
        bankValue += user.getUserMoneyOnTable();
        user.clearMoneyOnTable();
    }
    return bankValue;
}

void Game::dealFirstThreeCards()
{
    QList<Card> newCards = addCardsOnTable(3);
    emit onFirstCardsDealed(FirstCardsAction(newCards[0],
                                                 newCards[1],
                                                 newCards[2]));
}

void Game::dealNextCard()
{
    Card newCard = addCardsOnTable(1).first();
    emit onNextCardDealed(newCard);
}

QList<Card> Game::addCardsOnTable(int count)
{
    QList<Card> cardsToInsert;
    for (int i = 0; i < count; i++)
    {
        cardsToInsert.push_back(*deck->getNextCard());
    }
    cardsOnTable.append(cardsToInsert);
    return cardsToInsert;
}

QList<Actions> Game::getAvailableActions(long userId)
{
    long minimumBid = getMinimumBid(userId);
    QList<Actions> actions;
    actions.push_back(FOLD);
    actions.push_back(CALL);
    actions.push_back(RAISE);
    if (minimumBid == 0)
    {
        actions.push_back(CHECK);
    }

    return actions;
}

long Game::getMinimumBid(long userId)
{
    UserInfo user = getUserInGame(userId);
    return getMaximumBid() - user.getUserMoneyOnTable();
}

UserInfo& Game::getUserInGame(long userId)
{
    for(long i = 0; i < usersInGame.length(); i++)
    {
        if (usersInGame[i].getUserId() == userId)
        {
            return usersInGame[i];
        }
    }
    UserInfo qwe;
    return qwe;
}

bool Game::isLoopFinished()
{
    qDebug() << "All bids eq: " << isAllBidsAreEquals() << endl
             << "All moves eq: " << isAllMovesEquals() << endl
             << "Moves " << activeUsersCountOnStartLoop << " - " << currentLoopStep;
    return isAllBidsAreEquals() && isAllMovesEquals();
}

bool Game::isAllBidsAreEquals()
{
    long previous = -1;
    foreach(UserInfo user, usersInGame)
    {
        if (isUserActiveForBids(user.getUserId()))
        {
            if (previous == -1)
            {
                previous = user.getUserMoneyOnTable();
            }
            else
            {
                if (previous != user.getUserMoneyOnTable())
                {
                    return false;
                }
            }
        }
    }
    return true;
}

bool Game::isAllMovesEquals()
{
    return currentLoopStep == activeUsersCountOnStartLoop;
}

long Game::getUserMovesCount(long userId)
{
    return userMoveCounter.keys().contains(userId) ? userMoveCounter[userId] : 0;
}

bool Game::isLastActionExists(long userId)
{
    return lastUserAction.keys().contains(userId);
}

bool Game::isUserActiveForBids(long userId)
{
    UserInfo user = getUserInGame(userId);
    bool isLastActionNotFold = !isLastActionExists(userId) ||
                               (lastUserAction[userId]->getAction() != FOLD);
    return !user.isAllIn() && isLastActionNotFold;
}

QList<User*> Game::getWinner(QList<UserCardSet> cardSets, QList<Card*> cardsOnTable)
{
    Winner* winners = new Winner();
    return winners->GetWinner(cardSets, cardsOnTable);
}
