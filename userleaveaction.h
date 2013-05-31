#ifndef USERLEAVEACTION_H
#define USERLEAVEACTION_H

class UserLeaveAction
{
private:
    long userId;
    long moneyToBank;

public:
    UserLeaveAction(long userId, long moneyToBank);
    long getUserId();
    long getMoneyToBank();
};

#endif // USERLEAVEACTION_H
