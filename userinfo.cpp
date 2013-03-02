#include "userinfo.h"

UserInfo::UserInfo(User* user, long usersMoneyOnTable){
    init(user->getUserId(), user->getMoney(), userMoneyOnTable);
}

UserInfo::UserInfo(long userId, long userMoney, long userMoneyOnTable){
    init(userId, userMoney, userMoneyOnTable);
}

void UserInfo::init(long userId, long userMoney, long userMoneyOnTable){
    this->userId = userId;
    this->userMoney = userMoney;
    this->userMoneyOnTable = userMoneyOnTable;
}

bool UserInfo::isAllIn(){
    return userMoneyOnTable != 0 && userMoney == 0;
}
