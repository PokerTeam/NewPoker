#ifndef SERVER_H
#define SERVER_H

#include <QtNetwork/QTcpServer>
#include<qnetworkinterface.h>
#include <QObject>
#include <QDebug>
#include <QDate>
#include <QList>
#include <iostream>
#include <windows.h>
#include <QThread>

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
#include "client.h"
#include "clientsocket.h"

class Client;

class Server : public QTcpServer
{
    Q_OBJECT

public:
    Server(Game* game, AccountManager* accountManager);
    void start(QHostAddress addr, qint16 port);
    void stop();
    void outToConsole(QString message,int color);
    QList<Client*> getClients();

private:
    Game* game;
    AccountManager* accountManager;
    HANDLE hConsole;

protected:
    void incomingConnection(int handle);
};

#endif // SERVER_H
