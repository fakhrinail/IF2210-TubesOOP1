#include "Engimon.hpp"
#include <iostream>

using namespace std;

int Engimon::maxCumulativeExperience = 5000;

Engimon::Engimon(){
    this->name = "";
    this->species = "";
    this->parentName = new string[2];
    this->parentSpecies = new string[2];
    this->learnedSkills = new Skill[4];
    this->elements = new Element[3];
    this->level = 0;
    this->experience = 0;
    this->cumulativeExperience = 0;
    this->countElement = 0;
    this->countSkill = 0;
}

Engimon::Engimon(string _name, string _species, string _parentName, string _parentSpecies, string _parentName2, string _parentSpecies2, int _level){
    this->name = _name;
    this->species = _species;
    this->parentName = new string[2];
    this->parentSpecies = new string[2];
    this->parentName[0] = _parentName; this->parentName[1] = _parentName2;
    this->parentSpecies[0] = _parentSpecies; this->parentSpecies[1] = _parentSpecies2;
    this->learnedSkills = new Skill[4];
    this->elements = new Element[3];
    this->level = _level;
    this->experience = 0;
    this->cumulativeExperience = 0;
    this->countElement = 0;
    this->countSkill = 0;
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
    cout << "Nama parent 1 " << this->parentName[0] << " spesiesnya " << this->parentSpecies[0] << "." << endl;
    cout << "Nama parent 2 " << this->parentName[1] << " spesiesnya " << this->parentSpecies[1] << "." << endl;
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
    bool isLearned = false;
    
    for (int i=0; i<this->countSkill; i++){
        if (learnedSkills[i] == s) {
            isLearned = true;
        }
    }
    
    if (isLearned) {
        cout << "Engimon sudah memiliki skill " << s.getSkillName() << endl;
    } else if (this->countSkill == 4) {
        int toReplace;
        cout << "Skill engimon sudah penuh." << endl;

        for (int k=0; k<this->countSkill; k++) {
            cout << k+1 << ". " << this->learnedSkills[k] << endl;
        }
        
        cout << "Pilih urutan skill untuk di replace(1,2,3,4): ";
        cin >> toReplace;
        this->learnedSkills[toReplace-1] = s;
        cout << "Engimon berhasil mereplace skill slot " << toReplace << " dengan " << s.getSkillName() << endl;
    } else {
        bool isLearnable = false; int j = 0;

        while (!isLearnable && j < this->countElement) {
            if (s.learnable(this->elements[j])) {
                this->learnedSkills[this->countSkill] = s;
                this->countSkill++;
                isLearnable = true;
                cout << "Engimon berhasil mempelajari skill " << s.getSkillName() << endl;
            }
            j++;
        }

        if (!isLearnable) {
            cout << "Engimon tidak dapat mempelajari skill" << endl;
        }
    }
}

bool Engimon::operator==(const Engimon& other) const {
    return false; //request dari player
}

ostream& operator<<(ostream& os, const Engimon& s){
    os << s.getName();
    return os;
}