#include "bankchangeaction.h"

BankChangeAction::BankChangeAction(long newBankValue){
    this->newBankValue = newBankValue;
}

long BankChangeAction::getBankValue(){
    return newBankValue;
}
