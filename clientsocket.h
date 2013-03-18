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
private slots:
    void readClient();
private:
    void sendLoginRequest(LoginResult* login);
    void processRegisterRequest(QDataStream &stream);
    quint16 nextBlockSize;
};

#endif // CLIENTSOCKET_H
