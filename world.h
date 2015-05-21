#ifndef WORLD_H
#define WORLD_H

#include "continent.h"
#include "territory.h"
#include <vector>
#include <string>


class World
{
public:
    World();
    Continent* europe();
    Continent* northAmerica();
    Continent* southAmerica();
    Continent* africa();
    Continent* asia();
    Continent* australia();

    Territory* territory(std::string name);
    Territory* territory(int id);
    std::vector<Territory*> allTerritories();

private:
    std::vector<Continent*> m_continents;
};

#endif // WORLD_H
