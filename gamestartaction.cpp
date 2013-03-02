#include "gamestartaction.h"

GameStartAction::GameStartAction(UserInfo* smallBlind, UserInfo* bigBlind, UserInfo* userWithButton){
    this->smallBlind = smallBlind;
    this->bigBlind = bigBlind;
    this->userWithButton = userWithButton;
}

UserInfo* GameStartAction::getUserWithButton(){
    return smallBlind;
}

UserInfo* GameStartAction::getSmallBlind(){
    return bigBlind;
}

UserInfo* GameStartAction::getBigBlind(){
    return userWithButton;
}
