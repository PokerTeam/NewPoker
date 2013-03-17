#include "server.h"
#include "qstringlist.h"
#include "cmath"
using namespace std;

Server::Server()
{
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    connect( this->thread(), SIGNAL(finished()), this, SLOT(deleteLater()) );
}

void Server::start(QHostAddress addr, qint16 port)
{
    Game* game = new Game(NULL);
    connect(this, SIGNAL(joinGame(UserInfo*)),game, SLOT(joinGame(UserInfo*)));
    emit joinGame(new UserInfo(1,2,3));
        SetConsoleTextAttribute(hConsole, 11);
        qDebug()<<"    ppppp    ooo    k   k   eeeee   rrrr                      1       000000";
        qDebug()<<"    p   p   o   o   k k     e       r   r        v     v    1 1       0    0";
        qDebug()<<"    ppppp   o   o   kk      eeeee   rrrr          v   v       1       0    0";
        qDebug()<<"    p       o   o   k k     e       r  r           v v        1  ..   0    0";
        qDebug()<<"    p	     ooo    k   k   eeeee   r   r           v         1  ..   000000";
        qDebug()<<"\n";
        SetConsoleTextAttribute(hConsole, 10);
        cout<<"> ";
        QList<QHostAddress> allAddress = QNetworkInterface::allAddresses();
        QString addreses="{";
        for(int i = 0;i<allAddress.count();i++)
        {
            addreses+= allAddress[i].toString()+";";
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
         Client *client = new Client(handle, this);
         if(_clients.count()<7)
          {
             connect(client, SIGNAL(removeUser(Client*)), this, SLOT(onRemoveUser(Client*)));
            _clients.append(client);
          }
         else
         {
           //client->doSendCommand(Client::comErrFull);
         }

}

void Server::onUserJoinGame(UserInfo* user){

}

void Server::onGameStarted(GameStartAction* gameStartAction){

}

void Server::onUserMove(UserMoveAction* userMoveAction){

}

void Server::onFirstCardsDealed(FirstCardsAction* firstCardsAction){

}

void Server::onNextCardDealed(Card* nextCard){

}

void Server::onGameFinished(UserInfo* winner){

}

void Server::onGameStopped(){

}

void Server::onUserAction(UserAction* userAction){

}

void Server::onUserLeaveGame(UserLeaveAction* userLeaveAction){

}

void Server::onBankChanged(BankChangeAction* bankChangeAction){

}
void Server::onRemoveUser(Client *client)
{
    _clients.removeAt(_clients.indexOf(client));
}

