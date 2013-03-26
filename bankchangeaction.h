#ifndef BANKCHANGEACTION_H
#define BANKCHANGEACTION_H

class BankChangeAction
{
public:
    BankChangeAction(long newBankValue);
    long getBankValue();

private:
    long newBankValue;
};

#endif // BANKCHANGEACTION_H
