#include "accountmanager.h"

AccountManager::AccountManager()
{
}

bool AccountManager::isPasswordCorrect(long userId, QString password){
    return true; //TODO: Add Logic.
}

LoginResult* AccountManager::createNewUser(QString login, QString password){
    return new LoginResult(true, "", new UserInfo(new User(1, login, password, 1000)));
}

LoginResult* AccountManager::loginUser(QString login, QString password){
    return new LoginResult(true, "", new UserInfo(new User(1, login, password, 1000)));
}
