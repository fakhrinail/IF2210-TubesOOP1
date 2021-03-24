//
// Created by abida on 23/03/2021.
//

#ifndef COBACOBATUBES_MAPS_H
#define COBACOBATUBES_MAPS_H
#include <iostream>
#include "Engimon.hpp"
#include "point.h"
#include <list>
#include <string>
#include <fstream>
#include <utility>
using namespace std;
class Maps {
private:
    char ** mapArea;
    list<pair<Engimon,point>> wildEngimons;
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
    void showMap();
    int getTotalRow() const;
    void setTotalRow(int totalRow);
    int getTotalColumn() const;
    void setTotalColumn(int totalColumn);
    void engimonRandomMove();
    void generateEngimon();
private:
    bool loadfile(string filename);


};


#endif //COBACOBATUBES_MAPS_H
