#include "mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{    
    this->setWindowTitle("Amaizing Poker");    
    ui = new QDeclarativeView;
    SetLoginScreen();

    client = new Client();
    client->ConnectToServer();
    connect(client, SIGNAL(OnLoginResult(LoginResult*)),
            this, SLOT(OnLoginResult(LoginResult*)));
    connect(this, SIGNAL(JoinGame(UserInfo*)),
            client, SLOT(DoJoinGameRequest(UserInfo*)));
    connect(client, SIGNAL(UserJoinedGame(QList<UserInfo>)),
            this, SLOT(OnUserJoinedGame(QList<UserInfo>)));
    connect(client, SIGNAL(OnGameStart(GameStartAction)),
            this, SLOT(OnGameStart(GameStartAction)));
    connect(client, SIGNAL(OnUserMove(UserMoveAction)),
            this, SLOT(OnUserMove(UserMoveAction)));
    connect(client, SIGNAL(OnUserAction(UserAction)),
            this, SLOT(OnUserAction(UserAction)));
    connect(client, SIGNAL(OnBankChange(BankChangeAction)),
            this, SLOT(OnBankChange(BankChangeAction)));
    connect(client, SIGNAL(OnFirstCardsAction(FirstCardsAction)),
            this, SLOT(OnFirstCardsAction(FirstCardsAction)));
    connect(client, SIGNAL(OnNextCardDealed(Card)),
            this, SLOT(OnNextCardDealed(Card)));
    connect(client, SIGNAL(OnGameFinished(GameFinish)),
            this, SLOT(OnGameFinished(GameFinish)));    
}

MainWindow::~MainWindow()
{
    delete client;
    delete ui;    
}

void MainWindow::SetupUI(QString path)
{
    this->setMinimumWidth(1024);
    this->setMinimumHeight(600);

    ui->setSource(QUrl(path));
    ui->setResizeMode(QDeclarativeView::SizeRootObjectToView);
    setCentralWidget(ui);
    ui->rootContext()->setContextProperty("window", this);
}

void MainWindow::SetLoginScreen()
{
    SetupUI("qrc:/login.qml");
    root = ui->rootObject();        
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
    button->setProperty("enabled", false);
    QObject::connect(button, SIGNAL(buttonClick()),
                     this, SLOT(OnButtonCallClick()));

    button = aRoot->findChild<QObject*>("buttonRaise");
    button->setProperty("enabled", false);
    QObject::connect(button, SIGNAL(buttonClick()),
                     this, SLOT(OnButtonRaiseClick()));

    button = aRoot->findChild<QObject*>("buttonCheck");
    button->setProperty("enabled", false);
    QObject::connect(button, SIGNAL(buttonClick()),
                     this, SLOT(OnButtonCheckClick()));

    button = aRoot->findChild<QObject*>("buttonIncObj");
    button->setProperty("enabled", false);
    QObject::connect(button, SIGNAL(buttonClick()),
                     this, SLOT(OnButtonRateIncClick()));

    button = aRoot->findChild<QObject*>("buttonDecObj");
    button->setProperty("enabled", false);
    QObject::connect(button, SIGNAL(buttonClick()),
                     this, SLOT(OnButtonRateDecClick()));
}

void MainWindow::SetupGameUserBlocks(QObject *aRoot)
{
    QObject* user = aRoot->findChild<QObject*>("user1");
    user->setProperty("activeUser", false);
    user->setProperty("failedUser", true);
    user->setProperty("userAvaImage", 0);
    user->setProperty("selfUser", false);

    user = aRoot->findChild<QObject*>("user2");
    user->setProperty("activeUser", false);
    user->setProperty("failedUser", true);
    user->setProperty("userAvaImage", 0);
    user->setProperty("selfUser", false);

    user = aRoot->findChild<QObject*>("user3");
    user->setProperty("activeUser", false);
    user->setProperty("failedUser", true);
    user->setProperty("userAvaImage", 0);    
    user->setProperty("selfUser", false);

    user = aRoot->findChild<QObject*>("user4");
    user->setProperty("activeUser", false);
    user->setProperty("failedUser", true);
    user->setProperty("userAvaImage", 0);
    user->setProperty("selfUser", false);

    user = aRoot->findChild<QObject*>("user5");
    user->setProperty("activeUser", false);
    user->setProperty("failedUser", true);
    user->setProperty("userAvaImage", 0);
    user->setProperty("selfUser", false);

    user = aRoot->findChild<QObject*>("user6");
    user->setProperty("activeUser", false);
    user->setProperty("failedUser", true);
    user->setProperty("userAvaImage", 0);
    user->setProperty("selfUser", false);

    user = aRoot->findChild<QObject*>("user7");
    user->setProperty("activeUser", false);
    user->setProperty("failedUser", true);
    user->setProperty("userAvaImage", 0);
    user->setProperty("selfUser", false);

    user = aRoot->findChild<QObject*>("user8");
    user->setProperty("activeUser", false);
    user->setProperty("failedUser", true);
    user->setProperty("userAvaImage", 0);
    user->setProperty("selfUser", false);
}

void MainWindow::SetupGameCardImages(QObject *aRoot)
{
    QObject* card = aRoot->findChild<QObject*>("card1");
    card->setProperty("currentFrame", 83);

    card = aRoot->findChild<QObject*>("card2");
    card->setProperty("currentFrame", 83);

    card = aRoot->findChild<QObject*>("card3");
    card->setProperty("currentFrame", 83);

    card = aRoot->findChild<QObject*>("card4");
    card->setProperty("currentFrame", 83);

    card = aRoot->findChild<QObject*>("card5");
    card->setProperty("currentFrame", 83);

    QObject* user = aRoot->findChild<QObject*>("user1");
    user->setProperty("card1", 83);
    user->setProperty("card2", 83);

    user = aRoot->findChild<QObject*>("user2");
    user->setProperty("card1", 83);
    user->setProperty("card2", 83);

    user = aRoot->findChild<QObject*>("user3");
    user->setProperty("card1", 83);
    user->setProperty("card2", 83);

    user = aRoot->findChild<QObject*>("user4");
    user->setProperty("card1", 83);
    user->setProperty("card2", 83);

    user = aRoot->findChild<QObject*>("user5");
    user->setProperty("card1", 83);
    user->setProperty("card2", 83);

    user = aRoot->findChild<QObject*>("user6");
    user->setProperty("card1", 83);
    user->setProperty("card2", 83);

    user = aRoot->findChild<QObject*>("user7");
    user->setProperty("card1", 83);
    user->setProperty("card2", 83);

    user = aRoot->findChild<QObject*>("user8");
    user->setProperty("card1", 83);
    user->setProperty("card2", 83);
}

void MainWindow::OnButtonLoginClick()
{
    QObject* textArea = root->findChild<QObject*>("textAreaLogin");
    QString login = textArea->property("textContent").toString();
    textArea = root->findChild<QObject*>("textAreaPassword");
    QString password = textArea->property("textContent").toString();
    client->DoLoginRequest(login, password);
}

void MainWindow::OnLoginResult(LoginResult* loginResult)
{
    if (loginResult->getIsSuccessed())
    {
        userInfo = (*loginResult).getUser();
        SetGameScreen();
        emit JoinGame(&userInfo);
    }
    else
    {
        QObject* textArea = root->findChild<QObject*>("textAreaPassword");
        textArea->setProperty("textAreaHint", loginResult->getMessage());
    }
}

void MainWindow::OnUserJoinedGame(QList<UserInfo> users)
{
    UpdateUsersInGame(users);
}

void MainWindow::OnGameStart(GameStartAction action)
{
    SetupGameCardImages(root);
    minimumBid = maximumBid = currentBid = cardsOnTable = 0;
    QObject* ui = root->findChild<QObject*>("textBankValueObj");
    ui->setProperty("bankValue", "0");
    userAdditionalInfo.clear();
    usersInGame[action.getBigBlind().getUserId()] = action.getBigBlind();
    usersInGame[action.getSmallBlind().getUserId()] = action.getSmallBlind();
    usersInGame[action.getUserWithButton().getUserId()] = action.getUserWithButton();
    AppendInfo(action.getBigBlind().getUserId(), "Big");
    AppendInfo(action.getSmallBlind().getUserId(), "Small");
    AppendInfo(action.getUserWithButton().getUserId(), "Btn");

    foreach (UserCardSet set, action.getCards())
    {
        if (set.getUser().getUserId() == userInfo.getUserId())
        {
            QObject* cardUI;

            cardUI = root->findChild<QObject*>("cardImageSelf1");
            cardUI->setProperty("currentFrame", Card::getCardImage(set.getFirstCard()));

            cardUI = root->findChild<QObject*>("cardImageSelf2");
            cardUI->setProperty("currentFrame", Card::getCardImage(set.getSecondCard()));
        }
    }

    UpdateUsers();
}

void MainWindow::OnUserMove(UserMoveAction action)
{
    QObject* button;
    button = root->findChild<QObject*>("buttonCall");
    button->setProperty("enabled", false);

    button = root->findChild<QObject*>("buttonRaise");
    button->setProperty("enabled", false);

    button = root->findChild<QObject*>("buttonCheck");
    button->setProperty("enabled", false);

    button = root->findChild<QObject*>("buttonIncObj");
    button->setProperty("enabled", false);

    button = root->findChild<QObject*>("buttonDecObj");
    button->setProperty("enabled", false);

    minimumBid = action.getMinimumBid();
    currentBid = minimumBid;
    maximumBid = action.getUserInfo().getUserMoney();
    if (userInfo.getUserId() == action.getUserInfo().getUserId())
    {
        userInfo = action.getUserInfo();
        foreach(Actions item, action.getAvailableActions())
        {
            switch (item)
            {
                case CHECK:
                {
                    button = root->findChild<QObject*>("buttonCheck");
                    button->setProperty("enabled", true);
                    break;
                }

                case CALL:
                {
                    button = root->findChild<QObject*>("buttonCall");
                    button->setProperty("enabled", true);
                    break;
                }

                case RAISE:
                {
                    button = root->findChild<QObject*>("buttonIncObj");
                    button->setProperty("enabled", true);
                    button = root->findChild<QObject*>("buttonDecObj");
                    button->setProperty("enabled", true);
                    QObject* bankText = root->findChild<QObject*>("textRaiseValueObj");
                    bankText->setProperty("raiseValue", QString("%1").arg(action.getMinimumBid()));
                    currentBid = action.getMinimumBid();
                    break;
                }

                default:
                    break;
            }
        }
    }
    QObject* userUI = usersUI[action.getUserInfo().getUserId()];
    foreach (QObject* itemUI, usersUI.values())
    {
        itemUI->setProperty("activeUser", false);
    }
    userUI->setProperty("activeUser", true);
    userUI->setProperty("labelUsercash", QString("%1 (%2)").arg(action.getUserInfo().getUserMoney()).arg(action.getUserInfo().getUserMoneyOnTable()));
}

void MainWindow::AppendInfo(long userId, QString info)
{
    userAdditionalInfo[userId] = QString("%1%2").arg(userAdditionalInfo.contains(userId) ? userAdditionalInfo[userId] + ", " : "").arg(info);
}

long MainWindow::GetAvaliblePosition()
{
    for (long i = 1; i <= 8; i++)
    {
        if (!usersByPosition.contains(i))
        {
            return i;
        }
    }
    return -1;
}

void MainWindow::UpdateUsersInGame(QList<UserInfo> users)
{
    SetupGameUserBlocks(root);
    foreach (UserInfo user, users)
    {
        long place = GetAvaliblePosition();
        int userId = user.getUserId();
        if (!usersUI.contains(userId))
        {
            if (userId == userInfo.getUserId())
            {
                usersUI[userId] = root->findChild<QObject*>(GetUserFieldName(place));
                usersUI[userId]->setProperty("userAvaImage", 1 + rand() % 5);
                usersUI[userId]->setProperty("selfUser", true);
                usersByPosition[place] = userId;
                usersInGame[userId] = user;
            }
            else
            {
                usersUI[userId] = root->findChild<QObject*>(GetUserFieldName(place));
                usersUI[userId]->setProperty("userAvaImage", 1 + rand() % 5);
                usersByPosition[place] = userId;
                usersInGame[userId] = user;
            }
        }
    }
    UpdateUsers();
}

void MainWindow::UpdateUsers()
{
    foreach(long key, usersInGame.keys())
    {
        QObject* userUI = usersUI[key];
        QString info = userAdditionalInfo.contains(key) ? "(" + userAdditionalInfo[key] + ")" : "";
        userUI->setProperty("labelUsername",
                            QString("%1 %2").arg(usersInGame[key].getUsername()).arg(info));
        userUI->setProperty("labelUsercash",
                            QString("%1 (%2)").arg(usersInGame[key].getUserMoney()).arg(usersInGame[key].getUserMoneyOnTable()));
    }
}

QString MainWindow::GetUserFieldName(long position)
{
    return QString("user%1").arg(position);
}

void MainWindow::OnButtonRegisterClick()
{
    QObject* textArea = root->findChild<QObject*>("textAreaLogin");
    QString login = textArea->property("textContent").toString();
    textArea = root->findChild<QObject*>("textAreaPassword");
    QString password = textArea->property("textContent").toString();
    client->DoRegisterRequest(login, password);
}

void MainWindow::OnUserAction(UserAction action)
{
    QObject* ui = usersUI[action.getUser().getUserId()];
    if (action.getAction() == FOLD)
    {
        ui->setProperty("labelUsername", "FOLD");
        ui->setProperty("labelUsercash", "");
    }
    if (userInfo.getUserId() == action.getUser().getUserId())
    {
        userInfo = action.getUser();
    }
    usersInGame[action.getUser().getUserId()] = action.getUser();
    UpdateUsers();
}

void MainWindow::OnBankChange(BankChangeAction action)
{
    QObject* ui = root->findChild<QObject*>("textBankValueObj");
    ui->setProperty("bankValue", QString("%1").arg(action.getBankValue()));
    foreach (long key, usersInGame.keys())
    {
        usersInGame[key].clearMoneyOnTable();
    }
    UpdateUsers();
}

void MainWindow::OnFirstCardsAction(FirstCardsAction action)
{
    cardsOnTable = 3;
    QObject* cardUI;

    cardUI = root->findChild<QObject*>("card1");
    cardUI->setProperty("currentFrame", Card::getCardImage(action.getFirstCard()));

    cardUI = root->findChild<QObject*>("card2");
    cardUI->setProperty("currentFrame", Card::getCardImage(action.getSecondCard()));

    cardUI = root->findChild<QObject*>("card3");
    cardUI->setProperty("currentFrame", Card::getCardImage(action.getThirdCard()));
}

void MainWindow::OnNextCardDealed(Card card)
{
    cardsOnTable++;
    QObject* cardUI;
    switch (cardsOnTable)
    {
        case 4:
            cardUI = root->findChild<QObject*>("card4");
            cardUI->setProperty("currentFrame", Card::getCardImage(card));
            break;

        case 5:
            cardUI = root->findChild<QObject*>("card5");
            cardUI->setProperty("currentFrame", Card::getCardImage(card));
            break;

        case 6:
            cardUI = root->findChild<QObject*>("card6");
            cardUI->setProperty("currentFrame", Card::getCardImage(card));
            break;

        default:
            break;
    }
}

void MainWindow::OnGameFinished(GameFinish action){
    foreach(UserCardSet set, action.getWinners())
    {
        foreach(long position, usersByPosition.keys())
        {
            if (usersByPosition[position] == set.getUser().getUserId())
            {
                QObject* userBlock = usersUI[position];
                userBlock->setProperty("card1", Card::getCardImage(set.getFirstCard()));
                userBlock->setProperty("card2", Card::getCardImage(set.getSecondCard()));
            }
        }
    }
}

void MainWindow::OnButtonExitClick()
{

}

void MainWindow::OnButtonFoldClick()
{
    client->DoUserActionRequest(UserAction(userInfo, FOLD, -1));
}

void MainWindow::OnButtonCallClick()
{
    if (minimumBid != 0)
    {
        client->DoUserActionRequest(UserAction(userInfo, CALL, minimumBid));
    }
    else
    {
        client->DoUserActionRequest(UserAction(userInfo, CHECK, 0));
    }
}

void MainWindow::OnButtonRaiseClick()
{
    client->DoUserActionRequest(UserAction(userInfo, RAISE, currentBid));
}

void MainWindow::OnButtonCheckClick()
{
    client->DoUserActionRequest(UserAction(userInfo, CHECK, 0));
}

void MainWindow::OnButtonRateIncClick()
{
    currentBid++;
    if (currentBid > maximumBid )
    {
        currentBid = maximumBid;
    }
    if (currentBid > minimumBid)
    {
        QObject* button = root->findChild<QObject*>("buttonRaise");
        button->setProperty("enabled", true);
    }
    UpdateRateUI();
}

void MainWindow::OnButtonRateDecClick()
{
    currentBid--;
    if (currentBid < minimumBid )
    {
        currentBid = minimumBid;
    }
    if (currentBid == minimumBid)
    {
        QObject* button = root->findChild<QObject*>("buttonRaise");
        button->setProperty("enabled", false);
    }
    UpdateRateUI();
}

void MainWindow::UpdateRateUI()
{
    QObject* text = root->findChild<QObject*>("textRaiseValueObj");
    text->setProperty("raiseValue", QString("%1").arg(currentBid));
}
