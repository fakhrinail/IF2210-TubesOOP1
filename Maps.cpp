//
// Created by abida on 23/03/2021.
//

#include "Maps.h"
#include "Engimon.hpp"
#include "point.h"
#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include <utility>
using namespace std;
Maps::Maps(string filename, int spawnEngi, int minLevel) {
    totalEngimonSpawned = spawnEngi;
    this->minLevel = minLevel;
    if(!this->loadfile(filename)){
        throw "gagal load file";
    }
}

Maps::Maps(const Maps &map) {
    this->totalEngimonSpawned = map.totalEngimonSpawned;
    this->totalColumn = map.totalColumn;
    this->totalRow = map.totalRow;
    this->minLevel = map.minLevel;
    this->mapArea = new char * [totalRow];
    for(int i=0;i<getTotalRow();i++){
        this->mapArea[i] = new char[totalColumn];
        for(int j=0;j<getTotalColumn();j++){
            this->mapArea[i][j] = map.mapArea[i][j];
        }
    }
}

void Maps::showMap() {
    for(int i=0;i<totalRow;i++){
        for(int j=0;j<totalColumn;j++){
            cout<<mapArea[i][j];
        }
        cout<<endl;
    }
}

bool Maps::loadfile(string filename) {
    try{
        string haha;
        ifstream mapFile(filename);
        this->totalColumn = 0 ;
        this->totalRow = 0;
        while(mapFile >> haha){
            if(totalRow==0){
                int i=0;
                while(haha[i]!='\0'){totalColumn++; i++;}
            }
            totalRow++;
        }
        mapFile.close();
        mapFile.open(filename);
        mapArea = new char*[totalRow];
        int i = 0;
        while(mapFile>>haha && i<totalRow){
            int j = 0;
            mapArea[i] = new char[totalColumn];
            while(haha[j]!='\0' && j<totalColumn){
                mapArea[i][j] = haha[j];
                j++;
            }
            i++;
        }

        mapFile.close();
        return true;
    }catch (ifstream::failure f){
        cout << f.what();
        return false;
    }
}

void Maps::engimonRandomMove() {
    list<pair<Engimon,point>>::iterator it;
    for(it=wildEngimons.begin();it!=wildEngimons.end();it++){
        //REPLACE THE OLD PLACE WITH x OR o DEPENDS ON ENGIMON ELEMENTS
        mapArea[it->second.getX()][it->second.getY()] = 'x';


        it->first.levelUp();
        int seedX = (rand()%3)-1;
        int seedY = (rand()%3)-1;
        it->second.setY(it->second.getY()+(seedX));
        it->second.setX(it->second.getX()+(seedY));
        bool flag = it->second.getX()<totalRow && it->second.getY()<totalColumn;
        flag = flag && (mapArea[it->second.getX()][it->second.getY()]=='o' || mapArea[it->second.getX()][it->second.getY()]=='x');
        flag = flag && (seedX!=0 || seedY!=0);

        while(!flag){
            seedX = (rand()%3)-1;
            seedY = (rand()%3)-1;
            it->second.setY(it->second.getY()+(seedX));
            it->second.setX(it->second.getX()+(seedY));
            flag = it->second.getX()<totalRow && it->second.getY()<totalColumn;
            flag = flag && (mapArea[it->second.getX()][it->second.getY()]=='o' || mapArea[it->second.getX()][it->second.getY()]=='x');
            flag = flag && (seedX!=0 || seedY!=0);
        }
        mapArea[it->second.getX()][it->second.getY()] = 'e';
    }
}

void Maps::generateEngimon() {
    if(wildEngimons.size()<this->totalEngimonSpawned){
        point loc;
        loc.randomPoint(totalRow,totalColumn);

        //UNTUK MEMASTIKAN DIGENERATE DI LAHAN KOSONG
        while (!(mapArea[loc.getX()][loc.getY()]=='o' || mapArea[loc.getX()][loc.getY()]=='x')){
            //TAMBAHKAN JUGA APAKAH DIA CRASH SAMA ENGIMON LAIN TIDAK.
            //BILA CRAASH ULANGI SAMPAI NDAK CRASH
            loc.randomPoint(totalRow,totalColumn);
        }

        //MENGANTI MAPS DENGAN ENGIMON YG DITEMPATI
        mapArea[loc.getX()][loc.getY()]='e';

        wildEngimons.push_back(
                pair<Engimon,point>(Engimon("randommon"),loc)
                );
    }
}

int Maps::getTotalRow() const {
    return totalRow;
}

void Maps::setTotalRow(int totalRow) {
    Maps::totalRow = totalRow;
}

int Maps::getTotalColumn() const {
    return totalColumn;
}

void Maps::setTotalColumn(int totalColumn) {
    Maps::totalColumn = totalColumn;
}

Maps::~Maps() {
    delete[] this->mapArea;
}

int Maps::getTotalEngimonSpawned() const {
    return totalEngimonSpawned;
}

void Maps::setTotalEngimonSpawned(int totalEngimonSpawned) {
    Maps::totalEngimonSpawned = totalEngimonSpawned;
}
