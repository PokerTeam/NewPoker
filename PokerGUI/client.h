#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include <QtNetwork/QTcpSocket>
#include<qnetworkinterface.h>
#include "../loginresult.h"
#include <QObject>
class Client : QObject
{
    Q_OBJECT
public:
    Client();
    void connectToServer();
public slots:
    void doRegisterRequest(QString username, QString password);
    void readClient();
signals:
    void onLoginResult(LoginResult* result);
private:
    QTcpSocket socket;
    quint16 nextBlockSize;

};

#endif // CLIENT_H
