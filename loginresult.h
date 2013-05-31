#ifndef REGISTERRESULT_H
#define REGISTERRESULT_H

#include <QString>
#include "userinfo.h"

class LoginResult
{
private:
    UserInfo user;
    QString message;
    bool isSuccessed;

public:
    LoginResult() { }
    LoginResult(bool isSuccessed, QString message, UserInfo user);
    bool getIsSuccessed();
    QString getMessage();
    UserInfo getUser();

    friend QDataStream &operator<<(QDataStream &out, LoginResult &login);
    friend QDataStream &operator>>(QDataStream &in, LoginResult &login);
};

#endif // REGISTERRESULT_H
