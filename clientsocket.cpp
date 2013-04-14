#include "clientsocket.h"

ClientSocket::ClientSocket(QObject *parent) :
    QTcpSocket(parent)
{
    connect(this, SIGNAL(readyRead()),
            this, SLOT(readClient()));
    connect(this, SIGNAL(disconnected()),
            this, SLOT(deleteLater()));
    nextBlockSize = 0;
}

void ClientSocket::readClient()
{
    //qDebug() << "Req";
    QDataStream in(this);
    in.setVersion(QDataStream::Qt_4_6);
    while (bytesAvailable() > 0)
    {
        if (nextBlockSize == 0)
        {
            if (bytesAvailable() < sizeof(quint16))
            {
                return;
            }
            else
            {
                in >> nextBlockSize;
            }
        }

        if (bytesAvailable() < nextBlockSize)
        {
            return;
        }
        else
        {
            quint16 requestType;
            in >> requestType;
            //qDebug() << bytesAvailable() << " " << nextBlockSize << " " << requestType;
            switch(requestType)
            {
                case Commands::registerNewUser:
                    processRegisterRequest(in);
                    break;

                case Commands::loginUser:
                    processLoginRequest(in);
                    break;

                case Commands::joinGame:
                    processJoinGameRequest(in);
                    break;

                case Commands::userAction:
                    processUserActionRequest(in);
                    break;
            }
            nextBlockSize = 0;
        }
    }
}

void ClientSocket::processRegisterRequest(QDataStream &stream)
{
    QString login;
    QString password;
    stream >> login >> password;
    LoginResult* result = emit onRegisterRequest(login, password);
    sendLoginRequest(result);
}

void ClientSocket::processLoginRequest(QDataStream &stream)
{
    QString login;
    QString password;
    stream >> login >> password;
    LoginResult* result = emit onLoginRequest(login, password);
    sendLoginRequest(result);
}

void ClientSocket::processJoinGameRequest(QDataStream &stream)
{
    UserInfo userInfo;
    stream >> userInfo;
    qDebug() << "Join game " << userInfo.getUserId();
    emit onJoinGameRequest(&userInfo);
}

void ClientSocket::processUserActionRequest(QDataStream &stream){
    UserAction action;
    stream >> action;
    emit onUserAction(action);
}

void ClientSocket::doUserJoinGame(QList<UserInfo> users){
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_6);
    out << quint16(0) << quint16(Commands::joinGame);
    out << qint32(users.size());
    foreach (UserInfo user, users){
        out << user;
    }
    out.device()->seek(0);
    out << quint16(block.size() - sizeof(quint16));
    write(block);
    flush();
    waitForBytesWritten(1000);
}

void ClientSocket::doGameStart(GameStartAction action){
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_6);
    out << quint16(0) << quint16(Commands::gameStart);
    out << action;
    out.device()->seek(0);
    out << quint16(block.size() - sizeof(quint16));
    write(block);
    flush();
    waitForBytesWritten(1000);
}

void ClientSocket::doUserMove(UserMoveAction userMoveAction){
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_6);
    out << quint16(0) << quint16(Commands::userMove);
    out << userMoveAction;
    out.device()->seek(0);
    out << quint16(block.size() - sizeof(quint16));
    write(block);
    flush();
    waitForBytesWritten(1000);
}

void ClientSocket::doUserAction(UserAction userAction){
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_6);
    out << quint16(0) << quint16(Commands::userAction);
    out << userAction;
    out.device()->seek(0);
    out << quint16(block.size() - sizeof(quint16));
    write(block);
    flush();
    waitForBytesWritten(1000);
}

void ClientSocket::doBankChangeAction(BankChangeAction action){
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_6);
    out << quint16(0) << quint16(Commands::bankChange);
    out << action;
    out.device()->seek(0);
    out << quint16(block.size() - sizeof(quint16));
    write(block);
    flush();
    waitForBytesWritten(1000);
}

void ClientSocket::sendLoginRequest(LoginResult* login)
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_6);
    out << quint16(0) << quint16(Commands::loginResult) << *login;
    out.device()->seek(0);
    out << quint16(block.size() - sizeof(quint16));
    write(block);
    flush();
    waitForBytesWritten(1000);
}
