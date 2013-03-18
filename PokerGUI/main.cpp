#include <QtGui/QApplication>
#include "mainwindow.h"
#include "client.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Client* client = new Client();
    client->connectToServer();
    client->doRegisterRequest("user1", "password1");
    return a.exec();
}
