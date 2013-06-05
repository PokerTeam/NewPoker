#include <QtCore/QString>
#include <QtTest/QtTest>
#include <QtCore/QCoreApplication>

#include "../user.h"
#include "../userinfo.h"

class User_Test : public QObject
{
    Q_OBJECT
    
public:
    User_Test();
    
private Q_SLOTS:
    void getUserName();
    void getUserId();
    void getMoney();
    void isAllIn();
    void isNotAllIn();
    void putOnTable();
};

User_Test::User_Test()
{
}

void User_Test::getUserName()
{
    User user = User(1, "TestName", "", 2);
    QCOMPARE(user.getUsername(), QString("TestName"));
}

void User_Test::getUserId()
{
    User user = User(1, "TestName", "", 2);
    QCOMPARE(user.getUserId(), long(1));
}

void User_Test::getMoney()
{
    User user = User(1, "TestName", "", 2);
    QCOMPARE(user.getMoney(), long(2));
}

void User_Test::isAllIn(){
    UserInfo user = UserInfo("", 1, 100, 0);
    user.putOnTable(100);
    QCOMPARE(user.isAllIn(), true);
}

void User_Test::isNotAllIn(){
    UserInfo user = UserInfo("", 1, 100, 0);
    user.putOnTable(99);
    QCOMPARE(user.isAllIn(), false);
}

void User_Test::putOnTable(){
    UserInfo user = UserInfo("", 1, 100, 0);
    user.putOnTable(60);
    QCOMPARE(user.getUserMoneyOnTable(), long(60));
    QCOMPARE(user.getUserMoney(), long(40));
}

QTEST_MAIN(User_Test)

#include "tst_user_test.moc"
