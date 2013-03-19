#include <QtGui/QApplication>
#include "mainwindow.h"
#include "client.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Client* client = new Client();
    client->connectToServer();
    client->doRegisterRequest("user1", "password1");
    client->doLoginRequest("user2", "password2");
    client->doJoinGameRequest(new UserInfo(new User(123, "USERN", "PASWD")));
    return a.exec();
}
