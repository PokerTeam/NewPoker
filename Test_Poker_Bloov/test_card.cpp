#include "test_card.h"
#include "../card.h"
#include "../suit.h"

Test_Card::Test_Card()
{
    //nothing to do
}

void Test_Card::getSuit_data()
{
    QTest::addColumn<int>("cardSuit");
    QTest::newRow("getSuit_test1") << (int)SPADES;
}

void Test_Card::getSuit()
{
    Card* card = new Card(SPADES, 8);
    QFETCH(int, cardSuit);
    QCOMPARE((int)(card->getSuit()), cardSuit);
}

void Test_Card::getCardNumber_data()
{
    QTest::addColumn<int>("cardNumber");
    QTest::newRow("getCardNumber_test1") << 8;
}

void Test_Card::getCardNumber()
{
    Card* card = new Card(SPADES, 8);
    QFETCH(int, cardNumber);
    QCOMPARE(card->getCardNumber(), cardNumber);
}

void Test_Card::getCardImage_data()
{
    QTest::addColumn<int>("cardImage");
    QTest::newRow("getCardImage_test1") << 49;
}

void Test_Card::getCardImage()
{
    Card* card = new Card(CLUBS, 7);
    QFETCH(int, cardImage);
    QCOMPARE(card->getCardImage(*card), cardImage);
}

void Test_Card::isEquals_data()
{
    QTest::addColumn<bool>("equalsValue");
    QTest::newRow("isEquals_test1") << true;
}

void Test_Card::isEquals()
{
    Card* card = new Card(CLUBS, 7);
    Card* other = new Card(CLUBS, 7);
    QFETCH(bool, equalsValue);
    QCOMPARE(card->isEquals(other), equalsValue);
}

void Test_Card::compare_data()
{
    QTest::addColumn<int>("value");
    QTest::newRow("compare_test1") << 1;
}

void Test_Card::compare()
{
    Card* card = new Card(CLUBS, 7);
    Card* other = new Card(CLUBS, 3);
    QFETCH(int, value);
    QCOMPARE(card->compare(other), value);
}

void Test_Card::isOrdered_data()
{
    QTest::addColumn<bool>("orderdValue");
    QTest::newRow("isOrdered_test1") << false;
}

void Test_Card::isOrdered()
{
    Card* card = new Card(CLUBS, 7);
    Card* other = new Card(CLUBS, 5);
    QFETCH(bool, orderdValue);
    QCOMPARE(card->isOrdered(other), orderdValue);
}
