#include "server.h"
#include "qstringlist.h"
#include "cmath"
#include "clientsocket.h"
using namespace std;

Server::Server(Game* game, AccountManager* manager)
{
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    this->game = game;
    this->accountManager = manager;
    connect(this->thread(), SIGNAL(finished()), this, SLOT(deleteLater()) );
}

void Server::start(QHostAddress addr, qint16 port)
{
        SetConsoleTextAttribute(hConsole, 11);
        qDebug() << "    ppppp    ooo    k   k   eeeee   rrrr                      1       000000";
        qDebug() << "    p   p   o   o   k k     e       r   r        v     v    1 1       0    0";
        qDebug() << "    ppppp   o   o   kk      eeeee   rrrr          v   v       1       0    0";
        qDebug() << "    p       o   o   k k     e       r  r           v v        1  ..   0    0";
        qDebug() << "    p        ooo    k   k   eeeee   r   r           v         1  ..   000000";
        qDebug() << "\n";
        SetConsoleTextAttribute(hConsole, 10);
        cout<<"> ";
        QList<QHostAddress> allAddress = QNetworkInterface::allAddresses();
        QString addreses="{";
        for(int i = 0;i<allAddress.count();i++)
        {
            addreses+= allAddress[i].toString()+"; ";
            if(i==allAddress.count()-1)
            {
            addreses+= allAddress[i].toString()+"}";
            }
        }
        if (!listen(addr, port))
        {
            SetConsoleTextAttribute(hConsole, 12);

            outToConsole("Server not started at " + addreses+" and port - "+QString::number(port),12);

        }
        outToConsole("Server started at " + addreses+" and port - "+QString::number(port),10);
}

void Server::outToConsole(QString message, int color)
{
 SetConsoleTextAttribute(hConsole, color);
 cout<<"["<<QDate::currentDate().toString(Qt::LocalDate).toStdString()<<" "<<QTime::currentTime().toString(Qt::LocalDate).toStdString()<<"] " << message.toStdString()<<endl;
 SetConsoleTextAttribute(hConsole,10);
 cout<<"> ";
}

void Server::incomingConnection(int handle)
{
    qDebug() << "Connected";
    ClientSocket *client = new ClientSocket(this);
    client->setSocketDescriptor(handle);
    connect(client, SIGNAL(onRegisterRequest(QString,QString)), accountManager, SLOT(Registration(QString,QString)));
    connect(client, SIGNAL(onLoginRequest(QString,QString)), accountManager, SLOT(Login(QString,QString)));
    connect(client, SIGNAL(onJoinGameRequest(UserInfo*)), game, SLOT(joinGame(UserInfo*)));
    connect(game, SIGNAL(onUserJoinGame(QList<UserInfo>)), client, SLOT(doUserJoinGame(QList<UserInfo>)));
    connect(game, SIGNAL(gameStarted(GameStartAction)), client, SLOT(doGameStart(GameStartAction)));
    connect(game, SIGNAL(onUserMove(UserMoveAction)), client, SLOT(doUserMove(UserMoveAction)));
    connect(game, SIGNAL(onUserAction(UserAction)), client, SLOT(doUserAction(UserAction)));
    connect(game, SIGNAL(onBankChanged(BankChangeAction)), client, SLOT(doBankChangeAction(BankChangeAction)));
    connect(game, SIGNAL(onFirstCardsDealed(FirstCardsAction)), client, SLOT(doFirstCardsAction(FirstCardsAction)));
    connect(game, SIGNAL(onNextCardDealed(Card)), client, SLOT(doNextCardsDealed(Card)));
    connect(game, SIGNAL(onGameFinished(GameFinish)), client, SLOT(doGameFinished(GameFinish)));
    connect(client, SIGNAL(onUserAction(UserAction)), game, SLOT(doAction(UserAction)));
}


