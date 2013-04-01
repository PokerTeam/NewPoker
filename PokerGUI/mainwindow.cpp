#include "mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{    
    ui = new QDeclarativeView;
    client = new Client();
    client->connectToServer();
    connect(client, SIGNAL(onLoginResult(LoginResult*)), this, SLOT(OnLoginResult(LoginResult*)));
    connect(this, SIGNAL(joinGame(UserInfo*)), client, SLOT(doJoinGameRequest(UserInfo*)));
    SetLoginScreen();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SetupUI(QString path)
{
    ui->setSource(QUrl(path));
    ui->setResizeMode(QDeclarativeView::SizeRootObjectToView);
    setCentralWidget(ui);
    ui->rootContext()->setContextProperty("window", this);
}

void MainWindow::SetLoginScreen()
{
    SetupUI("qrc:/login.qml");
    root = ui->rootObject();    
    this->setMinimumWidth(360);
    this->setMinimumHeight(380);
    SetupLoginControls(root);
}

void MainWindow::SetupLoginControls(QObject *aRoot)
{
    SetupLoginTextAreas(aRoot);
    SetupLoginButtons(aRoot);
}

void MainWindow::SetupLoginTextAreas(QObject *aRoot)
{
    QObject* textArea = aRoot->findChild<QObject*>("textAreaLogin");
    textArea->setProperty("textContent", "");
    textArea->setProperty("textAreaHint", "");

    textArea = aRoot->findChild<QObject*>("textAreaPassword");
    textArea->setProperty("textContent", "");
    textArea->setProperty("textAreaHint", "");
}

void MainWindow::SetupLoginButtons(QObject *aRoot)
{
    QObject* button = aRoot->findChild<QObject*>("buttonLogin");
    QObject::connect(button, SIGNAL(buttonClick()),
                     this, SLOT(OnButtonLoginClick()));

    button = aRoot->findChild<QObject*>("buttonRegister");
    QObject::connect(button, SIGNAL(buttonClick()),
                     this, SLOT(OnButtonRegisterClick()));
}

void MainWindow::SetGameScreen()
{
    SetupUI("qrc:/game.qml");
    root = ui->rootObject();    
    this->setMinimumWidth(1024);
    this->setMinimumHeight(600);
    SetupGameControls(root);
}

void MainWindow::SetupGameControls(QObject *aRoot)
{
    SetupGameText(aRoot);
    SetupGameButtons(aRoot);
    SetupGameUserBlocks(aRoot);
    SetupGameCardImages(aRoot);
}

void MainWindow::SetupGameText(QObject *aRoot)
{
    QObject* text = aRoot->findChild<QObject*>("textRaiseValueObj");
    text->setProperty("raiseValue", "0");

    text = aRoot->findChild<QObject*>("textBankValueObj");
    text->setProperty("bankValue", "0");
}

void MainWindow::SetupGameButtons(QObject *aRoot)
{
    QObject* button = aRoot->findChild<QObject*>("buttonExit");
    QObject::connect(button, SIGNAL(buttonClick()),
                     this, SLOT(OnButtonExitClick()));

    button = aRoot->findChild<QObject*>("buttonFold");
    QObject::connect(button, SIGNAL(buttonClick()),
                     this, SLOT(OnButtonFoldClick()));

    button = aRoot->findChild<QObject*>("buttonCall");
    QObject::connect(button, SIGNAL(buttonClick()),
                     this, SLOT(OnButtonCallClick()));

    button = aRoot->findChild<QObject*>("buttonRaise");
    QObject::connect(button, SIGNAL(buttonClick()),
                     this, SLOT(OnButtonRaiseClick()));

    button = aRoot->findChild<QObject*>("buttonIncObj");
    QObject::connect(button, SIGNAL(buttonClick()),
                     this, SLOT(OnButtonRateIncClick()));

    button = aRoot->findChild<QObject*>("buttonDecObj");
    QObject::connect(button, SIGNAL(buttonClick()),
                     this, SLOT(OnButtonRateDecClick()));
}

void MainWindow::SetupGameUserBlocks(QObject *aRoot)
{
    QObject* user = aRoot->findChild<QObject*>("user1");
    user->setProperty("activeUser", false);
    user->setProperty("faildeUser", true);
    user->setProperty("userAvaImage", 0);

    user = aRoot->findChild<QObject*>("user2");
    user->setProperty("activeUser", false);
    user->setProperty("faildeUser", true);
    user->setProperty("userAvaImage", 0);

    user = aRoot->findChild<QObject*>("user3");
    user->setProperty("activeUser", false);
    user->setProperty("faildeUser", true);
    user->setProperty("userAvaImage", 0);

    user = aRoot->findChild<QObject*>("userSelf");
    user->setProperty("activeUser", false);
    user->setProperty("faildeUser", false);
    user->setProperty("userAvaImage", 4);
}

void MainWindow::SetupGameCardImages(QObject *aRoot)
{
    QObject* card = aRoot->findChild<QObject*>("cardImageSelf1");
    card->setProperty("currentFrame", 13);

    card = aRoot->findChild<QObject*>("cardImageSelf2");
    card->setProperty("currentFrame", 13);

    card = aRoot->findChild<QObject*>("card1");
    card->setProperty("currentFrame", 83);

    card = aRoot->findChild<QObject*>("card2");
    card->setProperty("currentFrame", 83);

    card = aRoot->findChild<QObject*>("card3");
    card->setProperty("currentFrame", 83);

    card = aRoot->findChild<QObject*>("card4");
    card->setProperty("currentFrame", 83);

    card = aRoot->findChild<QObject*>("card5");
    card->setProperty("currentFrame", 83);
}

void MainWindow::OnButtonLoginClick()
{
    QObject* textArea = root->findChild<QObject*>("textAreaLogin");
    QString login = textArea->property("textContent").toString();
    textArea = root->findChild<QObject*>("textAreaPassword");
    QString password = textArea->property("textContent").toString();
    client->doLoginRequest(login, password);
}

void MainWindow::OnLoginResult(LoginResult *loginResult)
{
    if (loginResult->getIsSuccessed()){
        userInfo = loginResult->getUser();
        emit joinGame(userInfo);
    }else{
        QObject* textArea = root->findChild<QObject*>("textAreaPassword");
        textArea->setProperty("textAreaHint", loginResult->getMessage());
    }
}

void MainWindow::OnButtonRegisterClick()
{

}

void MainWindow::OnButtonExitClick()
{

}

void MainWindow::OnButtonFoldClick()
{

}

void MainWindow::OnButtonCallClick()
{

}

void MainWindow::OnButtonRaiseClick()
{

}

void MainWindow::OnButtonRateIncClick()
{

}

void MainWindow::OnButtonRateDecClick()
{

}
