#ifndef SERVER_H
#define SERVER_H
/////////////////Network
#include <QtNetwork/QTcpServer>
#include<qnetworkinterface.h>
#include <QObject>
#include <QDebug>
#include <QDate>
#include <qlist.h>
#include <iostream>
#include <windows.h>
#include <QThread>
#include <client.h>
///////////////////////////////////////
#include "useraction.h"
#include "user.h"
#include "gameaction.h"
#include "userinfo.h"
#include "usermoveaction.h"
#include "gamestartaction.h"
#include "firstcardsaction.h"
#include "userleaveaction.h"
#include "bankchangeaction.h"
#include "game.h"
class Client;
class Server : public QTcpServer
{
    Q_OBJECT
public:
    Server();
    void start(QHostAddress addr, qint16 port);
    void stop();
    void outToConsole(QString message,int color);
    QList<Client *> getClients(){return _clients;}
private:
    Game* game;
    HANDLE hConsole;
    QList<Client *> _clients;
signals:
    void onAction(UserAction* userAction);
    void joinGame(UserInfo* user);
public slots:
    void onRemoveUser(Client* client);
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
protected:
void incomingConnection(int handle);
};

#endif // SERVER_H
