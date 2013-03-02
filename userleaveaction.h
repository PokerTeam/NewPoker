#ifndef USERLEAVEACTION_H
#define USERLEAVEACTION_H

class UserLeaveAction
{
public:
    UserLeaveAction(long userId, long moneyToBank);
private:
    long userId;
    long moneyToBank;
};

#endif // USERLEAVEACTION_H
