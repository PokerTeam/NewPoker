
#include <QtCore/QCoreApplication>
#include "server.h"
#include "game.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    Server* server = new Server();
    server->start();

    return a.exec();
}
