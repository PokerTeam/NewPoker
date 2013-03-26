#include "loginresult.h"

LoginResult::LoginResult(bool isSuccessed, QString message, UserInfo* user){
    this->isSuccessed = isSuccessed;
    this->message = message;
    this->user = user;
}

bool LoginResult::getIsSuccessed(){
    return isSuccessed;
}

QString LoginResult::getMessage(){
    return message;
}

UserInfo* LoginResult::getUser(){
    return user;
}

QDataStream &operator<<(QDataStream &out, LoginResult *&login){
    out << login->getIsSuccessed()
        << login->getMessage()
        << login->getUser();
    return out;
}

QDataStream &operator>>(QDataStream &in, LoginResult *&login){
    bool isSuccess;
    QString message;
    UserInfo* user;
    in >> isSuccess >> message >> user;
    login = new LoginResult(isSuccess, message, user);
    return in;
}
