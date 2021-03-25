//
// Created by abida on 23/03/2021.
//

#include "Maps.h"
#include "Engimon.hpp"
#include "point.h"
#include "Player.hpp"
#include "Species.hpp"
#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include <utility>
using namespace std;
Maps::Maps(string filename, int spawnEngi, int minLevel) {
    totalEngimonSpawned = spawnEngi;
    this->minLevel = minLevel;
    prevPlayerLocation.first= point(-1,-1);
    prevPlayerLocation.second = EMPTY;
    prevActiveEngimonLoc = point(-1,-1);
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

void Maps::showMap(Player & p) {
    if(p.getPlayerPosition().getX()>=0 && p.getPlayerPosition().getX()<totalRow && p.getPlayerPosition().getY()>=0 && p.getPlayerPosition().getY()<totalColumn){
        if(prevPlayerLocation.first.getX()==-1 && prevPlayerLocation.first.getY()==-1){
            prevPlayerLocation.first = p.getPlayerPosition();
            prevPlayerLocation.second = mapArea[p.getPlayerPosition().getX()][p.getPlayerPosition().getY()];
            mapArea[p.getPlayerPosition().getX()][p.getPlayerPosition().getY()]='P';
        }else{
            if(!(mapArea[p.getPlayerPosition().getX()][p.getPlayerPosition().getY()]=='x' ||mapArea[p.getPlayerPosition().getX()][p.getPlayerPosition().getY()]=='o')){
                throw ("player menabrak sesuatu");
            }else{
                mapArea[prevPlayerLocation.first.getX()][prevPlayerLocation.first.getY()]=prevPlayerLocation.second;
                prevPlayerLocation.first = p.getPlayerPosition();
                prevPlayerLocation.second = mapArea[p.getPlayerPosition().getX()][p.getPlayerPosition().getY()];
                mapArea[p.getPlayerPosition().getX()][p.getPlayerPosition().getY()]='P';
            }
        }

    }else{
        throw ("posisi player invalid!");
    }


    for(int i=0;i<totalRow;i++){
        for(int j=0;j<totalColumn;j++){
            if(mapArea[i][j]==EMPTY){
                cout<<mapTemplate[i][j];
            }else{
                cout<<mapArea[i][j];
            }
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
        mapTemplate = new char * [totalRow];
        int i = 0;
        while(mapFile>>haha && i<totalRow){
            int j = 0;
            mapArea[i] = new char[totalColumn];
            mapTemplate[i] = new char [totalColumn];
            while(haha[j]!='\0' && j<totalColumn){
                mapArea[i][j] = EMPTY;
                mapTemplate[i][j] = haha[j];
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

void Maps::engimonRandomMove(Player & p) {
    this->loadPlayerPos(p);
    list<pair<Engimon,point>>::iterator it;
    for(it=wildEngimons.begin();it!=wildEngimons.end();it++){
        if(it->second.getX()!=-1 && it->second.getY()!=-1){
            int seedX = (rand()%3)-1;
            int seedY = (rand()%3)-1;
            while (seedX==0 && seedY==0){
                int seedX = (rand()%3)-1;
                int seedY = (rand()%3)-1;
            }
            //REPLACE THE OLD PLACE WITH x OR o DEPENDS ON ENGIMON ELEMENTS
            int nElmt = it->first.getCountElement();
            int E1 = it->first.getElements()[0].getElementID();
            int tempX = it->second.getX()+seedX;
            int tempY = it->second.getY()+seedY;

            if(nElmt==1){
                if(E1 == 1 || E1==3 || E1==4){ //fire electric ground
                    if(mapTemplate[tempX][tempY]==GRASS && mapArea[tempX][tempY]==EMPTY){
                        it->second.setX(tempX);
                        it->second.setY(tempY);
                    }
                }else if(E1==2 || E1 == 5){ //water ice
                    if(mapTemplate[tempX][tempY]==WATER && mapArea[tempX][tempY]==EMPTY){
                        it->second.setX(tempX);
                        it->second.setY(tempY);
                    }
                }
            }else if(nElmt==2){
                int E2 = it->first.getElements()[1].getElementID();
                if((E1==1 && E2==3)||(E1==3 && E2==1)){ //itachimon fire - electric
                    if(mapTemplate[tempX][tempY]==GRASS && mapArea[tempX][tempY]==EMPTY){
                        it->second.setX(tempX);
                        it->second.setY(tempY);
                    }
                }else if((E1==2 && E2==4)||(E1==4 && E2==2)){ //narutomon water-ground
                    if(mapArea[tempX][tempY]==EMPTY){
                        it->second.setX(tempX);
                        it->second.setY(tempY);
                    }
                }else if((E1==1 && E2==5)||(E1==5 && E2==1)){ //telermon ice-water
                    if(mapTemplate[tempX][tempY]==WATER && mapArea[tempX][tempY]==EMPTY){
                        it->second.setX(tempX);
                        it->second.setY(tempY);
                    }
                }
            }
        }
    }

    refreshMap(p);

}

void Maps::generateEngimon(Player & p, int round) {
    if(wildEngimons.size()<this->totalEngimonSpawned){
        loadPlayerPos(p);
        point loc;
        loc.randomPoint(totalRow,totalColumn);

        //UNTUK MEMASTIKAN DIGENERATE DI LAHAN KOSONG
        while (mapArea[loc.getX()][loc.getY()]!=EMPTY) {
            loc.randomPoint(totalRow,totalColumn);
        }

        int lvl = rand()%(round/2);
        if(mapTemplate[loc.getX()][loc.getY()]==GRASS){
            int pil = rand()%5+1;
            if(pil==1){
                wildEngimons.push_back(
                        pair<Engimon,point>(Groundmon("randommon","","","","",lvl),loc)
                );
                if(lvl>=minLevel){
                    mapArea[loc.getX()][loc.getY()] = 'G';
                }else{
                    mapArea[loc.getX()][loc.getY()] = 'g';
                }
            }else if(pil==2){
                wildEngimons.push_back(
                        pair<Engimon,point>(Electricmon("randommon","","","","",lvl),loc)
                );
                if(lvl>=minLevel){
                    mapArea[loc.getX()][loc.getY()] = 'E';
                }else{
                    mapArea[loc.getX()][loc.getY()] = 'e';
                }
            }else if(pil==3){
                wildEngimons.push_back(
                        pair<Engimon,point>(Firemon("randommon","","","","",lvl),loc)
                );
                if(lvl>=minLevel){
                    mapArea[loc.getX()][loc.getY()] = 'F';
                }else{
                    mapArea[loc.getX()][loc.getY()] = 'f';
                }
            }else if(pil==4){
                wildEngimons.push_back(
                        pair<Engimon,point>(Itachimon("randommon","","","","",lvl),loc)
                );
                if(lvl>=minLevel){
                    mapArea[loc.getX()][loc.getY()] = 'L';
                }else{
                    mapArea[loc.getX()][loc.getY()] = 'l';
                }
            }else if(pil==5){
                wildEngimons.push_back(
                        pair<Engimon,point>(Narutomon("randommon","","","","",lvl),loc)
                );
                if(lvl>=minLevel){
                    mapArea[loc.getX()][loc.getY()] = 'N';
                }else{
                    mapArea[loc.getX()][loc.getY()] = 'n';
                }
            }
        }
        else{
            int pil = rand()%4+1;
            if(pil==1){
                wildEngimons.push_back(
                        pair<Engimon,point>(Watermon("randommon","","","","",lvl),loc)
                );
                if(lvl>=minLevel){
                    mapArea[loc.getX()][loc.getY()] = 'W';
                }else{
                    mapArea[loc.getX()][loc.getY()] = 'w';
                }
            }else if(pil==2){
                wildEngimons.push_back(
                        pair<Engimon,point>(Icemon("randommon","","","","",lvl),loc)
                );
                if(lvl>=minLevel){
                    mapArea[loc.getX()][loc.getY()] = 'I';
                }else{
                    mapArea[loc.getX()][loc.getY()] = 'i';
                }
            }else if(pil==3){
                wildEngimons.push_back(
                        pair<Engimon,point>(Telermon("randommon","","","","",lvl),loc)
                );
                if(lvl>=minLevel){
                    mapArea[loc.getX()][loc.getY()] = 'S';
                }else{
                    mapArea[loc.getX()][loc.getY()] = 's';
                }
            }else if(pil==4){
                wildEngimons.push_back(
                        pair<Engimon,point>(Narutomon("randommon","","","","",lvl),loc)
                );
                if(lvl>=minLevel){
                    mapArea[loc.getX()][loc.getY()] = 'N';
                }else{
                    mapArea[loc.getX()][loc.getY()] = 'n';
                }
            }
        }

    }
}

bool Maps::isEmpty(int x, int y){
    if(x>=0 && x<totalRow && y>=0 && y<totalColumn){
        if(mapArea[x][y]=='x' || mapArea[x][y]=='o'){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}

Maps::~Maps() {
    delete[] this->mapArea;
    delete[] this->mapTemplate;
}

int Maps::getTotalEngimonSpawned() const {
    return totalEngimonSpawned;
}

void Maps::setTotalEngimonSpawned(int totalEngimonSpawned) {
    Maps::totalEngimonSpawned = totalEngimonSpawned;
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

const list<pair<Engimon, point>> &Maps::getWildEngimons() const {
    return wildEngimons;
}

void Maps::loadPlayerPos(Player & p){
    point playerPoint = p.getPlayerPosition();
    point activeEngimonPoint = p.getActiveEngimonPos();
    if(
            playerPoint.getX()>=0 &&
            playerPoint.getX() < totalRow &&
            playerPoint.getY() >=0 &&
            playerPoint.getY() < totalColumn
        )
    {
        if(mapArea[playerPoint.getX()][playerPoint.getY()]==EMPTY){
            if(prevPlayerLocation.first.getY()==-1 && prevPlayerLocation.first.getX()==-1){
                mapArea[playerPoint.getX()][playerPoint.getY()] = 'P';
                prevPlayerLocation.first = playerPoint;
            }else{
                mapArea[prevPlayerLocation.first.getX()][prevPlayerLocation.first.getY()] = EMPTY;
                prevPlayerLocation.first = playerPoint;
                mapArea[playerPoint.getX()][playerPoint.getY()] = 'P';
            }

            if(prevActiveEngimonLoc.getY()==-1 && prevActiveEngimonLoc.getX()==-1){
                mapArea[activeEngimonPoint.getX()][activeEngimonPoint.getY()] = 'X';
                prevActiveEngimonLoc = activeEngimonPoint;
            }else{
                mapArea[prevActiveEngimonLoc.getX()][prevActiveEngimonLoc.getY()] = EMPTY;
                mapArea[activeEngimonPoint.getX()][activeEngimonPoint.getY()] = 'X';
                prevActiveEngimonLoc = activeEngimonPoint;
            }
        }else{
            throw ("player nabrak!");
        }
    }
    else{
        throw ("player loc out of area");
    }
}

void Maps::refreshMap(Player & p){
    for(int i=0;i<totalRow;i++){
        for(int j=0;j<totalColumn;j++){
            mapArea[i][j] = EMPTY;
        }
    }
    prevPlayerLocation.first= point(-1,-1);
    prevPlayerLocation.second = EMPTY;
    prevActiveEngimonLoc = point(-1,-1);
    loadPlayerPos(p);
    list<pair<Engimon,point>>::iterator it;
    for(it=wildEngimons.begin();it!=wildEngimons.end();it++){
        if(it->second.getY()!=-1 && it->second.getX()!=-1){
            int nElmt = it->first.getCountElement();
            int E1 = it->first.getElements()[0].getElementID();

            if(nElmt==1){
                if(E1 == 1){ //fire
                    if(it->first.getLevel() >= minLevel){
                        mapArea[it->second.getX()][it->second.getY()]='F';
                    }else{
                        mapArea[it->second.getX()][it->second.getY()]='f';
                    }
                }else if(E1==2){ //water
                    if(it->first.getLevel() >= minLevel){
                        mapArea[it->second.getX()][it->second.getY()]='W';
                    }else{
                        mapArea[it->second.getX()][it->second.getY()]='w';
                    }
                }else if(E1==3){ //electric
                    if(it->first.getLevel() >= minLevel){
                        mapArea[it->second.getX()][it->second.getY()]='E';
                    }else{
                        mapArea[it->second.getX()][it->second.getY()]='e';
                    }
                }else if(E1==4){ //ground
                    if(it->first.getLevel() >= minLevel){
                        mapArea[it->second.getX()][it->second.getY()]='G';
                    }else{
                        mapArea[it->second.getX()][it->second.getY()]='g';
                    }
                }else if(E1==5){ //ice
                    if(it->first.getLevel() >= minLevel){
                        mapArea[it->second.getX()][it->second.getY()]='I';
                    }else{
                        mapArea[it->second.getX()][it->second.getY()]='i';
                    }
                }
            }else if(nElmt==2){
                int E2 = it->first.getElements()[1].getElementID();
                if((E1==1 && E2==3)||(E1==3 && E2==1)){ //itachimon fire - electric
                    if(it->first.getLevel() >= minLevel){
                        mapArea[it->second.getX()][it->second.getY()]='L';
                    }else{
                        mapArea[it->second.getX()][it->second.getY()]='l';
                    }
                }else if((E1==2 && E2==4)||(E1==4 && E2==2)){ //narutomon water-ground
                    if(it->first.getLevel() >= minLevel){
                        mapArea[it->second.getX()][it->second.getY()]='N';
                    }else{
                        mapArea[it->second.getX()][it->second.getY()]='n';
                    }
                }else if((E1==1 && E2==5)||(E1==5 && E2==1)){ //telermon ice-water
                    if(it->first.getLevel() >= minLevel){
                        mapArea[it->second.getX()][it->second.getY()]='S';
                    }else{
                        mapArea[it->second.getX()][it->second.getY()]='s';
                    }
                }
            }
        }
    }
}

bool Maps::deleteWildEngimon(point p){
    bool flag = false;
    list<pair<Engimon,point>>::iterator it;
    it = this->wildEngimons.begin();
    while (it!=wildEngimons.end() && flag==false){
        if(it->second==p){
            it->second.setX(-1);
            it->second.setY(-1);
            flag =true;
        }else{
            it++;
        }
    }
    return flag;
}
