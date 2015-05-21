#ifndef GLOBAL_H
#define GLOBAL_H
#include "territory.h"


extern Territory greatBritain;
extern Territory iceland;
extern Territory northernEurope;
extern Territory scandinavia;
extern Territory southernEurope;
extern Territory ukraine;
extern Territory westernEurope;

//S.AMERIKA:
extern Territory greenland;
extern Territory quebec;
extern Territory easternUnitedStates;
extern Territory centralAmerica;
extern Territory westernUnitedStates;
extern Territory alberta;
extern Territory ontario;
extern Territory alaska;
extern Territory northwestTerritory;

//J.AMERIKA:
extern Territory venezuela;
extern Territory peru;
extern Territory brasil;
extern Territory argentina;

//AFRIKA:
extern Territory egypt;
extern Territory northAfrica;
extern Territory eastAfrica;
extern Territory congo;
extern Territory southAfrica;
extern Territory madagascar;

//AZIJA:
extern Territory middleEast;
extern Territory afghanistan;
extern Territory ural;
extern Territory siberia;
extern Territory yakutsk;
extern Territory irkutsk;
extern Territory mongolia;
extern Territory kamchatka;
extern Territory japan;
extern Territory china;
extern Territory india;
extern Territory siam;

//AUSTRALIA:
extern Territory indonesia;
extern Territory newGuinea;
extern Territory easternAustralia;
extern Territory westernAustralia;

void init(std::list<Player*> players);

#endif // GLOBAL_H
