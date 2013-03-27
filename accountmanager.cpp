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
    return new LoginResult(true, "",
                           new UserInfo(
                               new User(1, login, password, 1000)));
}

LoginResult* AccountManager::loginUser(QString login, QString password)
{
    return new LoginResult(true, "",
                           new UserInfo(
                               new User(1, login, password, 1000)));
}
