#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>
#include <QtGui/QMainWindow>
#include <QtDeclarative/QDeclarativeView>
#include <QtDeclarative/QDeclarativeContext>
#include <QGraphicsObject>
#include "client.h"
#include "../userinfo.h"

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QDeclarativeView *ui;
    QObject *root;
    Client *client;

    UserInfo userInfo;
    QMap<long, long> usersByPosition;
    QMap<long, UserInfo> usersInGame;
    QMap<long, QObject*> usersUI;
    QMap<long, QString> userAdditionalInfo;

    long minimumBid;
    long maximumBid;
    long currentBid;
    UserMoveAction lastAction;
    long cardsOnTable;

    void SetupUI(QString path);
    void SetLoginScreen();
    void SetupLoginControls(QObject *aRoot);
    void SetupLoginTextAreas(QObject *aRoot);
    void SetupLoginButtons(QObject *aRoot);

    void SetGameScreen();
    void SetupGameControls(QObject *aRoot);
    void SetupGameText(QObject *aRoot);
    void SetupGameButtons(QObject *aRoot);
    void SetupGameUserBlocks(QObject *aRoot);
    void SetupGameCardImages(QObject *aRoot);

    void UpdateUsersInGame(QList<UserInfo> users);
    void UpdateUsers();
    QString GetUserFieldName(long position);
    long GetAvaliblePosition();
    void AppendInfo(long userId, QString info);
    void UpdateRateUI();

signals:
    void JoinGame(UserInfo*);

private slots:
    void OnButtonLoginClick();
    void OnLoginResult(LoginResult*);
    void OnUserJoinedGame(QList<UserInfo> users);
    void OnButtonRegisterClick();
    void OnGameStart(GameStartAction);
    void OnUserMove(UserMoveAction);
    void OnUserAction(UserAction);
    void OnBankChange(BankChangeAction action);
    void OnFirstCardsAction(FirstCardsAction action);
    void OnNextCardDealed(Card);
    void OnGameFinished(GameFinish);

    void OnButtonExitClick();
    void OnButtonFoldClick();
    void OnButtonCallClick();
    void OnButtonRaiseClick();
    void OnButtonCheckClick();
    void OnButtonRateIncClick();
    void OnButtonRateDecClick();
};

#endif // MAINWINDOW_H
