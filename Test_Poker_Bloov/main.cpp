#include <QTest>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "test_accountmanager.h"
#include "test_user.h"
#include "test_card.h"

int main(int argc, char *argv[])
{
    freopen("testing.log", "w", stdout);
    QTest::qExec(new Test_Card(), argc, argv);
    qDebug() << "some";
    return 0;
}
