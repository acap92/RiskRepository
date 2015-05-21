#include "world.h"
#include <iostream>


/*
 *  m_continents[0] - Europe
 *  m_continents[1] - N.America
 *  m_continents[2] - S.America
 *  m_continents[3] - Africa
 *  m_continents[4] - Asia
 *  m_continents[5] - Australia
 */


/*
 * funkcija za raspodelu teritorija na pocetku
 * (mozda kao poziv svakom kontinentu da raspodeli)
 * iskoristiti postojanu iz global.cpp
 */


Continent* World::europe(){
    if(m_continents.size() == 6)
        return m_continents[0];
    else
        return 0;
}

Continent* World::northAmerica(){
    if(m_continents.size() == 6)
        return m_continents[1];
    else
        return 0;
}
Continent* World::southAmerica(){
    if(m_continents.size() == 6)
        return m_continents[2];
    else
        return 0;
}
Continent* World::africa(){
    if(m_continents.size() == 6)
        return m_continents[3];
    else
        return 0;
}
Continent* World::asia(){
    if(m_continents.size() == 6)
        return m_continents[4];
    else
        return 0;
}
Continent* World::australia(){
    if(m_continents.size() == 6)
        return m_continents[0];
    else
        return 0;
}


Territory* World::territory(std::string name){
    std::vector<Continent*>::iterator i;
    Territory* resoult;
    for(i=m_continents.begin(); i!=m_continents.end(); i++){
        if( (resoult = (*i)->territory(name)) != 0)
            return resoult;
    }
    return 0;
}


Territory* World::territory(int id){
    std::vector<Continent*>::iterator i;
    Territory* resoult;
    for(i=m_continents.begin(); i!=m_continents.end(); i++){
        if( (resoult = (*i)->territory(id)) != 0)
            return resoult;
    }
    return 0;
}

std::vector<Territory*> World::allTerritories()
{
    std::vector<Continent*>::iterator i;
    std::vector<Territory*>::iterator j;
    std::vector<Territory*> result;
    std::vector<Territory*> tmp;

    for(i=m_continents.begin(); i!=m_continents.end(); i++)
    {
        tmp = (*i)->territories();

        for(j=tmp.begin(); j!=tmp.end(); j++)
            result.push_back(*j);

    }

    return result;
}

World::World()
{
    //EVROPA:
    Continent *europe = new Continent();

    Territory *greatBritain = new Territory(4, "Great Britain", 1);
    europe->addTerritory(greatBritain);

    Territory *iceland = new Territory(2, "Iceland", 2);
    europe->addTerritory(iceland);

    Territory *northernEurope = new Territory(1, "Northern Europe", 3);
    europe->addTerritory(northernEurope);

    Territory *scandinavia = new Territory(1, "Scandinavia", 4);
    europe->addTerritory(scandinavia);

    Territory *southernEurope = new Territory(1, "Southern Europe", 5);
    europe->addTerritory(southernEurope);

    Territory *ukraine = new Territory(1, "Ukraine", 6);
    europe->addTerritory(ukraine);

    Territory *westernEurope = new Territory(1, "Western Europe", 7);
    europe->addTerritory(westernEurope);

    m_continents.push_back(europe);




    //S.AMERIKA:
    Continent *northAmerica = new Continent();

    Territory *greenland = new Territory(1, "Greenland", 8);
    northAmerica->addTerritory(greenland);

    Territory *quebec = new Territory(1, "Quebec", 9);
    northAmerica->addTerritory(quebec);

    Territory *easternUnitedStates = new Territory(1, "Eastern United States", 10);
    northAmerica->addTerritory(easternUnitedStates);

    Territory *centralAmerica = new Territory(1, "Central America", 11);
    northAmerica->addTerritory(centralAmerica);

    Territory *westernUnitedStates = new Territory(1, "Western United States", 12);
    northAmerica->addTerritory(westernUnitedStates);

    Territory *alberta = new Territory(1, "Alberta", 13);
    northAmerica->addTerritory(alberta);

    Territory *ontario = new Territory(1, "Ontario", 14);
    northAmerica->addTerritory(ontario);

    Territory *alaska = new Territory(1, "Alaska", 15);
    northAmerica->addTerritory(alaska);

    Territory *northwestTerritory = new Territory(1, "Northwest Territory", 16);
    northAmerica->addTerritory(northwestTerritory);

    m_continents.push_back(northAmerica);




    //J.AMERIKA:
    Continent *southAmerica = new Continent();

    Territory *venezuela = new Territory(1, "Venezuela", 17);
    southAmerica->addTerritory(venezuela);

    Territory *peru = new Territory(1, "Peru", 18);
    southAmerica->addTerritory(peru);

    Territory *brasil = new Territory(1, "Brasil", 19);
    southAmerica->addTerritory(brasil);

    Territory *argentina = new Territory(1, "Argentina", 20);
    southAmerica->addTerritory(argentina);

    m_continents.push_back(southAmerica);

    //AFRIKA:
    Continent *africa = new Continent();

    Territory *egypt = new Territory(1, "Egypt", 21);
    africa->addTerritory(egypt);

    Territory *northAfrica = new Territory(1, "North Africa", 22);
    africa->addTerritory(northAfrica);

    Territory *eastAfrica = new Territory(1, "East Africa", 23);
    africa->addTerritory(eastAfrica);

    Territory *congo = new Territory(1, "Congo", 24);
    africa->addTerritory(congo);

    Territory *southAfrica = new Territory(1, "South Africa", 25);
    africa->addTerritory(southAfrica);

    Territory *madagascar = new Territory(1, "Madagascar", 26);
    africa->addTerritory(madagascar);

    m_continents.push_back(africa);



    //AZIJA:
    Continent *asia = new Continent();

    Territory *middleEast = new Territory(1, "Middle East", 27);
    asia->addTerritory(middleEast);

    Territory *afghanistan = new Territory(1, "Afghanistan", 28);
    asia->addTerritory(afghanistan);

    Territory *ural = new Territory(1, "Ural", 29);
    asia->addTerritory(ural);

    Territory *siberia = new Territory(1, "Siberia", 30);
    asia->addTerritory(siberia);

    Territory *yakutsk = new Territory(1, "Yakutsk", 31);
    asia->addTerritory(yakutsk);

    Territory *irkutsk = new Territory(1, "Irkutsk", 32);
    asia->addTerritory(irkutsk);

    Territory *mongolia = new Territory(1, "Mongolia", 33);
    asia->addTerritory(mongolia);

    Territory *kamchatka = new Territory(1, "Kamchatka", 34);
    asia->addTerritory(kamchatka);

    Territory *japan = new Territory(1, "Japan", 35);
    asia->addTerritory(japan);

    Territory *china = new Territory(1, "China", 36);
    asia->addTerritory(china);

    Territory *india = new Territory(1, "India", 37);
    asia->addTerritory(india);

    Territory *siam = new Territory(1, "Siam", 38);
    asia->addTerritory(siam);

    m_continents.push_back(asia);


    //AUSTRALIA:

    Continent *australia = new Continent();

    Territory *indonesia = new Territory(1, "Indonesia", 39);
    australia->addTerritory(indonesia);

    Territory *newGuinea = new Territory(1, "New Guinea", 40);
    australia->addTerritory(newGuinea);

    Territory *easternAustralia = new Territory(1, "Eastern Australia", 41);
    australia->addTerritory(easternAustralia);

    Territory *westernAustralia = new Territory(1, "Western Australia", 42);
    australia->addTerritory(westernAustralia);

    m_continents.push_back(australia);




    //BOooOOoooOOOoooOM KONEKCIJE
    //EVROPA:
    greatBritain->addNeighbour(iceland);
    greatBritain->addNeighbour(scandinavia);
    greatBritain->addNeighbour(northernEurope);
    greatBritain->addNeighbour(westernEurope);

    iceland->addNeighbour(greatBritain);
    iceland->addNeighbour(scandinavia);
    iceland->addNeighbour(greenland);

    scandinavia->addNeighbour(ukraine);
    scandinavia->addNeighbour(iceland);
    scandinavia->addNeighbour(greatBritain);
    scandinavia->addNeighbour(northernEurope);

    ukraine->addNeighbour(scandinavia);
    ukraine->addNeighbour(northernEurope);
    ukraine->addNeighbour(southernEurope);
    ukraine->addNeighbour(ural);
    ukraine->addNeighbour(afghanistan);
    ukraine->addNeighbour(middleEast);

    southernEurope->addNeighbour(ukraine);
    southernEurope->addNeighbour(northernEurope);
    southernEurope->addNeighbour(westernEurope);
    southernEurope->addNeighbour(egypt);
    southernEurope->addNeighbour(northAfrica);

    westernEurope->addNeighbour(southernEurope);
    westernEurope->addNeighbour(northernEurope);
    westernEurope->addNeighbour(greatBritain);
    westernEurope->addNeighbour(northAfrica);

    northernEurope->addNeighbour(greatBritain);
    northernEurope->addNeighbour(scandinavia);
    northernEurope->addNeighbour(ukraine);
    northernEurope->addNeighbour(southernEurope);
    northernEurope->addNeighbour(westernEurope);



    //S.AMERIKA:
    alaska->addNeighbour(northwestTerritory);
    alaska->addNeighbour(alberta);
    alaska->addNeighbour(kamchatka);

    northwestTerritory->addNeighbour(alaska);
    northwestTerritory->addNeighbour(greenland);
    northwestTerritory->addNeighbour(alberta);
    northwestTerritory->addNeighbour(ontario);

    greenland->addNeighbour(quebec);
    greenland->addNeighbour(northwestTerritory);
    greenland->addNeighbour(ontario);
    greenland->addNeighbour(iceland);

    quebec->addNeighbour(greenland);
    quebec->addNeighbour(easternUnitedStates);
    quebec->addNeighbour(ontario);

    ontario->addNeighbour(quebec);
    ontario->addNeighbour(easternUnitedStates);
    ontario->addNeighbour(westernUnitedStates);
    ontario->addNeighbour(alberta);
    ontario->addNeighbour(northwestTerritory);
    ontario->addNeighbour(greenland);

    alberta->addNeighbour(ontario);
    alberta->addNeighbour(westernUnitedStates);
    alberta->addNeighbour(alaska);
    alberta->addNeighbour(northwestTerritory);

    westernUnitedStates->addNeighbour(ontario);
    westernUnitedStates->addNeighbour(easternUnitedStates);
    westernUnitedStates->addNeighbour(centralAmerica);
    westernUnitedStates->addNeighbour(alberta);

    easternUnitedStates->addNeighbour(ontario);
    easternUnitedStates->addNeighbour(quebec);
    easternUnitedStates->addNeighbour(centralAmerica);
    easternUnitedStates->addNeighbour(westernUnitedStates);

    centralAmerica->addNeighbour(westernUnitedStates);
    centralAmerica->addNeighbour(easternUnitedStates);
    centralAmerica->addNeighbour(venezuela);


    //J.AMERIKA
    venezuela->addNeighbour(centralAmerica);
    venezuela->addNeighbour(brasil);
    venezuela->addNeighbour(peru);

    peru->addNeighbour(venezuela);
    peru->addNeighbour(brasil);
    peru->addNeighbour(argentina);

    brasil->addNeighbour(northAfrica);
    brasil->addNeighbour(venezuela);
    brasil->addNeighbour(peru);
    brasil->addNeighbour(argentina);

    argentina->addNeighbour(brasil);
    argentina->addNeighbour(peru);



    //AFRIKA
    northAfrica->addNeighbour(brasil);
    northAfrica->addNeighbour(westernEurope);
    northAfrica->addNeighbour(southernEurope);
    northAfrica->addNeighbour(egypt);
    northAfrica->addNeighbour(eastAfrica);
    northAfrica->addNeighbour(congo);

    egypt->addNeighbour(southernEurope);
    egypt->addNeighbour(middleEast);
    egypt->addNeighbour(northAfrica);
    egypt->addNeighbour(eastAfrica);
    egypt->addNeighbour(congo);

    congo->addNeighbour(northAfrica);
    congo->addNeighbour(eastAfrica);
    congo->addNeighbour(southAfrica);

    eastAfrica->addNeighbour(egypt);
    eastAfrica->addNeighbour(northAfrica);
    eastAfrica->addNeighbour(congo);
    eastAfrica->addNeighbour(southAfrica);
    eastAfrica->addNeighbour(madagascar);
    eastAfrica->addNeighbour(middleEast);

    southAfrica->addNeighbour(congo);
    southAfrica->addNeighbour(eastAfrica);
    southAfrica->addNeighbour(madagascar);

    madagascar->addNeighbour(southAfrica);
    madagascar->addNeighbour(eastAfrica);



    //AUSTRALIA:
    indonesia->addNeighbour(siam);
    indonesia->addNeighbour(newGuinea);
    indonesia->addNeighbour(westernAustralia);

    newGuinea->addNeighbour(indonesia);
    newGuinea->addNeighbour(easternAustralia);
    newGuinea->addNeighbour(westernAustralia);

    easternAustralia->addNeighbour(newGuinea);
    easternAustralia->addNeighbour(westernAustralia);

    westernAustralia->addNeighbour(newGuinea);
    westernAustralia->addNeighbour(easternAustralia);
    westernAustralia->addNeighbour(indonesia);



    //AZIJA
    middleEast->addNeighbour(eastAfrica);
    middleEast->addNeighbour(southernEurope);
    middleEast->addNeighbour(ukraine);
    middleEast->addNeighbour(egypt);
    middleEast->addNeighbour(afghanistan);
    middleEast->addNeighbour(india);

    india->addNeighbour(middleEast);
    india->addNeighbour(afghanistan);
    india->addNeighbour(china);
    india->addNeighbour(siam);

    siam->addNeighbour(indonesia);
    siam->addNeighbour(india);
    siam->addNeighbour(china);

    china->addNeighbour(siam);
    china->addNeighbour(india);
    china->addNeighbour(afghanistan);
    china->addNeighbour(ural);
    china->addNeighbour(siberia);
    china->addNeighbour(mongolia);

    afghanistan->addNeighbour(ukraine);
    afghanistan->addNeighbour(ural);
    afghanistan->addNeighbour(china);
    afghanistan->addNeighbour(india);
    afghanistan->addNeighbour(middleEast);

    ural->addNeighbour(ukraine);
    ural->addNeighbour(siberia);
    ural->addNeighbour(china);
    ural->addNeighbour(afghanistan);

    siberia->addNeighbour(yakutsk);
    siberia->addNeighbour(irkutsk);
    siberia->addNeighbour(mongolia);
    siberia->addNeighbour(china);
    siberia->addNeighbour(ural);

    yakutsk->addNeighbour(kamchatka);
    yakutsk->addNeighbour(irkutsk);
    yakutsk->addNeighbour(siberia);

    irkutsk->addNeighbour(yakutsk);
    irkutsk->addNeighbour(kamchatka);
    irkutsk->addNeighbour(mongolia);
    irkutsk->addNeighbour(siberia);

    mongolia->addNeighbour(irkutsk);
    mongolia->addNeighbour(kamchatka);
    mongolia->addNeighbour(japan);
    mongolia->addNeighbour(china);
    mongolia->addNeighbour(siberia);

    japan->addNeighbour(kamchatka);
    japan->addNeighbour(mongolia);

    kamchatka->addNeighbour(japan);
    kamchatka->addNeighbour(mongolia);
    kamchatka->addNeighbour(irkutsk);
    kamchatka->addNeighbour(yakutsk);
    kamchatka->addNeighbour(alaska);


    //std::cout << m_continents[0]->greatBritain()->name() << std::endl;

}

