#ifndef ACCOUNTMANAGER_H
#define ACCOUNTMANAGER_H
#include <user.h>
#include <QString>
#include <QObject>
class AccountManager : QObject
{
    Q_OBJECT
public:
    AccountManager();
private:
    long createNewUser(User* user);
    User* loadUser(long userId);
    bool isPasswordCorrect(long userId, QString password);
    bool isUserWithSuchUsernameExists(QString username);
    void updateUser(User* updatedUser);
signals:
    void onUserCreation();
    void onLoginFailed();
    void onLoginSuccessed();
};

#endif // ACCOUNTMANAGER_H
