#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include "Engimon.hpp"
#include "Inventory.hpp"
#include <utility>
#include <iostream>
using namespace std;

class Player {
    private :
        Engimon activeEngimon;
        pair<int, int> playerPosition;
        pair<int, int> activeEngimonPos;
        Inventory<Engimon> inventoryE;
        Inventory<Skill> inventoryS;

    public :
        Player(Engimon basic);
        ~Player();
        void w();
        void a();
        void s();
        void d();
        void battle();
        void setActiveEngimon();
        void printAllInventory();
        void useSkill();
        Engimon getActiveEngimon();
        Engimon breeding(Engimon a, Engimon b);
        pair<int, int> getPlayerPosition();
        pair<int, int> getActiveEngimonPos();
        // masih kurang commands
};

#endif