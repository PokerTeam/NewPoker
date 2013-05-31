#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QString>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/qnetworkinterface.h>
#include "loginresult.h"
#include "user.h"
#include "userinfo.h"
#include "gamestartaction.h"
#include "usermoveaction.h"
#include "useraction.h"
#include "bankchangeaction.h"
#include "firstcardsaction.h"
#include "gamefinish.h"

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
    void onUserAction(UserAction action);
    void onBankChange(BankChangeAction action);
    void onFirstCardsAction(FirstCardsAction action);
    void onNextCardDealed(Card);
    void onGameFinished(GameFinish action);

private:
    QTcpSocket socket;
    quint16 nextBlockSize;
};

#endif // CLIENT_H
