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
#include "clientsocket.h"
class Server : public QTcpServer
{
    Q_OBJECT
public:
    Server(Game* game);
    void start(QHostAddress addr, qint16 port);
    void stop();
    void outToConsole(QString message,int color);
private:
    Game* game;
    HANDLE hConsole;
protected:
void incomingConnection(int handle);
};

#endif // SERVER_H
