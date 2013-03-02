#ifndef USER_H
#define USER_H
#include <QString>
class User
{
public:
    User(long userId, QString username, QString password, long money = 0);
    long getUserId();
    QString getUsername();
    QString getPassword();
    long getMoney();
    void setMoney(long newValue);
private:
    long userId;
    QString username;
    QString password;
    long money; //Need to move this field to separate class(When we will do refactoring).
};

#endif // USER_H
