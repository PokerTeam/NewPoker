#ifndef GAMEFINISH_H
#define GAMEFINISH_H

#include <QDataStream>

#include "userinfo.h"
#include "usercardset.h"

class GameFinish
{
private:
    QList<UserCardSet> winners;

public:
    GameFinish();
    GameFinish(QList<UserCardSet> winners);

    QList<UserCardSet> getWinners();

    friend QDataStream &operator<<(QDataStream &out,GameFinish &action);
    friend QDataStream &operator>>(QDataStream &in, GameFinish &action);
};

#endif // GAMEFINISH_H
