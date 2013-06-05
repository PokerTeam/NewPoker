#include <QtCore/QString>
#include <QtTest/QtTest>
#include <QtCore/QCoreApplication>

#include "../user.h"

class User_Test : public QObject
{
    Q_OBJECT
    
public:
    User_Test();
    
private Q_SLOTS:
    void getUserName();
    void getUserId();
    void getMoney();
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

QTEST_MAIN(User_Test)

#include "tst_user_test.moc"
