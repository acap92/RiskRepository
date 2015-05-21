#ifndef TURN_H
#define TURN_H

#include "player.h"
#include <list>

class Turn{
public:
    void nextPlayer(void);

    void removePlayer(Player* player);

    Player* currentPlayer(void);

    void addPlayer(Player* player);


    Turn(std::list<Player*> players);


private:
    std::list<Player*> m_players;
    std::list<Player*>::iterator m_current;
};

#endif // TURN_H
