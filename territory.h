#ifndef TERRITORY_H
#define TERRITORY_H

#include <vector>
#include <iostream>
#include <time.h>
#include <math.h>
#include <algorithm>
#include <list>
#include "player.h"

class Territory{
public:
    void add_tanks(short count);

    void remove_tanks(short count);

    void attack_Territory(Territory* victim);

    void changeOwner(Player* owner);

    std::string name(void);

    Player* owner(void);

    int id(void);

    int tanks(void);


    void addNeighbour(Territory* neighbour);

    std::list <Territory*> allConected();

    void setOwner(Player* owner);

    std::vector<Territory*> neighbours(void);

    Territory(int tanks, const std::string name, Player* owner);

    Territory(int tanks, const std::string name);

    Territory(int tanks, const std::string name, int id);

    ~Territory(void);

private:
    int m_tanks;
    std::string m_name;
    Player* m_owner;
    int m_id;
    std::vector<Territory*> m_neighbours;
};

#endif // TERRITORY_H
