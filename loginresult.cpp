#include "loginresult.h"

LoginResult::LoginResult(bool isSuccessed,
                         QString message,
                         UserInfo user)
{
    this->isSuccessed = isSuccessed;
    this->message = message;
    this->user = user;
}

bool LoginResult::getIsSuccessed()
{
    return isSuccessed;
}

QString LoginResult::getMessage()
{
    return message;
}

UserInfo LoginResult::getUser()
{
    return user;
}

QDataStream &operator<<(QDataStream &out,
                        LoginResult &login)
{
    UserInfo usr = login.getUser();
    out << login.getIsSuccessed()
        << login.getMessage()
        << usr;
    return out;
}

QDataStream &operator>>(QDataStream &in,
                        LoginResult &login)
{
    in >> login.isSuccessed >> login.message >> login.user;
    //login = new LoginResult(isSuccess, message, &user);
    return in;
}
