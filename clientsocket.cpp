#include "clientsocket.h"

ClientSocket::ClientSocket(QObject *parent) :
    QTcpSocket(parent)
{
    connect(this, SIGNAL(readyRead()), this, SLOT(readClient()));
    connect(this, SIGNAL(disconnected()), this, SLOT(deleteLater()));
    nextBlockSize = 0;
}


void ClientSocket::readClient(){
    QDataStream in(this);
    in.setVersion(QDataStream::Qt_4_6);

    if (nextBlockSize == 0){
        if (bytesAvailable() < sizeof(quint16)){
            return;
        }else{
            in >> nextBlockSize;
        }
    }

    if (bytesAvailable() < nextBlockSize){
        return;
    }else{
        quint16 requestType;
        in >> requestType;
        qDebug() << requestType;
        switch(requestType){
            case Commands::registerNewUser:
                processRegisterRequest(in);
                break;
        }
        close();
    }

}

void ClientSocket::processRegisterRequest(QDataStream &stream){
    QString login;
    QString password;
    stream >> login >> password;
    qDebug() << "Login/Password on server = " << login << "/" << password;
    LoginResult* result = new LoginResult(false, "IncorrectPassword", NULL);//emit onRegisterRequest(login, password);
    sendLoginRequest(result);
    QDataStream out(this);
    out << quint16(0xFFFF);
}

void ClientSocket::sendLoginRequest(LoginResult* login){
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_6);
    out << quint16(0) << quint16(Commands::loginUser) << login;
    out.device()->seek(0);
    out << quint16(block.size() - sizeof(quint16));
    write(block);
}
