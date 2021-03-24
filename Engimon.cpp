#include "Engimon.hpp"
#include <iostream>

using namespace std;

int Engimon::maxLevel = 50;
int Engimon::maxCumulativeExperience = 5000;

Engimon::Engimon(string _name, string _species, string _parentName, string _parentSpecies){
    this->name = _name;
    this->species = _species;
    this->parentName = _parentName;
    this->parentSpecies = _parentSpecies;
    this->level = 1;
    this->experience = 0;
    this->cumulativeExperience = 0;
}

Engimon::Engimon(const Engimon& e){
    this->name = e.name;
    this->species = e.species;
    this->parentName = e.parentName;
    this->parentSpecies = e.parentSpecies;
    this->level = e.level;
    this->experience = e.experience;
    this->cumulativeExperience = e.cumulativeExperience;
    this->countSkill = e.countSkill;
    this->learnedSkills = new Skill[4];
    for (int i=0; i<this->countSkill; i++){
        this->learnedSkills[i] = e.learnedSkills[i];
    }
    this->countElement = e.countElement;
    this->elements = new Element[3];
    for (int j=0; j<this->countElement; j++){
        this->elements[j] = e.elements[j];
    }
}

Engimon& Engimon::operator=(const Engimon& e){
    this->name = e.name;
    this->species = e.species;
    this->parentName = e.parentName;
    this->parentSpecies = e.parentSpecies;
    this->level = e.level;
    this->experience = e.experience;
    this->cumulativeExperience = e.cumulativeExperience;
    this->countSkill = e.countSkill;
    this->learnedSkills = new Skill[4];
    for (int i=0; i<this->countSkill; i++){
        this->learnedSkills[i] = e.learnedSkills[i];
    }
    this->countElement = e.countElement;
    this->elements = new Element[3];
    for (int j=0; j<this->countElement; j++){
        this->elements[j] = e.elements[j];
    }

    return *this;
}

Engimon::~Engimon(){
    delete[] this->learnedSkills;
    delete[] this->elements;
}

string Engimon::getName() const{
    return this->name;
}

int Engimon::getCountElement(){
    return this->countElement;
}

int Engimon::getCountSkill(){
    return this->countSkill;
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

void Engimon::showDetail(){
    cout << "Nama " << this->name << endl;
    cout << "Nama parent " << this->parentName << " spesiesnya " << this->parentSpecies << "." << endl;
    cout << "Level " << this->level << endl;
    cout << "Current Exp " << this->experience << endl;
    cout << "Akumulasi Exp " << this->maxCumulativeExperience << endl;
    cout << "Skill ";
    for (int i=0; i < this->countSkill; i++){
        cout << this->learnedSkills[i].getSkillName();
        if (i != this->countSkill-1) {
            cout << ", ";
        }
    }
    cout << endl;
    cout << "Element ";
    for (int i=0; i < this->countElement; i++){
        cout << this->elements[i].getElementName();
        if (i != this->countElement-1) {
            cout << ", ";
        }
    }
    cout << endl;
}

void Engimon::learnSkill(Skill& s){
    this->learnedSkills[this->countSkill] = s;
    this->countSkill++;
}

bool Engimon::operator==(const Engimon& other) const {
    return false; //request dari player
}

ostream& operator<<(ostream& os, const Engimon& s){
    os << s.getName();
    return os;
}