#ifndef ACCOUNTMANAGER_H
#define ACCOUNTMANAGER_H

#include <user.h>
#include <QString>
#include <QObject>
#include "loginresult.h"

class AccountManager : public QObject
{
    Q_OBJECT

public:
    AccountManager();
    bool isPasswordCorrect(long userId, QString password);

private:
    User* loadUser(long userId);
    bool isUserWithSuchUsernameExists(QString username);
    void updateUser(User* updatedUser);

public slots:
    LoginResult* createNewUser(QString login, QString password);
    LoginResult* loginUser(QString login, QString password);
};

#endif // ACCOUNTMANAGER_H
