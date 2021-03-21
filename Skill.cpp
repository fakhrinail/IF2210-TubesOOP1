#include "Skill.hpp"
using namespace std;

Skill::Skill(){
    this->skillName = new char[0];
    this->masteryLevel = 0;
    this->basePower = 0;
    for(int i=0; i<5; i++){
        this->compatibleElements[i] = false;
    }
}
Skill::Skill(char* name, int ml, float bp, bool* ce){
    int len = strlen(name);
    this->skillName = new char[len];
    for(int i=0; i<len; i++){
        this->skillName[i] = name[i];
    }
    this->masteryLevel = ml;
    this->basePower = bp;
    for(int i=0; i<5; i++){
        this->compatibleElements[i] = ce[i];
    }
}
Skill& Skill::operator=(const Skill& other){
    int len = strlen(other.skillName);
    this->skillName = new char[len];
    for(int i=0; i<len; i++){
        this->skillName[i] = other.skillName[i];
    }
    this->masteryLevel = other.masteryLevel;
    this->basePower = other.basePower;
    for(int i=0; i<5; i++){
        this->compatibleElements[i] = other.compatibleElements[i];
    }
    return *this;
}
Skill::~Skill(){
    delete[] this->skillName;
}

//Getters
char* Skill::getSkillName(){
    return this->skillName;
}
int Skill::getMasteryLevel(){
    return this->masteryLevel;
}
float Skill::getBasePower(){
    return this->basePower;
}

//Methods
void Skill::addMasteryLevel(){
    this->masteryLevel++;
}
float Skill::totalPower() const{
    return ((float) this->masteryLevel) * (this->basePower);
}
bool Skill::learnable(const Element& e) const {
    return this->compatibleElements[e.getElementID()];
}