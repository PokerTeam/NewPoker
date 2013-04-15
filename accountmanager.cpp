#include "accountmanager.h"

AccountManager::AccountManager()
{
    dbase = QSqlDatabase::addDatabase("QSQLITE");
    dbase.setDatabaseName("UserDataBase.sqlite");
    dbase.open();
}

User* AccountManager::GetUser(QString userName)
{
    if(isUserWithSuchUsernameExists(userName))
    {
        return loadUser(getUserIdByUserName(userName));
    }
    return NULL;
}

User* AccountManager::GetUser(long userId)
{
    return loadUser(userId);
}

LoginResult* AccountManager::Login(QString userName, QString password)
{
    if(isUserWithSuchUsernameExists(userName))
    {
        User* user = loadUser(getUserIdByUserName(userName));
        if(isPasswordCorrect(user->getUserId(), password))
        {
            return new LoginResult(true, QString(""),
                 UserInfo(user->getUsername(), user->getUserId(), user->getMoney(), 0));
        }
    }
    return new LoginResult(false, QString("Incorrect username or password."), UserInfo());
}

LoginResult* AccountManager::Registration(QString userName, QString password)
{
    if(isUserWithSuchUsernameExists(userName))
    {
        return new LoginResult(false, QString("User already exists."), UserInfo());
    }
    User *newUser = new User(userName, password, 0);
    return createNewUser(newUser);
}

long AccountManager::getUserIdByUserName(QString userName)
{
    QSqlQuery query;
    query.exec(QString("select Id from users where name='"+userName+"'"));
    query.next();
    return query.value(0).toLongLong();
}

LoginResult* AccountManager::createNewUser(User *user)
{
    QSqlQuery query;
    if(query.exec(QString("insert into Users values(null,'"+
       user->getUsername()+"','"+user->getPassword()+"',"
       +QString::number(user->getMoney())+")")))
    {
        return new LoginResult(true, QString(""),
             UserInfo(user->getUsername(), user->getUserId(), user->getMoney(), 0));
    }
    return new LoginResult(false, QString("There was an error.Try again"), UserInfo());

}

User* AccountManager::loadUser(long userId)
{
    QSqlQuery query;
    query.exec(QString("select * from users where Id="+ QString::number(userId)));
    query.next();
    return new User(query.value(0).toLongLong(),
                    query.value(1).toString(),
                    query.value(2).toString(),
                    query.value(3).toLongLong());
}

bool AccountManager::isPasswordCorrect(long userId, QString password)
{
    QSqlQuery query;
    query.exec(QString("select Password from users where id="+QString::number(userId)));
    query.next();
    return query.value(0).toString() == password;
}

bool AccountManager::isUserWithSuchUsernameExists(QString username)
{
    QSqlQuery query;
    query.exec(QString("select Id from users where name = '"+username+ "'"));
    query.next();
    return query.value(0).isValid();
}

void AccountManager::updateUser(User *updatedUser)
{
    QSqlQuery query;
    QString s = "update users set Money="+QString::number(updatedUser->getMoney());
    query.exec(QString(s+" where id="+QString::number(updatedUser->getUserId())));
}
