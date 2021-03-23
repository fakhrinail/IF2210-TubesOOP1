#include "Engimon.hpp"
#include <iostream>

using namespace std;

int Engimon::maxLevel = 50;
int Engimon::maxCumulativeExperience = 5000;

Engimon::Engimon(string _name){
    this->name = _name;
    this->level = 0;
    this->experience = 0;
    this->cumulativeExperience = 0;
}

Engimon::~Engimon(){}

void Engimon::addExperience(int _exp){
    this->experience = this->experience + _exp;
    this->cumulativeExperience = this->cumulativeExperience + _exp;
    if (this->experience > 100){
        int addLevel = this->experience/100;
        for (int i=0; i<addLevel; i++){
            this->levelUp();
        }
    }

}

void Engimon::levelUp(){
    if (this->level+1 <= maxLevel && this->cumulativeExperience < maxCumulativeExperience){
        this->level++;
        this->experience = this->experience-100;
    }
    this->death();
}