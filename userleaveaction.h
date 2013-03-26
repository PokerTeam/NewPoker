#ifndef USERLEAVEACTION_H
#define USERLEAVEACTION_H

class UserLeaveAction
{
public:
    UserLeaveAction(long userId, long moneyToBank);
    long getUserId();
    long getMoneyToBank();

private:
    long userId;
    long moneyToBank;
};

#endif // USERLEAVEACTION_H
