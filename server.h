#ifndef SERVER_H
#define SERVER_H
#include "useraction.h"
#include "user.h"
#include "gameaction.h"
#include <QObject>
#include "userinfo.h"
#include "usermoveaction.h"
#include "gamestartaction.h"
#include "firstcardsaction.h"
#include "userleaveaction.h"
#include "bankchangeaction.h"
#include "game.h"

class Server : QObject
{
    Q_OBJECT
public:
    Server();
    void start();
    void stop();
private:
    Game* game;
signals:
    void onAction(UserAction* userAction);
    void joinGame(UserInfo* user);
public slots:
    void onUserJoinGame(UserInfo* user);
    void onGameStarted(GameStartAction* gameStartAction);
    void onUserMove(UserMoveAction* userMoveAction);
    void onFirstCardsDealed(FirstCardsAction* firstCardsAction);
    void onNextCardDealed(Card* nextCard);
    void onGameFinished(UserInfo* winner);
    void onGameStopped();
    void onUserAction(UserAction* userAction);
    void onUserLeaveGame(UserLeaveAction* userLeaveAction);
    void onBankChanged(BankChangeAction* bankChangeAction);
};

#endif // SERVER_H
