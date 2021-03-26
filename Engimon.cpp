#include "Engimon.hpp"
#include "Species.hpp"
#include <iostream>

using namespace std;

int Engimon::maxCumulativeExperience = 5000;

Engimon::Engimon() : Engimon("engimon", "engimon", "engimon", "engimon", "engimon", "engimon", 0){}

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

Engimon Engimon::operator+(Engimon& other){
    if (this->level > 30 && other.level > 30){
        //string nama; cout << "Masukan nama";
        //cin << nama;
        Engimon child;
        //proses
        
        //Elements
        //Element* childElements = new Element[2];
        if (this->elements[0].getElementID() == other.elements[0].getElementID()){ //operator
            if (this->elements[0].getElementID() == 1){
                Firemon dummy("aaa","","","","",1);
                child = dummy;
            } else if (this->elements[0].getElementID() == 2)
            {
                Watermon dummy("aaa","","","","",1);
                child = dummy;
            } else if (this->elements[0].getElementID() == 3)
            {
                Electricmon dummy("aaa","","","","",1);
                child = dummy;
            } else if (this->elements[0].getElementID() == 4)
            {
                Groundmon dummy("aaa","","","","",1);
                child = dummy;
            } else if (this->elements[0].getElementID() == 5)
            {
                Icemon dummy("aaa","","","","",1);
                child = dummy;
            }
            //childElements[1] = this->elements[1];
        } else{
            float this_over_other_adv = this->elements[0].getAdvantage(other.elements[0]);
            float other_over_this_adv = other.elements[0].getAdvantage(this->elements[0]);
            if (this_over_other_adv > other_over_this_adv){
               if (this->elements[0].getElementID() == 1){
                    Firemon dummy("aaa","","","","",1);
                    child = dummy;
                } else if (this->elements[0].getElementID() == 2)
                {
                    Watermon dummy("aaa","","","","",1);
                    child = dummy;
                } else if (this->elements[0].getElementID() == 3)
                {
                    Electricmon dummy("aaa","","","","",1);
                    child = dummy;
                } else if (this->elements[0].getElementID() == 4)
                {
                    Groundmon dummy("aaa","","","","",1);
                    child = dummy;
                } else if (this->elements[0].getElementID() == 5)
                {
                    Icemon dummy("aaa","","","","",1);
                    child = dummy;
                }
            } else if (other_over_this_adv > this_over_other_adv){
               if (this->elements[0].getElementID() == 1){
                    Firemon dummy("aaa","","","","",1);
                    child = dummy;
                } else if (other.elements[0].getElementID() == 2)
                {
                    Watermon dummy("aaa","","","","",1);
                    child = dummy;
                } else if (other.elements[0].getElementID() == 3)
                {
                    Electricmon dummy("aaa","","","","",1);
                    child = dummy;
                } else if (other.elements[0].getElementID() == 4)
                {
                    Groundmon dummy("aaa","","","","",1);
                    child = dummy;
                } else if (other.elements[0].getElementID() == 5)
                {
                    Icemon dummy("aaa","","","","",1);
                    child = dummy;
                }
            } else {
                if ((this->elements[0].getElementID() == 1 && other.elements[0].getElementID() == 3) ||
                    (other.elements[0].getElementID() == 1 && this->elements[0].getElementID() == 3)){
                    Itachimon dummy("aaa","","","","",1);
                    child = dummy;
                } else if ((this->elements[0].getElementID() == 2 && other.elements[0].getElementID() == 5) ||
                           (other.elements[0].getElementID() == 2 && this->elements[0].getElementID() == 5))
                {
                    Telermon dummy("aaa","","","","",1);
                    child = dummy;
                } else if ((this->elements[0].getElementID() == 2 && other.elements[0].getElementID() == 4) ||
                           (other.elements[0].getElementID() == 2 && this->elements[0].getElementID() == 4))
                {
                    Narutomon dummy("aaa","","","","",1);
                    child = dummy;
                }
               child.elements[0] = this->elements[0];
               child.elements[1] = other.elements[0];
            }
        }
        cout << "Error1";
        //Skill
        Skill* this_Skill = this->getLearnedSkills(); int this_size = this->getCountSkill();
        Skill* other_Skill = other.getLearnedSkills(); int other_size = other.countSkill;
        int count = 0;
        while (count < 3){
            cout << "Error2";
            int this_i = 0; int other_i = 0;
            int maxMasterythis = 0; int maxMasteryother = 0;
            while (this_i < this_size){
                if (this_Skill[this_i].getMasteryLevel() > maxMasterythis){
                    maxMasterythis = this_i;
                }
                this_i++;
            }
            while (other_i < this_size){
                if (other_Skill[other_i].getMasteryLevel() > maxMasteryother){
                    maxMasteryother = other_i;
                }
                other_i++;
            }
            if (this_Skill[this_i].getMasteryLevel() >= other_Skill[this_i].getMasteryLevel()){
                int idx = findSkill(child.learnedSkills, this_size, this_Skill[this_i]);
                if (idx < 0){
                    child.learnSkill(this_Skill[maxMasterythis]);
                    count++;
                }
                this_size = deleteSkill(this_Skill, this_size, this_Skill[maxMasterythis]);
            } else {
                int idx = findSkill(child.learnedSkills, other_size, other_Skill[other_i]);
                if (idx < 0){
                    child.learnSkill(other_Skill[maxMasteryother]);
                    count++;
                }
                other_size = deleteSkill(other_Skill, other_size, other_Skill[maxMasteryother]);
            }
            
        }
        
        this->level -= 30;
        other.level -= 30;
        return child;
    } else{
        //pesan kesalahan
        throw;
    }
}

int deleteSkill(Skill* arrS, int n, Skill x)
{
   // Search x in array
   int i;
   for (i=0; i<n; i++)
      if (arrS[i] == x)
         break;
  
   // If x found in array
   if (i < n)
   {
     // reduce size of array and move all
     // elements on space ahead
     n = n - 1;
     for (int j=i; j<n; j++)
        arrS[j] = arrS[j+1];
   }
  
   return n;
}

int findSkill(Skill* arrS, int n, Skill x){
    int i;
    for (i=0; i<n; i++)
       if (arrS[i] == x)
        return i;
    return -1;
}

float max(float a, float b){
    if (a > b){
        return a;
    } return b;
}
