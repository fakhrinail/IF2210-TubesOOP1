//
// Created by abida on 23/03/2021.
//

#include "PlayerMaps.hpp"
#include <bits/stdc++.h>
using namespace std;

Maps::Maps(string filename, int spawnEngi, int minLevel) {
    GRASS = '-';
    WATER = 'o';
    EMPTY = '#';
    totalEngimonSpawned = spawnEngi;
    this->minLevel = minLevel;
    if(!this->loadfile(filename)){
        throw "gagal load file";
    }
}

Maps::Maps(const Maps &map) {
    GRASS = '-';
    WATER = 'o';
    EMPTY = '#';
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

void Maps::showMap(point p, point e, int round) {
    try{
        this->loadPlayerPos(p, e);
    }catch(const char* err){
        throw(err);
    }
    if(round%3 == 0){
        this->generateEngimon(p, e, 50);
        this->engimonRandomMove(p, e);
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
        ifstream mapFile(filename.c_str());
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
        mapFile.open(filename.c_str());
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

void Maps::engimonRandomMove(point p, point e) {
    srand(time(NULL));
    this->loadPlayerPos(p, e);
    list<pair<Engimon,point> >::iterator it;
    for(it=wildEngimons.begin();it!=wildEngimons.end();it++){
        if(it->second.getX()!=-1 && it->second.getY()!=-1){
            int seedX = (rand()%3)-1;
            int seedY = (rand()%3)-1;
            //REPLACE THE OLD PLACE WITH x OR o DEPENDS ON ENGIMON ELEMENTS
            int nElmt = it->first.getCountElement();
            int E1 = it->first.getElements()[0].getElementID();
            int tempX = it->second.getX()+seedX;
            int tempY = it->second.getY()+seedY;
            if(tempX>=0 && tempY>=0 && tempX<totalRow && tempY<totalColumn && seedX!=0 && seedY!=0){
                if(nElmt==1){
                    if(E1 == 1 || E1==3 || E1==4){ //fire electric ground
                        if(mapTemplate[tempX][tempY]==GRASS && mapArea[tempX][tempY]==EMPTY){
                            mapArea[tempX][tempY] = mapArea[it->second.getX()][it->second.getY()];
                            mapArea[it->second.getX()][it->second.getY()] = EMPTY;
                            it->second.setX(tempX);
                            it->second.setY(tempY);
                        }
                    }else if(E1==2 || E1 == 5){ //water ice
                        if(mapTemplate[tempX][tempY]==WATER && mapArea[tempX][tempY]==EMPTY){
                            mapArea[tempX][tempY] = mapArea[it->second.getX()][it->second.getY()];
                            mapArea[it->second.getX()][it->second.getY()] = EMPTY;
                            it->second.setX(tempX);
                            it->second.setY(tempY);
                        }
                    }
                }else if(nElmt==2){
                    int E2 = it->first.getElements()[1].getElementID();
                    if((E1==1 && E2==3)||(E1==3 && E2==1)){ //itachimon fire - electric
                        if(mapTemplate[tempX][tempY]==GRASS && mapArea[tempX][tempY]==EMPTY){
                            mapArea[tempX][tempY] = mapArea[it->second.getX()][it->second.getY()];
                            mapArea[it->second.getX()][it->second.getY()] = EMPTY;
                            it->second.setX(tempX);
                            it->second.setY(tempY);
                        }
                    }else if((E1==2 && E2==4)||(E1==4 && E2==2)){ //narutomon water-ground
                        if(mapArea[tempX][tempY]==EMPTY){
                            mapArea[tempX][tempY] = mapArea[it->second.getX()][it->second.getY()];
                            mapArea[it->second.getX()][it->second.getY()] = EMPTY;
                            it->second.setX(tempX);
                            it->second.setY(tempY);
                        }
                    }else if((E1==1 && E2==5)||(E1==5 && E2==1)){ //telermon ice-water
                        if(mapTemplate[tempX][tempY]==WATER && mapArea[tempX][tempY]==EMPTY){
                            mapArea[tempX][tempY] = mapArea[it->second.getX()][it->second.getY()];
                            mapArea[it->second.getX()][it->second.getY()] = EMPTY;
                            it->second.setX(tempX);
                            it->second.setY(tempY);
                        }
                    }
                }
            } 
        }
    }

    //refreshMap(p, e);

}

void Maps::generateEngimon(point p, point e, int round) {
    srand(time(NULL));
    if(wildEngimons.size()<this->totalEngimonSpawned){
        try{
            loadPlayerPos(p, e);
        }catch(const char* err){
            cout << err << endl;
        }

        point loc;
        loc.randomPoint(totalRow,totalColumn);

        //UNTUK MEMASTIKAN DIGENERATE DI LAHAN KOSONG
        while (mapArea[loc.getX()][loc.getY()]!=EMPTY) {
            loc.randomPoint(totalRow,totalColumn);
        }
        int lvl = (rand()%(round-1))+1;
        if(mapTemplate[loc.getX()][loc.getY()]==GRASS){
            int pil = rand()%5+1;
            if(pil==1){
                Groundmon E("randomGM","","","","",lvl);
                wildEngimons.push_back(
                        pair<Engimon,point>(E,loc)
                );
                if(lvl>=minLevel){
                    mapArea[loc.getX()][loc.getY()] = 'G';
                }else{
                    mapArea[loc.getX()][loc.getY()] = 'g';
                }
            }else if(pil==2){
                Electricmon E("randomEM","","","","",lvl);
                wildEngimons.push_back(
                        pair<Engimon,point>(E,loc)
                );
                if(lvl>=minLevel){
                    mapArea[loc.getX()][loc.getY()] = 'E';
                }else{
                    mapArea[loc.getX()][loc.getY()] = 'e';
                }
            }else if(pil==3){
                Firemon E("randomFM","","","","",lvl);
                wildEngimons.push_back(
                        pair<Engimon,point>(E,loc)
                );
                if(lvl>=minLevel){
                    mapArea[loc.getX()][loc.getY()] = 'F';
                }else{
                    mapArea[loc.getX()][loc.getY()] = 'f';
                }
            }else if(pil==4){
                Itachimon E("randomIM","","","","",lvl);
                wildEngimons.push_back(
                        pair<Engimon,point>(E,loc)
                );
                if(lvl>=minLevel){
                    mapArea[loc.getX()][loc.getY()] = 'L';
                }else{
                    mapArea[loc.getX()][loc.getY()] = 'l';
                }
            }else if(pil==5){
                Narutomon E("randomNM","","","","",lvl);
                wildEngimons.push_back(
                        pair<Engimon,point>(E,loc)
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
                Watermon E("randomWM","","","","",lvl);
                wildEngimons.push_back(
                        pair<Engimon,point>(E,loc)
                );
                if(lvl>=minLevel){
                    mapArea[loc.getX()][loc.getY()] = 'W';
                }else{
                    mapArea[loc.getX()][loc.getY()] = 'w';
                }
            }else if(pil==2){
                Icemon E("randomIM","","","","",lvl);
                wildEngimons.push_back(
                        pair<Engimon,point>(E,loc)
                );
                if(lvl>=minLevel){
                    mapArea[loc.getX()][loc.getY()] = 'I';
                }else{
                    mapArea[loc.getX()][loc.getY()] = 'i';
                }
            }else if(pil==3){
                Telermon E("randomTM","","","","",lvl);
                wildEngimons.push_back(
                        pair<Engimon,point>(E,loc)
                );
                if(lvl>=minLevel){
                    mapArea[loc.getX()][loc.getY()] = 'S';
                }else{
                    mapArea[loc.getX()][loc.getY()] = 's';
                }
            }else if(pil==4){
                Narutomon E("randomNM","","","","",lvl);
                wildEngimons.push_back(
                        pair<Engimon,point>(E,loc)
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

const list<pair<Engimon, point> > &Maps::getWildEngimons() const {
    return wildEngimons;
}

void Maps::loadPlayerPos(point p, point e){
    point playerPoint = p;
    point activeEngimonPoint = e;
    if(
            playerPoint.getX()>=0 &&
            playerPoint.getX() < totalRow &&
            playerPoint.getY() >=0 &&
            playerPoint.getY() < totalColumn
        )
    {
        for(int i=0; i<totalRow; i++){
            for(int j=0; j<totalColumn; j++){
                if(mapArea[i][j] == 'P' || mapArea[i][j] == 'X'){
                    mapArea[i][j] = EMPTY;
                }
            }
        }
        if(mapArea[playerPoint.getX()][playerPoint.getY()]==EMPTY){
            mapArea[playerPoint.getX()][playerPoint.getY()] = 'P';
            mapArea[activeEngimonPoint.getX()][activeEngimonPoint.getY()] = 'X';
        }else{
            throw ("player nabrak!");
        }
    }
    else{
        throw ("player loc out of area");
    }
}

void Maps::refreshMap(point p, point e){
    for(int i=0;i<totalRow;i++){
        for(int j=0;j<totalColumn;j++){
            mapArea[i][j] = EMPTY;
        }
    }
    loadPlayerPos(p, e);
    list<pair<Engimon,point> >::iterator it;
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
    list<pair<Engimon,point> >::iterator it;
    it = this->wildEngimons.begin();
    while (it!=wildEngimons.end() && flag==false){
        if(it->second==p){
            flag =true;
        }else{
            it++;
        }
    }
    if(flag){
        mapArea[it->second.getX()][it->second.getY()] = EMPTY;
        wildEngimons.erase(it);
    }
    return flag;
}
