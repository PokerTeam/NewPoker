#include "userleaveaction.h"

UserLeaveAction::UserLeaveAction(long userId, long moneyToBank)
{
    this->moneyToBank = moneyToBank;
    this->userId = userId;
}

long UserLeaveAction::getUserId()
{
    return userId;
}

long UserLeaveAction::getMoneyToBank()
{
    return moneyToBank;
}
