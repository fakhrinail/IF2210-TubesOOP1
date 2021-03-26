#ifndef __PLAYERMAPS_HPP__
#define __PLAYERMAPS_HPP__

#include "Species.hpp"
#include "Inventory.hpp"
#include "point.h"
#include <bits/stdc++.h>
using namespace std;

class Maps {
private:
    char GRASS;
    char WATER;
    char EMPTY;
    char ** mapArea;
    char ** mapTemplate;
    list<pair<Engimon,point> > wildEngimons;
    int totalRow;
    int totalColumn;
    int totalEngimonSpawned;
    int minLevel;
public:
    int getTotalEngimonSpawned() const;
    void setTotalEngimonSpawned(int totalEngimonSpawned);
    Maps(string filename, int spawnEngi, int minLevel);
    Maps(const Maps & map);
    ~Maps();
    void showMap(point p, point e, int round);
    int getTotalRow() const;
    void setTotalRow(int totalRow);
    int getTotalColumn() const;
    void setTotalColumn(int totalColumn);
    void engimonRandomMove(point p, point e);
    void generateEngimon(point p, point e, int round);
    bool isEmpty(int x, int y);
    bool deleteWildEngimon(point p); //Aslinya point
    const list<pair<Engimon, point> > &getWildEngimons() const;

private:
    bool loadfile(string filename);
    void loadPlayerPos(point p, point e);
    void refreshMap(point p, point e);
};

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
        void battle(Maps& M);
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
        void doCommands(Maps& M);
        Engimon getActiveEngimon();
        //Engimon breeding(Engimon& a, Engimon& b);
        point getPlayerPosition();
        point getActiveEngimonPos();
};

#endif