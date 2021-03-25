#include "Skill.hpp"
using namespace std;

Skill::Skill(){
    this->skillName = "";
    this->masteryLevel = 0;
    this->basePower = 0;
    this->compatibleElements = 0;
}
Skill::Skill(string name, int ml, float bp, int ce){
    this->skillName = name;
    this->masteryLevel = ml;
    this->basePower = bp;
    this->compatibleElements = ce;
}
Skill& Skill::operator=(const Skill& other){
    this->skillName = other.skillName;
    this->masteryLevel = other.masteryLevel;
    this->basePower = other.basePower;
    this->compatibleElements = other.compatibleElements;
    return *this;
}
Skill::~Skill(){
}

//Getters
string Skill::getSkillName() const{
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
    return this->compatibleElements & (1<<(e.getElementID()-1));
}
bool Skill::operator==(const Skill& other) const {
    return this->skillName == other.skillName;
}
void Skill::showDetail() const {
    cout << "Nama " << this->skillName << endl;
    cout << "Mastery Level " << this->masteryLevel << endl;
    cout << "Base Power " << this->basePower << endl;
    cout << "Compatible Elements:";
    for(int i=1; i<6; i++){
        if(this->compatibleElements & (1<<(i-1))){
            cout << " " << Element::elementNames[i];
        }
    }
    cout << endl;
}
bool Skill::operator<(const Skill& other) const{
    return this->masteryLevel < other.masteryLevel;
}
Skill Skill::operator+(const Skill& other) const {
    if(!(*this == other)){
        throw ("Skill tidak sejenis");
    }
    int newML;
    if((*this) < other || other < (*this)){
        newML = max(this->masteryLevel, other.masteryLevel);
    }else{
        newML = other.masteryLevel + 1;
    }
    Skill result(other.skillName, newML, other.basePower, other.compatibleElements);
    return result;
}
ostream& operator<<(ostream& os, const Skill& s){
    os << s.getSkillName();
    return os;
}

