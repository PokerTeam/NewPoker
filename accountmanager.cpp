#include "accountmanager.h"

AccountManager::AccountManager()
{

}

bool AccountManager::isPasswordCorrect(long userId, QString password)
{
    //TODO: Add Logic.
    return true;
}

LoginResult* AccountManager::createNewUser(QString login, QString password)
{
    return new LoginResult(true, QString(""),
                           UserInfo(1, 1000, 0));
}

LoginResult* AccountManager::loginUser(QString login, QString password)
{
    return new LoginResult(true, QString(""),
                           UserInfo(1, 1000, 0));
}
