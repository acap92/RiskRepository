#ifndef PLAYER
#define PLAYER

#include <string>
//#include "territory.h"

class Player{
public:

    std::string name(void);

    std::string color(void);

    int territories(void);

    void addTanks(int x);

    void removeTanks(int x);

    //void placeTanks(Territory ter, int x);

    int unplaced();

    void addTerritory(void);

    void addTerritories(int x);

    Player(std::string name, std::string color);

    Player(std::string color);

    Player(std::string name, std::string color, int id);

    Player(void);

private:
    std::string m_name;
    std::string m_color;
    int m_id;
    int m_unplaced;
    int m_territoriesCount;
};

#endif // PLAYER
