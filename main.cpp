#include <QtCore/QCoreApplication>
#include "server.h"
#include "game.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    AccountManager* accountManager = new AccountManager();
    Server* server = new Server(new Game(accountManager), accountManager);
    server->start(QHostAddress::Any, 1234);

    return a.exec();
}
