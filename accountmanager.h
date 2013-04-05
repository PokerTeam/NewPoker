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
    User* loadUser(QString login);
    bool isUserWithSuchUsernameExists(QString username);
    void updateUser(User* updatedUser);
    QList<User> users; //Remove when DB will be implemented.

public slots:
    LoginResult* createNewUser(QString login, QString password);
    LoginResult* loginUser(QString login, QString password);
};

#endif // ACCOUNTMANAGER_H
