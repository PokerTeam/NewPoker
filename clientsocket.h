#ifndef CLIENTSOCKET_H
#define CLIENTSOCKET_H

#include <QObject>
#include <QTcpSocket>
#include "commands.h"
#include "loginresult.h"
#include "QDataStream"

class ClientSocket : public QTcpSocket
{
    Q_OBJECT
public:
    ClientSocket(QObject *parent = 0);
    
signals:
    LoginResult* onRegisterRequest(QString login, QString password);
    LoginResult* onLoginRequest(QString login, QString password);
    void onJoinGameRequest(UserInfo* user);
private slots:
    void readClient();
private:
    void sendLoginRequest(LoginResult* login);
    void processRegisterRequest(QDataStream &stream);
    void processLoginRequest(QDataStream &stream);
    void processJoinGameRequest(QDataStream &stream);
    quint16 nextBlockSize;
};

#endif // CLIENTSOCKET_H
