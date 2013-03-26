#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QString>
#include <QtNetwork/QTcpSocket>
#include<qnetworkinterface.h>
#include "../loginresult.h"
#include "../user.h"
#include "../userinfo.h"

class Client : QObject
{
    Q_OBJECT

public:
    Client();
    void connectToServer();

public slots:
    void doRegisterRequest(QString username, QString password);
    void doLoginRequest(QString username, QString password);
    void doJoinGameRequest(UserInfo* userInfo);
    void readClient();

signals:
    void onLoginResult(LoginResult* result);

private:
    QTcpSocket socket;
    quint16 nextBlockSize;
};

#endif // CLIENT_H
