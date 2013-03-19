#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{    
    ui = new QDeclarativeView;    
    SetLoginScreen();
    SetGameScreen();
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
    this->setMaximumWidth(360);
    this->setMaximumHeight(380);
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
    this->setMaximumWidth(1920);
    this->setMaximumHeight(1080);
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
    QObject* text = aRoot->findChild<QObject*>("textRaiseValue");
    text->setProperty("raiseValue", "0");
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

    button = aRoot->findChild<QObject*>("buttonInc");
    QObject::connect(button, SIGNAL(buttonClick()),
                     this, SLOT(OnButtonRateIncClick()));

    button = aRoot->findChild<QObject*>("buttonDec");
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
    user->setProperty("userAvaImage", 1);
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
