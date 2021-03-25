#include "Species.hpp"
#include <iostream>

using namespace std;

Firemon::Firemon(string _name, string _parentName, string _parentSpecies, int _level) : Engimon(_name, "Firemon", _parentName, _parentSpecies, _level){
    this->countSkill = 1;
    this->learnedSkills = new Skill[4];
    Skill Fireball("Fireball", 1, 100, 1);
    this->learnedSkills[0] = Fireball; 
    
    this->countElement = 1;
    this->elements = new Element[3];
    Element Fire("Fire");
    this->elements[0] = Fire;
}

Firemon::~Firemon(){}

void Firemon::interact(){
    cout << this->name << ": " << "Ready to burn down the forest, bos?" << endl;
}

Watermon::Watermon(string _name, string _parentName, string _parentSpecies, int _level) : Engimon(_name, "Watermon", _parentName, _parentSpecies, _level){
    this->countSkill = 1;
    this->learnedSkills = new Skill[4];
    Skill Waterbom("Waterbom", 1, 100, 2);
    this->learnedSkills[0] = Waterbom; 
    
    this->countElement = 1;
    this->elements = new Element[3];
    Element Water("Water");
    this->elements[0] = Water;
}

Watermon::~Watermon(){}

void Watermon::interact(){
    cout << this->name << ": " << "Even the atlantis was drowned." << endl;
}

Electricmon::Electricmon(string _name, string _parentName, string _parentSpecies, int _level) : Engimon(_name, "Electricmon", _parentName, _parentSpecies, _level){
    this->countSkill = 1;
    this->learnedSkills = new Skill[4];
    Skill Chidori("Chidori", 1, 100, 4);
    this->learnedSkills[0] = Chidori; 
    
    this->countElement = 1;
    this->elements = new Element[3];
    Element Electric("Electric");
    this->elements[0] = Electric;
}

Electricmon::~Electricmon(){}

void Electricmon::interact(){
    cout << this->name << ": " << "I'm the core of everything." << endl;
}

Groundmon::Groundmon(string _name, string _parentName, string _parentSpecies, int _level) : Engimon(_name, "Groundmon", _parentName, _parentSpecies, _level){
    this->countSkill = 1;
    this->learnedSkills = new Skill[4];
    Skill Pakubumi("Pakubumi", 1, 100, 8);
    this->learnedSkills[0] = Pakubumi; 
    
    this->countElement = 1;
    this->elements = new Element[3];
    Element Ground("Ground");
    this->elements[0] = Ground;
}

Groundmon::~Groundmon(){}

void Groundmon::interact(){
    cout << this->name << ": " << "Rule no.1: you make mistake, you grounded." << endl;
}

Icemon::Icemon(string _name, string _parentName, string _parentSpecies, int _level) : Engimon(_name, "Icemon", _parentName, _parentSpecies, _level){
    this->countSkill = 1;
    this->learnedSkills = new Skill[4];
    Skill Freeze("Freeze", 1, 100, 16);
    this->learnedSkills[0] = Freeze; 
    
    this->countElement = 1;
    this->elements = new Element[3];
    Element Ice("Ice");
    this->elements[0] = Ice;
}

Icemon::~Icemon(){}

void Icemon::interact(){
    cout << this->name << ": " << "Icy bitsy spider." << endl;
}

Itachimon::Itachimon(string _name, string _parentName, string _parentSpecies, int _level) : Engimon(_name, "Itachimon", _parentName, _parentSpecies, _level){
    this->countSkill = 1;
    this->learnedSkills = new Skill[4];
    Skill Izanami("Izanami", 1, 100, 5);
    this->learnedSkills[0] = Izanami; 
    
    this->countElement = 2;
    this->elements = new Element[3];
    Element Fire("Fire");
    Element Electric("Electric");
    this->elements[0] = Fire;
    this->elements[1] = Electric;
}

Itachimon::~Itachimon(){}

void Itachimon::interact(){
    cout << this->name << ": " << "A nameless engimon Who protects peace within its shadows, that is a true engimon." << endl;
}

Telermon::Telermon(string _name, string _parentName, string _parentSpecies, int _level) : Engimon(_name, "Telermon", _parentName, _parentSpecies, _level){
    this->countSkill = 1;
    this->learnedSkills = new Skill[4];
    Skill Drunk("Drunk", 0, 100, 18);
    this->learnedSkills[0] = Drunk; 
    
    this->countElement = 2;
    this->elements = new Element[3];
    Element Water("Water");
    Element Ice("Ice");
    this->elements[0] = Water;
    this->elements[1] = Ice;
}

Telermon::~Telermon(){}

void Telermon::interact(){
    cout << this->name << ": " << "buuurrrrppppp...." << endl;
}

Narutomon::Narutomon(string _name, string _parentName, string _parentSpecies, int _level) : Engimon(_name, "Narutomon", _parentName, _parentSpecies, _level){
    this->countSkill = 1;
    this->learnedSkills = new Skill[4];
    Skill Rasengan("Rasengan", 0, 100, 10);
    this->learnedSkills[0] = Rasengan; 
    
    this->countElement = 2;
    this->elements = new Element[3];
    Element Water("Water");
    Element Ground("Ground");
    this->elements[0] = Water;
    this->elements[1] = Ground;
}

Narutomon::~Narutomon(){}

void Narutomon::interact(){
    cout << this->name << ": " << "datebayoo" << endl;
}