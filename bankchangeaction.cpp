#include "bankchangeaction.h"

BankChangeAction::BankChangeAction(long newBankValue)
{
    this->newBankValue = newBankValue;
}

BankChangeAction::BankChangeAction()
{
    this->newBankValue = 0;
}

long BankChangeAction::getBankValue()
{
    return newBankValue;
}

QDataStream &operator<<(QDataStream &out,BankChangeAction &action)
{
    out << qint64(action.newBankValue);
    return out;
}

QDataStream &operator>>(QDataStream &in, BankChangeAction &action)
{
    qint64 value;
    in >> value;
    action.newBankValue = value;
    return in;
}
