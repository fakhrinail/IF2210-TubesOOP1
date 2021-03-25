#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include "Species.hpp"
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
        //void battle(Maps& M);
        void manageActiveEngimon();
        void setActiveEngimon();
        void callEngimon();
        void printAllInventory();
        void detailsMenu();
        void useSkill();
        void breedingMenu();
        void showCommands();
        void addEngimon(Engimon e);
        void addSkill(Skill s);
        //void doCommands(Maps& M const);
        Engimon getActiveEngimon();
        //Engimon breeding(Engimon& a, Engimon& b);
        point getPlayerPosition();
        point getActiveEngimonPos();
};

#endif