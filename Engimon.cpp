#include "Engimon.hpp"
#include <iostream>

using namespace std;

int Engimon::maxLevel = 30;
int Engimon::maxCumulativeExperience = 3000;

Engimon::Engimon(string _name){
    this->name = _name;
    //parentname sepesies, learnedskill, elements 
    this->level = 0;
    this->experience = 0;
    this->cumulativeExperience = 0;
}

Engimon::~Engimon(){
    //delete[] elements, skills
}

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

void Engimon::death(){
    cout << "Engimon " << this->name << " mati.";
    this->~Engimon();
}

void Engimon::showDetail(){
    cout << "Nama engimon " << this->name << endl;
    //parentname spesies, skills, elements;
    cout << "Level engimon " << this->level << endl;
    cout << "Current Exp engimon " << this->experience << endl;
    cout << "Akumulasi Exp engimon " << this->maxCumulativeExperience << endl;
}