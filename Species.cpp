#include "Species.hpp"
#include <iostream>

using namespace std;

Firemon::Firemon(string _name, string _parentName, string _parentSpecies) : Engimon(_name, "Firemon", _parentName, _parentSpecies){
    this->countSkill = 1;
    this->learnedSkills = new Skill[4];
    Skill Fireball("Fireball", 0, 100, 0); // gatau parameter 4 asli nan :(
    this->learnedSkills[0] = Fireball; 
    
    this->countElement = 1;
    this->elements = new Element[3];
    Element Fire(0, "Fire");
    this->elements[0] = Fire;
}

Firemon::~Firemon(){}

void Firemon::interact(){
    cout << this->name << ": " << "Ready to burn down the forest, bos?" << endl;
}

Watermon::Watermon(string _name, string _parentName, string _parentSpecies) : Engimon(_name, "Watermon", _parentName, _parentSpecies){
    this->countSkill = 1;
    this->learnedSkills = new Skill[4];
    Skill Waterbom("Waterbom", 0, 100, 0); // gatau parameter 4 asli nan :(
    this->learnedSkills[0] = Waterbom; 
    
    this->countElement = 1;
    this->elements = new Element[3];
    Element Water(1, "Water");
    this->elements[0] = Water;
}

Watermon::~Watermon(){}

void Watermon::interact(){
    cout << this->name << ": " << "Even the atlantis was drowned." << endl;
}

Electricmon::Electricmon(string _name, string _parentName, string _parentSpecies) : Engimon(_name, "Electricmon", _parentName, _parentSpecies){
    this->countSkill = 1;
    this->learnedSkills = new Skill[4];
    Skill Chidori("Chidori", 0, 100, 0); // gatau parameter 4 asli nan :(
    this->learnedSkills[0] = Chidori; 
    
    this->countElement = 1;
    this->elements = new Element[3];
    Element Electric(2, "Electric");
    this->elements[0] = Electric;
}

Electricmon::~Electricmon(){}

void Electricmon::interact(){
    cout << this->name << ": " << "I'm the core of everything." << endl;
}

Groundmon::Groundmon(string _name, string _parentName, string _parentSpecies) : Engimon(_name, "Groundmon", _parentName, _parentSpecies){
    this->countSkill = 1;
    this->learnedSkills = new Skill[4];
    Skill Pakubumi("Pakubumi", 0, 100, 0); // gatau parameter 4 asli nan :(
    this->learnedSkills[0] = Pakubumi; 
    
    this->countElement = 1;
    this->elements = new Element[3];
    Element Ground(3, "Ground");
    this->elements[0] = Ground;
}

Groundmon::~Groundmon(){}

void Groundmon::interact(){
    cout << this->name << ": " << "Rule no.1: you make mistake, you grounded." << endl;
}

Icemon::Icemon(string _name, string _parentName, string _parentSpecies) : Engimon(_name, "Icemon", _parentName, _parentSpecies){
    this->countSkill = 1;
    this->learnedSkills = new Skill[4];
    Skill Freeze("Freeze", 0, 100, 0); // gatau parameter 4 asli nan :(
    this->learnedSkills[0] = Freeze; 
    
    this->countElement = 1;
    this->elements = new Element[3];
    Element Ice(4, "Ice");
    this->elements[0] = Ice;
}

Icemon::~Icemon(){}

void Icemon::interact(){
    cout << this->name << ": " << "Icy bitsy spider." << endl;
}