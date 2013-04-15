#ifndef ACCOUNTMANAGER_H
#define ACCOUNTMANAGER_H

#include <user.h>
#include <QString>
#include <QObject>
#include <QtSql/QtSql>
#include "loginresult.h"

class AccountManager : public QObject
{
    Q_OBJECT

public:
    AccountManager();
    User* GetUser(QString userName);
    User* GetUser(long userId);
    void updateUser(User* updatedUser);

private:
    QSqlDatabase dbase;
    User* loadUser(long userId);
    LoginResult* createNewUser(User* user);
    bool isUserWithSuchUsernameExists(QString username);
    long getUserIdByUserName(QString userName);
    bool isPasswordCorrect(long userId, QString password);

public slots:
    LoginResult* Login(QString userName, QString password);
    LoginResult* Registration(QString userName, QString password);
};

#endif // ACCOUNTMANAGER_H
