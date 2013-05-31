#ifndef BANKCHANGEACTION_H
#define BANKCHANGEACTION_H

#include <QDataStream>

class BankChangeAction
{
private:
    long newBankValue;

public:
    BankChangeAction();
    BankChangeAction(long newBankValue);
    long getBankValue();

    friend QDataStream &operator<<(QDataStream &out,BankChangeAction &action);
    friend QDataStream &operator>>(QDataStream &in, BankChangeAction &action);
};

#endif // BANKCHANGEACTION_H
