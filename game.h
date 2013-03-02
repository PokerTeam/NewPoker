#ifndef GAME_H
#define GAME_H
#include <QObject>
#include <user.h>
#include <QList>
#include <gameaction.h>
#include <card.h>
#include <usercardset.h>
#include <deck.h>
#include <useraction.h>
#include "gamestartaction.h"
#include "firstcardsaction.h"
#include "userleaveaction.h"
#include "bankchangeaction.h"
#include "usermoveaction.h"
#include "accountmanager.h"
class Game : public QObject
{
    Q_OBJECT
public:
    Game(AccountManager* accountManager);

private:
    QList<User> getUsersInGame();
    bool isGameStarted();//Maybe we do not need to implement this.
    User* getWinner(UserCardSet firstList, UserCardSet second);
    User* getWinner(QList<UserCardSet> cardSets);
    Deck* deck;
    QList<Card> cardsOnTable;
    QList<UserCardSet> cardSets;
    QList<UserInfo*> usersInGame; //This users are currently playing game.
    QList<UserInfo*> userInQueue; //This users are waiting for game.
    long bankValue;
    long lastBid;
    long currentUserCursor;
    AccountManager* accountManager;
public slots:
    //When user do his step.
    void doAction(UserAction* userAction);
    void joinGame(User* user);
signals:
    //if more than 2 users joined , we need to start the game.
    void onUserJoinGame(UserInfo* user);
    void onJoinUserFailed(long userId);
    //Deal hidden cards.
    //And We need to fill cardSets collection.
    void gameStarted(GameStartAction* gameStartAction);
    // Occurs when cursor is set to user. And 30(hidden) + 30(visible) seconds timer is started.
    void onUserMove(UserMoveAction* userMoveAction);
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
