#ifndef BANKCHANGEACTION_H
#define BANKCHANGEACTION_H

#include <QDataStream>

class BankChangeAction
{
public:
    BankChangeAction();
    BankChangeAction(long newBankValue);
    long getBankValue();

    friend QDataStream &operator<<(QDataStream &out,BankChangeAction &action);
    friend QDataStream &operator>>(QDataStream &in, BankChangeAction &action);

private:
    long newBankValue;
};

#endif // BANKCHANGEACTION_H
