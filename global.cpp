#include "player.h"
#include "global.h"
#include "turn.h"
#include <cstring>

//TERITORIJE KAO GLOBALNE PROMENLJIVE:


//EVROPA:
Territory greatBritain(4, "Great Britain");
Territory iceland(2, "Iceland");
Territory northernEurope(1, "Northern Europe");
Territory scandinavia(1, "Scandinavia");
Territory southernEurope(1, "Southern Europe");
Territory ukraine(1, "Ukraine");
Territory westernEurope(1, "Western Europe");


//S.AMERIKA:
Territory greenland(1, "Greenland");
Territory quebec(1, "Quebec");
Territory easternUnitedStates(1, "Eastern United States");
Territory centralAmerica(1, "Central America");
Territory westernUnitedStates(1, "Western United States");
Territory alberta(1, "Alberta");
Territory ontario(1, "Ontario");
Territory alaska(1, "Alaska");
Territory northwestTerritory(1, "Northwest Territory");

//J.AMERIKA:
Territory venezuela(1, "Venezuela");
Territory peru(1, "Peru");
Territory brasil(1, "Brasil");
Territory argentina(1, "Argentina");

//AFRIKA:
Territory egypt(1, "Egypt");
Territory northAfrica(1, "North Africa");
Territory eastAfrica(1, "East Africa");
Territory congo(1, "Congo");
Territory southAfrica(1, "South Africa");
Territory madagascar(1, "Madagascar");

//AZIJA:
Territory middleEast(1, "Middle East");
Territory afghanistan(1, "Afghanistan");
Territory ural(1, "Ural");
Territory siberia(1, "Siberia");
Territory yakutsk(1, "Yakutsk");
Territory irkutsk(1, "Irkutsk");
Territory mongolia(1, "Mongolia");
Territory kamchatka(1, "Kamchatka");
Territory japan(1, "Japan");
Territory china(1, "China");
Territory india(1, "India");
Territory siam(1, "Siam");

//AUSTRALIA:
Territory indonesia(1, "Indonesia");
Territory newGuinea(1, "New Guinea");
Territory easternAustralia(1, "Eastern Australia");
Territory westernAustralia(1, "Western Australia");



std::list<Territory*> regije; //lista svih teritorija



//FUNKCIJA ZA INICIJALIZACIJU:
void init(std::list<Player*> players){

    std::list<Territory*>::iterator i;
    std::list<Player*>::iterator j;

//    regije.push_back(europe.greatBritain());
//    regije.push_back(europe.iceland());
//    regije.push_back(europe.northernEurope());
//    regije.push_back(europe.scandinavia());
//    regije.push_back(europe.southernEurope());
//    regije.push_back(europe.ukraine());
//    regije.push_back(europe.westernEurope());
    regije.push_back(&greatBritain);
    regije.push_back(&iceland);
    regije.push_back(&northernEurope);
    regije.push_back(&scandinavia);
    regije.push_back(&southernEurope);
    regije.push_back(&ukraine);
    regije.push_back(&westernEurope);

    regije.push_back(&greenland);
    regije.push_back(&quebec);
    regije.push_back(&easternUnitedStates);
    regije.push_back(&centralAmerica);
    regije.push_back(&westernUnitedStates);
    regije.push_back(&alberta);
    regije.push_back(&ontario);
    regije.push_back(&alaska);
    regije.push_back(&northwestTerritory);

    regije.push_back(&venezuela);
    regije.push_back(&peru);
    regije.push_back(&brasil);
    regije.push_back(&argentina);

    regije.push_back(&egypt);
    regije.push_back(&northAfrica);
    regije.push_back(&eastAfrica);
    regije.push_back(&congo);
    regije.push_back(&southAfrica);
    regije.push_back(&madagascar);

    regije.push_back(&middleEast);
    regije.push_back(&afghanistan);
    regije.push_back(&ural);
    regije.push_back(&siberia);
    regije.push_back(&yakutsk);
    regije.push_back(&irkutsk);
    regije.push_back(&mongolia);
    regije.push_back(&kamchatka);
    regije.push_back(&japan);
    regije.push_back(&china);
    regije.push_back(&india);
    regije.push_back(&siam);

    regije.push_back(&indonesia);
    regije.push_back(&newGuinea);
    regije.push_back(&easternAustralia);
    regije.push_back(&westernAustralia);

    std::cout << "Broj teritorija: " << regije.size() << std::endl;
    std::cout << "Broj igraca: " << players.size() << std::endl;
    std::cout << std::endl;

    int max = (int)((float)regije.size() / (float)players.size()); //koliko svaki igrac treba da dobije teritorija
    int n = players.size();
    int broj[n];//broji koliko je svaki igrac dobio teritorija
    memset( broj, 0, n*sizeof(int) );
    int ukupnoMax=0;

    srand(time(0)); //potrebno da bi random uvek uzimao drugacije brojeve

    //u ovoj petlji se dodeljuju owneri teritorijama
    for(i=regije.begin(); i!=regije.end(); i++)
    {
        j=players.begin();

        //proverava da li su svi na 'max' teritorija, ako jesu ima ostatka i raspodeljuje ga od pocetka liste svakome po jedan
        if(n-ukupnoMax == 0){
            for(j=players.begin(); i!=regije.end(); i++, j++){
                (*i)->changeOwner(*j);
                std::cout << (*i)->name() << ": " << (*j)->name() << std::endl;
                (*j)->addTerritory();
            }
            break;
        }


        int nmb = rand() % (n-ukupnoMax); //random broj koji odredjuje igraca koji nije dobio max

        //dodeljivanje teritorije, nakon cega ukoliko igrac ima max teritorija ide na kraj liste koji se ne moze dobiti u 'nmb'
        advance(j, nmb);
        (*i)->changeOwner(*j);
        (*j)->addTerritory();
        broj[nmb]++;
        if(broj[nmb]>=max){
            ukupnoMax++;
            players.splice( players.end(), players, j );
            for(;nmb<n-1; nmb++){
                int tmp = broj[nmb+1];
                broj[nmb+1] = broj[nmb];
                broj[nmb] = tmp;
            }
        }
        std::cout << (*i)->name() << ": " << (*j)->name() << std::endl;
    }
    std::cout << std::endl;

    int tanksCount = 20 + (6 - players.size()) * 5;

    for(j=players.begin(); j!=players.end(); j++){
        std::cout << (*j)->name() << " : " << (*j)->territories() << " territories, ";
        int tmp = tanksCount - (*j)->territories();
        (*j)->addTanks(tmp);
        std::cout << (*j)->unplaced() << " unplaced tanks." << std::endl;
    }

    //BOooOOoooOOOoooOM KONEKCIJE
    //EVROPA:
    greatBritain.addNeighbour(&iceland);
    greatBritain.addNeighbour(&scandinavia);
    greatBritain.addNeighbour(&northernEurope);
    greatBritain.addNeighbour(&westernEurope);

    iceland.addNeighbour(&greatBritain);
    iceland.addNeighbour(&scandinavia);
    iceland.addNeighbour(&greenland);

    scandinavia.addNeighbour(&ukraine);
    scandinavia.addNeighbour(&iceland);
    scandinavia.addNeighbour(&greatBritain);
    scandinavia.addNeighbour(&northernEurope);

    ukraine.addNeighbour(&scandinavia);
    ukraine.addNeighbour(&northernEurope);
    ukraine.addNeighbour(&southernEurope);
    ukraine.addNeighbour(&ural);
    ukraine.addNeighbour(&afghanistan);
    ukraine.addNeighbour(&middleEast);

    southernEurope.addNeighbour(&ukraine);
    southernEurope.addNeighbour(&northernEurope);
    southernEurope.addNeighbour(&westernEurope);
    southernEurope.addNeighbour(&egypt);
    southernEurope.addNeighbour(&northAfrica);

    westernEurope.addNeighbour(&southernEurope);
    westernEurope.addNeighbour(&northernEurope);
    westernEurope.addNeighbour(&greatBritain);
    westernEurope.addNeighbour(&northAfrica);

    northernEurope.addNeighbour(&greatBritain);
    northernEurope.addNeighbour(&scandinavia);
    northernEurope.addNeighbour(&ukraine);
    northernEurope.addNeighbour(&southernEurope);
    northernEurope.addNeighbour(&westernEurope);



    //S.AMERIKA:
    alaska.addNeighbour(&northwestTerritory);
    alaska.addNeighbour(&alberta);
    alaska.addNeighbour(&kamchatka);

    northwestTerritory.addNeighbour(&alaska);
    northwestTerritory.addNeighbour(&greenland);
    northwestTerritory.addNeighbour(&alberta);
    northwestTerritory.addNeighbour(&ontario);

    greenland.addNeighbour(&quebec);
    greenland.addNeighbour(&northwestTerritory);
    greenland.addNeighbour(&ontario);
    greenland.addNeighbour(&iceland);

    quebec.addNeighbour(&greenland);
    quebec.addNeighbour(&easternUnitedStates);
    quebec.addNeighbour(&ontario);

    ontario.addNeighbour(&quebec);
    ontario.addNeighbour(&easternUnitedStates);
    ontario.addNeighbour(&westernUnitedStates);
    ontario.addNeighbour(&alberta);
    ontario.addNeighbour(&northwestTerritory);
    ontario.addNeighbour(&greenland);

    alberta.addNeighbour(&ontario);
    alberta.addNeighbour(&westernUnitedStates);
    alberta.addNeighbour(&alaska);
    alberta.addNeighbour(&northwestTerritory);

    westernUnitedStates.addNeighbour(&ontario);
    westernUnitedStates.addNeighbour(&easternUnitedStates);
    westernUnitedStates.addNeighbour(&centralAmerica);
    westernUnitedStates.addNeighbour(&alberta);

    easternUnitedStates.addNeighbour(&ontario);
    easternUnitedStates.addNeighbour(&quebec);
    easternUnitedStates.addNeighbour(&centralAmerica);
    easternUnitedStates.addNeighbour(&westernUnitedStates);

    centralAmerica.addNeighbour(&westernUnitedStates);
    centralAmerica.addNeighbour(&easternUnitedStates);
    centralAmerica.addNeighbour(&venezuela);


    //J.AMERIKA
    venezuela.addNeighbour(&centralAmerica);
    venezuela.addNeighbour(&brasil);
    venezuela.addNeighbour(&peru);

    peru.addNeighbour(&venezuela);
    peru.addNeighbour(&brasil);
    peru.addNeighbour(&argentina);

    brasil.addNeighbour(&northAfrica);
    brasil.addNeighbour(&venezuela);
    brasil.addNeighbour(&peru);
    brasil.addNeighbour(&argentina);

    argentina.addNeighbour(&brasil);
    argentina.addNeighbour(&peru);



    //AFRIKA
    northAfrica.addNeighbour(&brasil);
    northAfrica.addNeighbour(&westernEurope);
    northAfrica.addNeighbour(&southernEurope);
    northAfrica.addNeighbour(&egypt);
    northAfrica.addNeighbour(&eastAfrica);
    northAfrica.addNeighbour(&congo);

    egypt.addNeighbour(&southernEurope);
    egypt.addNeighbour(&middleEast);
    egypt.addNeighbour(&northAfrica);
    egypt.addNeighbour(&eastAfrica);
    egypt.addNeighbour(&congo);

    congo.addNeighbour(&northAfrica);
    congo.addNeighbour(&eastAfrica);
    congo.addNeighbour(&southAfrica);

    eastAfrica.addNeighbour(&egypt);
    eastAfrica.addNeighbour(&northAfrica);
    eastAfrica.addNeighbour(&congo);
    eastAfrica.addNeighbour(&southAfrica);
    eastAfrica.addNeighbour(&madagascar);
    eastAfrica.addNeighbour(&middleEast);

    southAfrica.addNeighbour(&congo);
    southAfrica.addNeighbour(&eastAfrica);
    southAfrica.addNeighbour(&madagascar);

    madagascar.addNeighbour(&southAfrica);
    madagascar.addNeighbour(&eastAfrica);



    //AUSTRALIA:
    indonesia.addNeighbour(&siam);
    indonesia.addNeighbour(&newGuinea);
    indonesia.addNeighbour(&westernAustralia);

    newGuinea.addNeighbour(&indonesia);
    newGuinea.addNeighbour(&easternAustralia);
    newGuinea.addNeighbour(&westernAustralia);

    easternAustralia.addNeighbour(&newGuinea);
    easternAustralia.addNeighbour(&westernAustralia);

    westernAustralia.addNeighbour(&newGuinea);
    westernAustralia.addNeighbour(&easternAustralia);
    westernAustralia.addNeighbour(&indonesia);



    //AZIJA
    middleEast.addNeighbour(&eastAfrica);
    middleEast.addNeighbour(&southernEurope);
    middleEast.addNeighbour(&ukraine);
    middleEast.addNeighbour(&egypt);
    middleEast.addNeighbour(&afghanistan);
    middleEast.addNeighbour(&india);

    india.addNeighbour(&middleEast);
    india.addNeighbour(&afghanistan);
    india.addNeighbour(&china);
    india.addNeighbour(&siam);

    siam.addNeighbour(&indonesia);
    siam.addNeighbour(&india);
    siam.addNeighbour(&china);

    china.addNeighbour(&siam);
    china.addNeighbour(&india);
    china.addNeighbour(&afghanistan);
    china.addNeighbour(&ural);
    china.addNeighbour(&siberia);
    china.addNeighbour(&mongolia);

    afghanistan.addNeighbour(&ukraine);
    afghanistan.addNeighbour(&ural);
    afghanistan.addNeighbour(&china);
    afghanistan.addNeighbour(&india);
    afghanistan.addNeighbour(&middleEast);

    ural.addNeighbour(&ukraine);
    ural.addNeighbour(&siberia);
    ural.addNeighbour(&china);
    ural.addNeighbour(&afghanistan);

    siberia.addNeighbour(&yakutsk);
    siberia.addNeighbour(&irkutsk);
    siberia.addNeighbour(&mongolia);
    siberia.addNeighbour(&china);
    siberia.addNeighbour(&ural);

    yakutsk.addNeighbour(&kamchatka);
    yakutsk.addNeighbour(&irkutsk);
    yakutsk.addNeighbour(&siberia);

    irkutsk.addNeighbour(&yakutsk);
    irkutsk.addNeighbour(&kamchatka);
    irkutsk.addNeighbour(&mongolia);
    irkutsk.addNeighbour(&siberia);

    mongolia.addNeighbour(&irkutsk);
    mongolia.addNeighbour(&kamchatka);
    mongolia.addNeighbour(&japan);
    mongolia.addNeighbour(&china);
    mongolia.addNeighbour(&siberia);

    japan.addNeighbour(&kamchatka);
    japan.addNeighbour(&mongolia);

    kamchatka.addNeighbour(&japan);
    kamchatka.addNeighbour(&mongolia);
    kamchatka.addNeighbour(&irkutsk);
    kamchatka.addNeighbour(&yakutsk);
    kamchatka.addNeighbour(&alaska);


}
