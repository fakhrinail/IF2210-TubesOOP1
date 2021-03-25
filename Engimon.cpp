#include "Engimon.hpp"
#include <iostream>

using namespace std;

int Engimon::maxCumulativeExperience = 5000;

Engimon::Engimon() : Engimon("engimon", "engimon", "engimon", "engimon", 0){}

Engimon::Engimon(string _name, string _species, string _parentName, string _parentSpecies, int _level){
    this->name = _name;
    this->species = _species;
    this->parentName = _parentName;
    this->parentSpecies = _parentSpecies;
    this->learnedSkills = new Skill[4];
    this->elements = new Element[3];
    this->level = _level;
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

int Engimon::getCountElement() const{
    return this->countElement;
}

int Engimon::getCountSkill() const{
    return this->countSkill;
}

int Engimon::getLevel() const{
    return this->level;
}

Element* Engimon::getElements() const{
    return this->elements;
}

Skill* Engimon::getLearnedSkills() const{
    return this->learnedSkills;
}

void Engimon::interact(){
    cout << "Hello bos" << endl;
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
    if (this->cumulativeExperience < maxCumulativeExperience){
        this->level++;
        this->experience = this->experience-100;
    } else {
        this->death();
    }
}

void Engimon::death(){
    cout << "Engimon " << this->name << " mati." << endl;
    this->~Engimon();
}

void Engimon::showDetail(){
    cout << "Nama " << this->name << endl;
    cout << "Nama parent " << this->parentName << " spesiesnya " << this->parentSpecies << "." << endl;
    cout << "Level " << this->level << endl;
    cout << "Current Exp " << this->experience << endl;
    cout << "Akumulasi Exp " << this->cumulativeExperience << endl;
    cout << "Skill ";
    for (int i=0; i < this->countSkill; i++){
        cout << this->learnedSkills[i].getSkillName();
        if (i != this->countSkill-1) {
            cout << ", ";
        }
    }
    cout << endl;
    cout << "Element ";
    for (int j=0; j < this->countElement; j++){
        cout << this->elements[j].getElementName();
        if (j != this->countElement-1) {
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