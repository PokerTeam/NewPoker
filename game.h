#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QList>
#include <QMap>
#include "user.h"
#include "gameaction.h"
#include "card.h"
#include "usercardset.h"
#include "deck.h"
#include "useraction.h"
#include "gamestartaction.h"
#include "firstcardsaction.h"
#include "userleaveaction.h"
#include "bankchangeaction.h"
#include "usermoveaction.h"
#include "winner.h"
#include "accountmanager.h"

class Game : public QObject
{
    Q_OBJECT

public:
    Game(AccountManager* accountManager);

private:
    static const long BIG_BLIND_BID = 2;
    static const long SMALL_BLIND_BID = 1;

    AccountManager* accountManager;
    Deck* deck;
    QList<Card*> cardsOnTable;
    QList<UserCardSet> cardSets;
    QList<UserInfo> usersInGame; //This users are currently playing game.
    QList<UserInfo> userInQueue; //This users are waiting for game.
    QMap<long, UserAction*> lastUserAction;
    QMap<long, long> userMoveCounter;
    long bankValue;
    long lastBid;
    long currentUserCursor;
    long buttonOnUserWithIndex;
    long cursorOnUserWithIndex;
    int activeUsersCountOnStartLoop;
    int currentLoopStep;

    QList<User*> getWinner(QList<UserCardSet> cardSets, QList<Card*> cardsOnTable);
    User* getWinner(UserCardSet firstList, UserCardSet second);
    User* getWinner(QList<UserCardSet> cardSets);      
    UserInfo* getUserWithButton();
    UserInfo* getBigBlind();
    UserInfo* getSmallBlind();
    UserInfo currentCursorOnUser();
    void askForUserMove(bool isFirstStep = false);
    QList<Actions> getAvailableActions(long userId);
    long getMinimumBid(long userId);
    long getCursor(long cursorValue);
    void start();
    void resetLoopCounter();
    void incrementLoopCounter(long userId);
    void moveCurrentCursor(long offset);
    UserInfo* getUserInGame(long userId);
    bool isLoopFinished();
    void dealFirstThreeCards();
    void dealNextCard();
    void clearBank();
    long moveFromTableToBank();
    long getBankValue();
    long getMaximumBid();
    QList<Card*> addCardsOnTable(int count);
    bool isLastActionExists(long userId);
    bool isAllBidsAreEquals();
    bool isAllMovesEquals();
    long getUserMovesCount(long userId);
    bool isUserActiveForBids(long userId);

public slots:
        //When user do his step.
    void doAction(UserAction* userAction);
    void joinGame(UserInfo* user);

signals:
        //if more than 2 users joined , we need to start the game.
    void onUserJoinGame(QList<UserInfo> usersInGame);
    void onJoinUserFailed(long userId);
        //Deal hidden cards.
        //And We need to fill cardSets collection.
    void gameStarted(GameStartAction gameStartAction);
        // Occurs when cursor is set to user. And 30(hidden) + 30(visible) seconds timer is started.
    void onUserMove(UserMoveAction userMoveAction);
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
};

#endif // GAME_H
