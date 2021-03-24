#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include "Engimon.hpp"
#include "Inventory.hpp"
#include "point.h"
#include <iostream>
using namespace std;

class Player {
    private :
        Engimon activeEngimon;
        point playerPosition;
        point activeEngimonPos;
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
        point getPlayerPosition();
        point getActiveEngimonPos();
        // masih kurang commands
};

#endif