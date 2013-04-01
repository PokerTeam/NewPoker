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
    UserInfo* userInfo;

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
signals:
    void joinGame(UserInfo*);
private slots:
    void OnButtonLoginClick();
    void OnLoginResult(LoginResult*);
    void OnButtonRegisterClick();

    void OnButtonExitClick();
    void OnButtonFoldClick();
    void OnButtonCallClick();
    void OnButtonRaiseClick();
    void OnButtonRateIncClick();
    void OnButtonRateDecClick();
};

#endif // MAINWINDOW_H
