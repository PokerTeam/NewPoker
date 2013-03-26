#ifndef REGISTERRESULT_H
#define REGISTERRESULT_H

#include <QString>
#include "userinfo.h"

class LoginResult
{
public:
    LoginResult(bool isSuccessed, QString message, UserInfo* user);
    bool getIsSuccessed();
    QString getMessage();
    UserInfo* getUser();

private:
    UserInfo* user;
    QString message;
    bool isSuccessed;
};

QDataStream &operator<<(QDataStream &out, LoginResult *&login);
QDataStream &operator>>(QDataStream &in, LoginResult *&login);

#endif // REGISTERRESULT_H
