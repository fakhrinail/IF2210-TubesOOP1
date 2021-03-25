//
// Created by abida on 23/03/2021.
//

#ifndef COBACOBATUBES_MAPS_H
#define COBACOBATUBES_MAPS_H
#include <iostream>
#include "Engimon.hpp"
#include "Player.hpp"
#include "point.h"
#include <list>
#include <string>
#include <fstream>
#include <utility>
using namespace std;
class Maps {
private:
    const char GRASS = '-';
    const char WATER = 'o';
    const char EMPTY = '#';
    char ** mapArea;
    char ** mapTemplate;
    list<pair<Engimon,point>> wildEngimons;
    int totalRow;
    int totalColumn;
    int totalEngimonSpawned;
    int minLevel;
    pair<point,char> prevPlayerLocation;
    point prevActiveEngimonLoc;
public:
    int getTotalEngimonSpawned() const;
    void setTotalEngimonSpawned(int totalEngimonSpawned);
    Maps(string filename, int spawnEngi, int minLevel);
    Maps(const Maps & map);
    ~Maps();
    void showMap(Player & p);
    int getTotalRow() const;
    void setTotalRow(int totalRow);
    int getTotalColumn() const;
    void setTotalColumn(int totalColumn);
    void engimonRandomMove(Player & p);
    void generateEngimon(Player & p, int round);
    bool isEmpty(int x, int y);
    bool deleteWildEngimon(point p);
public:
    const list<pair<Engimon, point>> &getWildEngimons() const;

private:
    bool loadfile(string filename);
    void loadPlayerPos(Player & p);
    void refreshMap(Player & p);
};


#endif //COBACOBATUBES_MAPS_H
