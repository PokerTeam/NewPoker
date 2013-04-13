#ifndef CLIENTSOCKET_H
#define CLIENTSOCKET_H

#include <QObject>
#include <QTcpSocket>
#include <QDataStream>
#include "commands.h"
#include "loginresult.h"
#include "gamestartaction.h"
#include "usermoveaction.h"


class ClientSocket : public QTcpSocket
{
    Q_OBJECT

public:
    ClientSocket(QObject* parent = 0);
    
signals:
    LoginResult* onRegisterRequest(QString login, QString password);
    LoginResult* onLoginRequest(QString login, QString password);
    void onJoinGameRequest(UserInfo* user);

private slots:
    void readClient();
    void doUserJoinGame(QList<UserInfo> users);
    void doGameStart(GameStartAction action);
    void doUserMove(UserMoveAction userMoveAction);
private:
    quint16 nextBlockSize;

    void sendLoginRequest(LoginResult* login);
    void processRegisterRequest(QDataStream &stream);
    void processLoginRequest(QDataStream &stream);
    void processJoinGameRequest(QDataStream &stream);    
};

#endif // CLIENTSOCKET_H
