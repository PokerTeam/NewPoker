#include "accountmanager.h"

AccountManager::AccountManager()
{
    users.push_back(User(1, "qwe", "123", 1000));
    users.push_back(User(2, "qwe1", "123", 1000));
    users.push_back(User(3, "qwe2", "123", 1000));
    users.push_back(User(4, "qwe3", "123", 1000));
}

bool AccountManager::isPasswordCorrect(long userId, QString password)
{
    //TODO: Add Logic.
    return true;
}

LoginResult* AccountManager::createNewUser(QString login, QString password)
{
    User* user = loadUser(login);
    if (user != NULL){
        return new LoginResult(false, QString("User already exists."), UserInfo());
    }else{
        User user = User(users.count() + 1, login, password, 1000);
        users.push_back(user);
        return new LoginResult(true, QString(""),
                                UserInfo(user.getUserId(), user.getMoney(), 0));
    }
}

LoginResult* AccountManager::loginUser(QString login, QString password)
{
    User* user = loadUser(login);
    if (user == NULL){
        return new LoginResult(false, QString("Incorrect username."), UserInfo());
    }else{
        if (user->getPassword() == password){
            return new LoginResult(true, QString(""),
                                    UserInfo(user->getUserId(), user->getMoney(), 0));
        }else{
            return new LoginResult(false, QString("Incorrect password."), UserInfo());
        }
    }
}

User* AccountManager::loadUser(QString login){
    foreach(User user, users){
        if (user.getUsername() == login){
            return &user;
        }
    }
    return NULL;
}
