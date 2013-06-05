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
    void putOnTable_data();
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

void User_Test::putOnTable_data()
{
    QTest::addColumn<long>("money");
    QTest::addColumn<long>("put");
    QTest::addColumn<long>("result");

    QTest::newRow("money_data_1") << long(100) << long(10) << long(90);
    QTest::newRow("money_data_2") << long(30) << long(1) << long(29);
    QTest::newRow("money_data_3") << long(30) << long(30) << long(0);
    QTest::newRow("money_data_4") << long(50) << long(0) << long(50);
}

void User_Test::putOnTable(){
    QFETCH(long, money);
    QFETCH(long, put);
    QFETCH(long, result);
    UserInfo user = UserInfo("", 1, money, 0);
    user.putOnTable(put);
    QCOMPARE(user.getUserMoneyOnTable(), long(put));
    QCOMPARE(user.getUserMoney(), long(result));
}

QTEST_MAIN(User_Test)

#include "tst_user_test.moc"
