#ifndef CLIENT_H
#define CLIENT_H
#include <QObject>
#include "useraction.h"
#include "userinfo.h"
#include "gamestartaction.h"
#include "usermoveaction.h"
#include "card.h"
#include "firstcardsaction.h"
#include "userleaveaction.h"
#include "bankchangeaction.h"
class Client : QObject
{
    Q_OBJECT
public:
    Client();
public slots:
    void onAction(UserAction* userAction);
    void joinGame(UserInfo* user);
signals:
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

#endif // CLIENT_H
