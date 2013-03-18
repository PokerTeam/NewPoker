#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{    
    ui = new QDeclarativeView;
    SetGameScreen();
    //SetLoginScreen();
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
}

void MainWindow::SetupGameControls(QObject *aRoot)
{

}

void MainWindow::SetupGameTextAreas(QObject *aRoot)
{

}

void MainWindow::SetupGameButtons(QObject *aRoot)
{

}

void MainWindow::OnButtonLoginClick()
{

}

void MainWindow::OnButtonRegisterClick()
{

}
