#include "territory.h"
#include "functions.h"

void Territory::add_tanks(short count){
    m_tanks += count;
}

void Territory::remove_tanks(short count){
    m_tanks -= count;
}

void Territory::attack_Territory(Territory* victim){
    if(m_tanks < 2){
        std::cout << "You dont have enough tanks on " << m_name << " to attack!" << std::endl;
    }
    else if(find(m_neighbours.begin(), m_neighbours.end(), victim) == m_neighbours.end()){
        std::cout << "Cannot attack that Territory!" << std::endl;
    }
    else{
        //NAPAD
        std::cout << m_name << "(" << m_tanks << ")" << " is attacking " << victim->name() << "(" << victim->tanks() << ")" << "....." << std::endl;
        int attackerCount = m_tanks-1;
        int defenderCount = victim->tanks();
        std::vector<int> attackerDices;
        std::vector<int> defenderDices;
        srand(time(NULL));


        for(int i=0; i<attackerCount; i++){
            int num = rand() % 6 + 1;
            attackerDices.push_back(num);
        }

        std::sort(attackerDices.begin(), attackerDices.end(), std::greater<int>());
        std::cout << "Attacker Rolls:";
        for(int i=0; i<attackerCount; i++){
            std::cout << " " << attackerDices[i];
        }
        std::cout << std::endl;

        for(int i=0; i<defenderCount; i++){
            int num = rand() % 6 + 1;
            defenderDices.push_back(num);
        }


        std::sort(defenderDices.begin(), defenderDices.end(), std::greater<int>());
        std::cout << "Defender Rolls:";
        for(int i=0; i<defenderCount; i++){
            std::cout << " " << defenderDices[i];
        }
        std::cout << std::endl;


        int attackerLoss=0;
        int defenderLoss=0;

        for(int i=0; i<attackerCount && i<defenderCount; i++){
            if((attackerDices[i] - defenderDices[i]) > 0)
                defenderLoss++;
            else attackerLoss++;
        }

        victim->remove_tanks(defenderLoss);
        remove_tanks(attackerLoss);

        std::cout << m_name << " lost " << attackerLoss << " and now have " << m_tanks << " tank(s)." << std::endl;
        std::cout << victim->name() << " lost " << defenderLoss << " and now have " << victim->tanks() << " tank(s)." << std::endl;

        if(victim->tanks()==0){
            std::cout << "Congratulations! You have coquered " << victim->name() << "!" << std::endl;
            std::cout << "How many tanks You want to transfer to " << victim->name() << "?" << std::endl;



        }

   }
}

std::list <Territory*> Territory::allConected()
{
    std::list <Territory* > queue;

    queue.push_back(this);

    std::list<Territory*>::iterator iter1;

    for(iter1=queue.begin(); iter1!=queue.end(); iter1++)
    {

            std::vector<Territory*> neighbours=(*iter1)->neighbours();

            bool* visited=new bool[neighbours.size()];

            std::vector<Territory*>::iterator i;

            for(i = neighbours.begin(); i != neighbours.end(); i++)
                    visited[distance(neighbours.begin(), i)]=false;

            for(i = neighbours.begin(); i != neighbours.end(); i++)
            {
                if(*iter1==*i)
                    continue;

                if(visited[distance(neighbours.begin(), i)]==true)
                    continue;

                if(this->owner()!=(*i)->owner())
                {
                 visited[distance(neighbours.begin(), i)]=1;
                 continue;
                }

                 visited[distance(neighbours.begin(), i)]=1;

                 if(!contains(*i, queue))
                    queue.push_back(*i);

            }
    }

    return queue;
}

void Territory::changeOwner(Player* owner){
    m_owner = owner;
}

std::string Territory::name(void){
    return m_name;
}

Player* Territory::owner(void){
    return m_owner;
}

int Territory::tanks(void){
    return m_tanks;
}

int Territory::id(void){
    return m_id;
}

void Territory::addNeighbour(Territory* neighbour){
    m_neighbours.push_back(neighbour);
}

void Territory::setOwner(Player* owner){
    m_owner = owner;
}

std::vector<Territory*> Territory::neighbours(void)
{
    return m_neighbours;
}

Territory::Territory(int tanks, const std::string name, Player* owner)
    :m_tanks(tanks), m_name(name), m_owner(owner)
{}

Territory::Territory(int tanks, const std::string name)
    :m_tanks(tanks), m_name(name)
{
    m_id=0;
}

Territory::Territory(int tanks, const std::string name, int id)
    :m_tanks(tanks), m_name(name), m_id(id)
{}

Territory::~Territory(void){

}
