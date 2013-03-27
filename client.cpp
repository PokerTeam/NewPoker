#include "client.h"

Client::Client(int desc, Server *serv)
{
    //������� ��������� �� ������-������
    _serv = serv;

    //������ �� ������ �����������
    _isAutched = false;

    //������ ������������ ����� 0
    _blockSize = 0;

    //������� �����
    _sok = new QTcpSocket(this);

    //������������� ���������� �� incomingConnection()
    _sok->setSocketDescriptor(desc);

    //���������� �������
    connect(_sok, SIGNAL(disconnected()),
            this, SLOT(onDisconnect()));
    connect(_sok, SIGNAL(readyRead()),
            this, SLOT(onReadyRead()));
    connect(_sok, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(onError(QAbstractSocket::SocketError)));
    connect(this, SIGNAL(Login(QString,QString)),
            this, SLOT(doLogin(QString ,QString )));
    connect(this, SIGNAL(Registration(QString,QString)),
            this, SLOT(doRegistration(QString,QString)));
    connect(this, SIGNAL(SendCommandToCurrentUser(quint8,QString)),
            this, SLOT(doSendCommand(quint8,QString)));
    connect(this, SIGNAL(SendCommandToAll(quint8,QString)),
            this, SLOT(doSendCommandAll(quint8,QString)));
}

void Client::onReadyRead()
{
    QDataStream in(_sok);
    //���� ��������� ����� ���� ������ 2 ����� ��� ��� ������
    if (_blockSize == 0)
    {
        //���� ������ ������ 2 ���� ���� ���� ����� 2 �����
        if (_sok->bytesAvailable() < (int)sizeof(quint16))
        {
            return;
        }

        //��������� ������ (2 �����)
        in >> _blockSize;
        qDebug() << "_blockSize now " << _blockSize;
    }

    //���� ���� ���� ������� ���������
    if (_sok->bytesAvailable() < _blockSize)
    {
        return;
    }
    else
    {
        //����� ��������� ����� ����
        _blockSize = 0;
    }

    //3 ���� - ������� �������
    quint8 command;
    QString buf;
    in >> command>>buf;
    qDebug() << "Received command " << command;
    //��� ���������������� ������������� ����������� ������ ������� "������ �� �����������"
    if (!_isAutched &&
        (command != Commands::comAutchReq) &&
        (command != Commands::comRegAcc))
    {
        return;
    }

    switch(command)
    {
    //������ �� �����������
        case Commands::comAutchReq:
        {
            //��������� ���
            QString login, pass;
            login = buf.split(";")[0];
            pass = buf.split(";")[1];

            if(emit Login(login, pass))
            {
                _serv->outToConsole("connect " +
                                    login +
                                    " with ip address " +
                                    this->_sok->localAddress().toString(), 10);
                _isAutched = true;
                emit SendCommandToCurrentUser(Commands::comResultLogin, "1");
                QString userList;
                /*QList<Client*> clients = _serv->getClients();
                for(int i = 0; i < clients.count(); i++)
                {
                    userList += clients[i]->_user->getUsername() + ";";
                    if(i == clients.count() - 1)
                    {
                        userList += clients[i]->_user->getUsername();
                    }
                }*/
                emit SendCommandToAll(Commands::comSendList, userList);
            }
            else
            {
                _serv->outToConsole("Don't connect " +
                                    login +
                                    " with ip address " +
                                    this->_sok->localAddress().toString(), 12);
                emit SendCommandToCurrentUser(Commands::comResultLogin, "0");
            }
        }
            break;

        case Commands::comRegAcc:
        {
            QString login,pass;

            login = buf.split(";")[0];
            pass = buf.split(";")[1];
            if(emit Registration(login,pass))
            {
                _serv->outToConsole("Register successful Login: " +
                                    login +
                                    " Password: " +
                                    pass,10);
                emit SendCommandToCurrentUser(Commands::comResultReg, "1");
            }
            else
            {
                _serv->outToConsole("Register Bad", 12);
                emit SendCommandToCurrentUser(Commands::comResultReg, "0");
            }
        }
            break;

        //�� �������� ������������ ������ ��������� ��� ����
        default:
            break;
        }
}

void Client::onDisconnect()
{
    //���� �����������
    if (_isAutched)
    {
        _serv->outToConsole("Disconnect ", 12);
        //�������� ����, ��� ������ �����
        // _serv->doSendToAllUserLeft();
        //������� �� ������

    }
    emit removeUser(this);
    deleteLater();
}

void Client::onError(QAbstractSocket::SocketError socketError) const
{
    //w ����� ��� ������������� ������ �� QMessageBox (����������� *parent = &w)
    switch (socketError)
    {
        case QAbstractSocket::RemoteHostClosedError:
            break;

        case QAbstractSocket::HostNotFoundError:
            _serv->outToConsole("Error - The host was not found", 12);
            break;

        case QAbstractSocket::ConnectionRefusedError:
            _serv->outToConsole("Error - The connection was refused by the peer.", 12);
            break;

        default:
            _serv->outToConsole("Error - The following error occurred: " +
                                _sok->errorString(), 12);
    }
    //��� ��������� ���������� w � �������������� QMessageBox (�� �������� �++)
}
void Client::onAction(UserAction* userAction)
{

}

void Client::joinGame(UserInfo* user)
{

}

bool Client::doLogin(QString login, QString pass)
{
    _user = new User(1, login, pass, 1000);
    return true;
}

bool Client::doRegistration(QString login, QString pass)
{
    return true;
}

void Client::doSendCommandAll(quint8 command, QString container)
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out << (quint16)0;
    out << command;
    out << container;
    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));
    /*QList<Client*> _clients = _serv->getClients();
    for (int i = 0; i < _clients.count(); i++)
    {
        _clients[i]->_sok->write(block);
    }*/
}

void Client::doSendCommand(quint8 command, QString container)
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out << (quint16)0;
    out << command;
    out << container;
    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));
    _sok->write(block);
}
