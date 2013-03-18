#include "client.h"
#include "../commands.h"
#include <QDebug>
Client::Client()
{
    connect(&socket, SIGNAL(readyRead()), this, SLOT(readClient()));
}

void Client::connectToServer(){
    socket.connectToHost(QHostAddress::LocalHost, 1234);
    nextBlockSize = 0;
}

void Client::doRegisterRequest(QString username, QString password){
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_6);
    out << quint16(0) << quint16(Commands::registerNewUser) << username << password;
    out.device()->seek(0);
    out << quint16(block.size() - sizeof(quint16));
    socket.write(block);
}

void Client::readClient(){
    qDebug() << "Response from server";
}
