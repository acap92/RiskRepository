#include <QApplication>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <iterator>
#include <stack>
#include <math.h>
#include "player.h"
#include "territory.h"
#include "turn.h"
#include "global.h"
#include "functions.h"
#include "mainwindow.h"

#include"world.h"

#define MAX_SIZE 7
#define WORLD_SIZE 42
using namespace std;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QVector< QWidget* > widgets;
    MainWindow w;
//    StartingWindow *start = new StartingWindow();
//    GameSetup *setup = new GameSetup();

    //connect(ui->pushButton_3,SIGNAL(clicked()),QApplication::instance(), SLOT(exit()));
    w.showNormal();

    //IGRACI:
    Player noone("none");
    Player one("Milan", "blue");
    Player two("Kiza", "red");
    Player three("Aca", "green");
    Player four("Cukara", "yellow");
    Player five("Mirjana", "orange");

    list<Player*> players;
    players.push_back(&one);
    players.push_back(&two);
    players.push_back(&three);
    players.push_back(&four);
    players.push_back(&five);

    Turn turn(players);

    //init(players);


    //TESTIRANJE WORLD KLASE

    World *world = new World();

    cout << world->territory(28)->name();

    vector<Territory*> test = world->territory(28)->neighbours();

    vector<Territory*>::iterator t;

    cout << " and his neighbours: ";

    for(t=test.begin(); t!=test.end(); t++){
        cout << (*t)->name() << ", ";
    }

    cout << endl << endl;

    //TESTIRANJE CIKLICNE LISTE:
    cout << "current player: " << turn.currentPlayer()->name() << endl;

    turn.nextPlayer();
    cout << "current player: " << turn.currentPlayer()->name() << endl;

    turn.nextPlayer();
    cout << "current player: " << turn.currentPlayer()->name() << endl;

    turn.nextPlayer();
    cout << "current player: " << turn.currentPlayer()->name() << endl;

    turn.nextPlayer();
    cout << "current player: " << turn.currentPlayer()->name() << endl;
    //---------------------------------------------------------------------


    //TESTIRANJE ATTACK FUNKCIJE

    greatBritain.attack_Territory(&iceland);

    //---------------------------------------

    //TESTIRANJE POVEZANOSTI TERITORIJA
    if(connected(&greenland, &greatBritain))
        cout<<"jesu"<<endl;
    else
        cout<<"nisu"<<endl;
    //----------------------------------------


    //TESTIRANJE NAJKRACEG PUTA
    vector<Territory*> path;
    vector<Territory*>::iterator i;
    try{path=bfs(&greatBritain, &greenland); }

    catch(bad_alloc)
    {
        cout << "nisu2" << endl;
    }

    if(path.begin()==path.end()){
        cout << "nisu3" << endl;
    }


    for(i=path.begin(); i!=path.end(); i++)
        cout<<(*i)->name()<<endl;
    //-----------------------------------------


    vector<Territory*> teritorije(world->allTerritories());
    vector<Territory*>::iterator k;

    for(k=teritorije.begin(); k!=teritorije.end(); k++)
    {
        cout << (*k)->name() << endl;
    }

    return a.exec();
}
