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
    socket.waitForConnected();
}

void Client::doRegisterRequest(QString username, QString password){
    qDebug() << "Register req";
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_6);
    out << quint16(0) << quint16(Commands::registerNewUser) << username << password;
    out.device()->seek(0);
    out << quint16(block.size() - sizeof(quint16));
    socket.write(block);
    qDebug() << "Block size " << block.size() - sizeof(quint16);
    //socket.waitForBytesWritten();
    socket.flush();
}

void Client::doLoginRequest(QString username, QString password){
    qDebug() << "Login req";
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_6);
    out << quint16(0) << quint16(Commands::loginUser) << username << password;
    out.device()->seek(0);
    out << quint16(block.size() - sizeof(quint16));
    qDebug() << "Block size " << block.size() - sizeof(quint16);
    socket.write(block);
    //socket.waitForBytesWritten();
    socket.flush();
}

void Client::doJoinGameRequest(UserInfo* userInfo){
    qDebug() << "Join game req";
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_6);
    out << quint16(0) << quint16(Commands::joinGame) << userInfo;
    out.device()->seek(0);
    out << quint16(block.size() - sizeof(quint16));
    qDebug() << "Block size " << block.size() - sizeof(quint16);
    socket.write(block);
   // socket.waitForBytesWritten();
    socket.flush();
}

void Client::readClient(){
    qDebug() << "Client req";
    QDataStream in(&socket);
    in.setVersion(QDataStream::Qt_4_6);
        if (nextBlockSize == 0){
            if (socket.bytesAvailable() < sizeof(quint16)){
                return;
            }else{
                in >> nextBlockSize;
            }
        }

        if (socket.bytesAvailable() < nextBlockSize){
            return;
        }else{
            quint16 requestType;
            in >> requestType;
            qDebug() << requestType;
            switch(requestType){
                case Commands::loginResult:
                    qDebug() << "Login Result";
                    break;
                case Commands::joinGame:
                    qDebug() << "Join Result";
                    break;
            }
            //socket.close();
            nextBlockSize = 0;
        }
}
