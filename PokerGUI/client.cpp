#include <QDebug>
#include "client.h"
#include "../commands.h"

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
    socket.flush();
    socket.waitForBytesWritten(1000);
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
    socket.flush();
    socket.waitForBytesWritten(1000);
}

void Client::doJoinGameRequest(UserInfo* userInfo){
    qDebug() << "Join game req";
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_6);
    out << quint16(0) << quint16(Commands::joinGame) << *userInfo;
    out.device()->seek(0);
    out << quint16(block.size() - sizeof(quint16));
    qDebug() << "Block size " << block.size() - sizeof(quint16);
    socket.write(block);
    socket.flush();
    socket.waitForBytesWritten(1000);
}

void Client::doUserActionRequest(UserAction action){
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_6);
    out << quint16(0) << quint16(Commands::userAction) << action;
    out.device()->seek(0);
    out << quint16(block.size() - sizeof(quint16));
    socket.write(block);
    socket.flush();
    socket.waitForBytesWritten(1000);
}

void Client::readClient(){
    qDebug() << endl <<"Client req, Avalible: " << socket.bytesAvailable() << ", next: " << nextBlockSize;
    QDataStream in(&socket);
    in.setVersion(QDataStream::Qt_4_6);
    while (socket.bytesAvailable() > 0){
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
            qDebug() << requestType << " Size: " << socket.bytesAvailable() << " next: " << nextBlockSize;
            switch(requestType){
            case Commands::loginResult:
            {
                LoginResult result;
                in >> result;
                emit onLoginResult(&result);
                break;
            }
            case Commands::gameStart:{
                GameStartAction action;
                in >> action;
                emit onGameStart(action);
                break;
            }
            case Commands::userMove:{
                UserMoveAction action;
                in >> action;
                emit onUserMove(action);
                break;
            }
            case Commands::userAction:{
                UserAction action;
                in >> action;
                emit onUserAction(action);
                break;
            }
            case Commands::joinGame:{
                {
                    QList<UserInfo> list;
                    qint32 size;
                    in >> size;
                    for (quint32 i = 0; i < size; i++){
                        UserInfo userInfo;
                        in >> userInfo;
                        list.push_back(userInfo);
                    }
                    emit userJoinedGame(list);
                }
                break;
            }
            }
            /*Stub
            char *arr;

            uint len = (uint)(quint32(nextBlockSize) - quint32(bytesBeforeRead) - quint32(socket.bytesAvailable()));
            in.readBytes(arr, len);
            /*To process bytes*/
            //socket.close();
            nextBlockSize = 0;
        }
    }
}
