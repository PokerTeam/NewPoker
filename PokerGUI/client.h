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
#include "../bankchangeaction.h"
#include "../firstcardsaction.h"
#include "../gamefinish.h"

class Client : public QObject
{
    Q_OBJECT

private:
    QTcpSocket socket;
    quint16 nextBlockSize;

public:
    Client();
    void ConnectToServer();

public slots:
    void DoRegisterRequest(QString username, QString password);
    void DoLoginRequest(QString username, QString password);
    void DoJoinGameRequest(UserInfo* userInfo);
    void DoUserActionRequest(UserAction action);
    void ReadClient();

signals:
    void OnLoginResult(LoginResult *result);
    void UserJoinedGame(QList<UserInfo> users);
    void OnGameStart(GameStartAction action);
    void OnUserMove(UserMoveAction action);
    void OnUserAction(UserAction action);
    void OnBankChange(BankChangeAction action);
    void OnFirstCardsAction(FirstCardsAction action);
    void OnNextCardDealed(Card);
    void OnGameFinished(GameFinish action);
};

#endif // CLIENT_H
