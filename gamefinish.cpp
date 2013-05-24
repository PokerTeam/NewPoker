#include "gamefinish.h"

GameFinish::GameFinish(){
}

GameFinish::GameFinish(QList<UserCardSet> winners){
    this->winners = winners;
}

QList<UserCardSet> GameFinish::getWinners(){
    return winners;
}

QDataStream &operator<<(QDataStream &out,GameFinish &action)
{
    out << quint32(action.winners.length());
    foreach(UserCardSet set, action.winners){
        out << set;
    }
    return out;
}

QDataStream &operator>>(QDataStream &in, GameFinish &action)
{
    quint32 length;
    in >> length;
    UserCardSet set;
    for (quint32 i = 0; i < length; i++){
        in >> set;
        action.winners.push_back(set);
    }
    return in;
}
