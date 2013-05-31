#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QtNetwork/QTcpSocket>

#include "qstringlist.h"
#include "server.h"
#include "commands.h"
#include "user.h"
#include "useraction.h"
#include "userinfo.h"
#include "gamestartaction.h"
#include "usermoveaction.h"
#include "card.h"
#include "firstcardsaction.h"
#include "userleaveaction.h"
#include "bankchangeaction.h"

class Server;

class Client : QObject
{
friend class Server;

    Q_OBJECT

private:
    QTcpSocket *_sok;
    Server *_serv;
    User * _user;
    quint16 _blockSize;
    bool _isAutched;

public:
        //Конструктор для сервера
    Client(int desc, Server *serv);

    void ConnectToHost(QHostAddress address, qint16 port);

private slots:
    void onReadyRead();
    void onDisconnect();
    void onError(QAbstractSocket::SocketError socketError) const;

public slots:
    bool doLogin(QString login, QString pass);
    bool doRegistration(QString login, QString pass);
    void doSendCommand(quint8 command, QString container);
    void doSendCommandAll(quint8 command, QString container);
    void onAction(UserAction* userAction);
    void joinGame(UserInfo* user);

signals:
    bool Login(QString name, QString pass);
    bool Registration(QString name, QString pass);
    void removeUser(Client *client);
    void SendCommandToCurrentUser(quint8 command, QString container);
    void SendCommandToAll(quint8 command, QString container);

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
