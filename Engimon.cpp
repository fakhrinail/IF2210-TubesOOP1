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
        throw("Engimon sudah memiliki skill tersebut");
    } else {
        bool isLearnable = false; int j = 0;

        while (!isLearnable && j < this->countElement) {
            if (s.learnable(this->elements[j])) {
                if(this->countSkill == 4){
                    int toReplace;
                    cout << "Skill engimon sudah penuh." << endl;

                    for (int k=0; k<this->countSkill; k++) {
                        cout << k+1 << ". " << this->learnedSkills[k] << endl;
                    }
            
                    cout << "Pilih urutan skill untuk di replace(1,2,3,4): ";
                    cin >> toReplace;
                    this->learnedSkills[toReplace-1] = s;
                    cout << "Engimon berhasil mereplace skill slot " << toReplace << " dengan " << s.getSkillName() << endl;
                }else{
                    this->learnedSkills[this->countSkill] = s;
                    this->countSkill++;
                    isLearnable = true;
                    cout << "Engimon berhasil mempelajari skill " << s.getSkillName() << endl;
                }

            }
            j++;
        }

        if (!isLearnable) {
            throw("Engimon tidak dapat mempelajari skill");
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
/*
Engimon Engimon::operator+(Engimon& other){
    if (this->level > 30 && other.level > 30){
        //proses
        //Skill //asumsi kumpulan skill pakai stl list
        //Skill concatSkill;
        Skill childSkill = new Skill[4];
        //concatSkill.insert(concatSkill.end(), a.learnedSkill.begin(), a.learnedSkill.end());
        //concatSkill.insert(concatSkill.end(), b.learnedSkill.begin(), b.learnedSkill.end());
        Skill* this_Skill = this->getLearnedSkills(); int this_size = this->getCountSkill;
        Skill* other_Skill = other.getLearnedSkills(); int other_size = other.countSkill;
        //concatSkill.sort([] (Skill * first, Skill * second) {return first.masteryLevel > second.masteryLevel;});
        //childSkill.insert(childSkill.end(), concatSkill.begin(), 4);
        //int limitthis = 999; int limitother = 999;
        int count = 0;
        while (count < 4){
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
                int idx = findElementS(childSkill, this_size, this_Skill[this_i]);
                if (idx >= 0){
                    childSkill[count] = this_Skill[maxMasterythis];
                }
                this_size = deleteElementS(this_Skill, this_size, this_Skill[maxMasterythis])
            } else {
                int idx = findElementS(childSkill, other_size, other_Skill[other_i]);
                if (idx >= 0){
                    childSkill[count] = other_Skill[maxMasteryother];
                }
                other_size = deleteElementS(other_Skill, other_size, other_Skill[maxMasteryother])
            }
            count++;
        }
        
        //Elements
        Elements childElements = new Element[2];
        if (this->elements[0].getElementID == other.elements[0].getElementID){ //operator
            childElements[0] = this->elements[0]; //copy?
            //childElements[1] = this->elements[1];
        } else{
            float this_over_other_adv = this->elements[0].getAdvantage(other.elements[0]);
            float other_over_this_adv = other.elementsp[0].getAdvantage(this->elements[0]);
            if (this_over_other_adv > other_over_this_adv){
               childElements[0] = this->elements[0];
            } else if (other_over_this_adv > this_over_other_adv){
               childElements[0] = other.elements[0];
            } else {
               childElements[0] = this->elements[0];
               childElements[] = other.elements[0];
            }
        }
        
        string nama; cout << "Masukan nama";
        cin << nama;
        Engimon child = new Engimon(nama, a, b, spesies, childSkill, childElements)//ini belum dibuat
        a.level -= 30;
        b.level -= 30;
        return child;
    } else{
        //pesan kesalahan
        return NULL;
    }
}
*/

int deleteElementS(Skill* arrS, int n, Skill x)
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

int findElementS(Skill* arrS, int n, Skill x){
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