#include "usermoveaction.h"

UserMoveAction::UserMoveAction(UserInfo* user, QList<Actions> availableActions, long minimumBid){
    this->user = user;
    this->availableActions = availableActions;
    this->minimumBid = minimumBid;
}

UserInfo* UserMoveAction::getUserInfo(){
    return user;
}

long UserMoveAction::getMinimumBid(){
    return minimumBid;
}

QList<Actions> UserMoveAction::getAvailableActions(){
    return availableActions;
}
