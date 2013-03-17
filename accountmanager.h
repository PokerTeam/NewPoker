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
    bool isPasswordCorrect(long userId, QString password);
private:
    User* loadUser(long userId);
    bool isUserWithSuchUsernameExists(QString username);
    void updateUser(User* updatedUser);
public slots:
    void createNewUser(User* user);
signals:
    void onLoginResult(bool isSuccess, User* user);
    void onUserCreationResult(bool isSuccess, User* user);
};

#endif // ACCOUNTMANAGER_H
