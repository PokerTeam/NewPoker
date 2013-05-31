#ifndef TEST_CARD_H
#define TEST_CARD_H

#include <QObject>
#include <QtTest>

#include "../suit.h"

class Test_Card : public QObject
{
    Q_OBJECT
public:
    Test_Card();
private slots:
    void getSuit_data();
    void getSuit();

    void getCardNumber_data();
    void getCardNumber();

    void getCardImage_data();
    void getCardImage();

    void isEquals_data();
    void isEquals();

    void compare_data();
    void compare();

    void isOrdered_data();
    void isOrdered();
};

#endif // TEST_CARD_H
