#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QString>
#include <QtNetwork/QTcpSocket>
#include<qnetworkinterface.h>
#include "../loginresult.h"
#include "../user.h"
#include "../userinfo.h"
#include "../gamestartaction.h"
#include "../usermoveaction.h"
#include "../useraction.h"

class Client : public QObject
{
    Q_OBJECT

public:
    Client();
    void connectToServer();

public slots:
    void doRegisterRequest(QString username, QString password);
    void doLoginRequest(QString username, QString password);
    void doJoinGameRequest(UserInfo* userInfo);
    void doUserActionRequest(UserAction action);
    void readClient();

signals:
    void onLoginResult(LoginResult *result);
    void userJoinedGame(QList<UserInfo> users);
    void onGameStart(GameStartAction action);
    void onUserMove(UserMoveAction action);
private:
    QTcpSocket socket;
    quint16 nextBlockSize;
};

#endif // CLIENT_H
