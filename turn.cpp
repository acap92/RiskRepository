#include "turn.h"

void Turn::nextPlayer(){
    m_current++;
    if(m_current == m_players.end())
        m_current=m_players.begin();
    /*Pozivi funkcija koje ce verovatno postojati pri pocetku poteza
      Npr:
      m_players[m_current].calculateTanks();
    */
}

void Turn::removePlayer(Player* player){
    std::list<Player*>::iterator i;
    for(i=m_players.begin(); *i!=player; i++);
    m_players.erase(i);
}

Player* Turn::currentPlayer(void){
    return *m_current;
}

void Turn::addPlayer(Player* player){
    if(m_players.size()==6){
        //std::cout << "Already 6 players (max)" << endl;
        return;
    }
    m_players.push_back(player);
    if(m_players.size() == 0)
        m_current=m_players.begin();
}


Turn::Turn(std::list<Player*> players)
    :m_players(players), m_current(m_players.begin())
{}
