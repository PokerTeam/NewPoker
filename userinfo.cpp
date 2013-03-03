#include "userinfo.h"

UserInfo::UserInfo(User* user, long userMoneyOnTable){
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

void UserInfo::clearMoneyOnTable(){
    userMoneyOnTable = 0;
}

void UserInfo::putOnTable(long value){
    userMoney = userMoney - value;
    if (userMoney < 0){
        userMoney = 0;
    }
    userMoneyOnTable += value;
}

long UserInfo::getUserId(){
    return userId;
}

long UserInfo::getUserMoney(){
    return userMoney;
}

long UserInfo::getUserMoneyOnTable(){
    return userMoneyOnTable;
}
