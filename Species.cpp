#include "Species.hpp"
#include <iostream>

using namespace std;

Firemon::Firemon(string name, string _parentName, string _parentSpecies) : Engimon(name){
    this->species = "Firemon";
    this->parentName = _parentName;
    this->parentSpecies = _parentSpecies;
    // Skill *learnedSkill[4];
    // Skill skillfire(); ???
    // learnedSkill[0] = skillfire
    // element pake list kayanya ya ? declare elements
    // Element elementfire(); ???
    // elements[0] = elementfire
    this->countSkill = 1;
    this->countElement = 1;
}

Firemon::~Firemon(){
    // delete[] learnedSkill ??
    // delete[] elements ??
}

void Firemon::death(){
    cout << "Firemon " << this->name << " mati." << endl;
    this->death();
}

void Firemon::showDetail(){
    cout << "Nama " << this->name << endl;
    cout << "Nama parent " << this->parentName << " spesiesnya " << this->parentSpecies << "." << endl;
    cout << "Skill ";
    // for (int i=0; i < this->countSkill; i++){
    //     cout << learnedSkill[i];
    //     if (i != this->countSkill-1) {
    //         cout << ", ";
    // }
    cout << endl;
    cout << "Element ";
    // for (int i=0; i < this->countElement; i++){
    //     cout << elements[i];
    //     if (i != this->countElement-1) {
    //         cout << ", ";
    // }
    cout << endl;
    cout << "Level " << this->level << endl;
    cout << "Current Exp " << this->experience << endl;
    cout << "Akumulasi Exp " << this->maxCumulativeExperience << endl;
}

Watermon::Watermon(string name, string _parentName, string _parentSpecies) : Engimon(name){
    this->species = "Watermon";
    this->parentName = _parentName;
    this->parentSpecies = _parentSpecies;
    // Skill *learnedSkill[4];
    // Skill skillfire(); ???
    // learnedSkill[0] = skillfire
    // element pake list kayanya ya ? declare elements
    // Element elementfire(); ???
    // elements[0] = elementfire
    this->countSkill = 1;
    this->countElement = 1;
}

Watermon::~Watermon(){
    // delete[] learnedSkill ??
    // delete[] elements ??
}

void Watermon::death(){
    cout << "Watermon " << this->name << " mati." << endl;
    this->death();
}

void Watermon::showDetail(){
    cout << "Nama " << this->name << endl;
    cout << "Nama parent " << this->parentName << " spesiesnya " << this->parentSpecies << "." << endl;
    cout << "Skill ";
    // for (int i=0; i < this->countSkill; i++){
    //     cout << learnedSkill[i];
    //     if (i != this->countSkill-1) {
    //         cout << ", ";
    // }
    cout << endl;
    cout << "Element ";
    // for (int i=0; i < this->countElement; i++){
    //     cout << elements[i];
    //     if (i != this->countElement-1) {
    //         cout << ", ";
    // }
    cout << endl;
    cout << "Level " << this->level << endl;
    cout << "Current Exp " << this->experience << endl;
    cout << "Akumulasi Exp " << this->maxCumulativeExperience << endl;
}

Electricmon::Electricmon(string name, string _parentName, string _parentSpecies) : Engimon(name){
    this->species = "Electricmon";
    this->parentName = _parentName;
    this->parentSpecies = _parentSpecies;
    // Skill *learnedSkill[4];
    // Skill skillfire(); ???
    // learnedSkill[0] = skillfire
    // element pake list kayanya ya ? declare elements
    // Element elementfire(); ???
    // elements[0] = elementfire
    this->countSkill = 1;
    this->countElement = 1;
}

Electricmon::~Electricmon(){
    // delete[] learnedSkill ??
    // delete[] elements ??
}

void Electricmon::death(){
    cout << "Electricmon " << this->name << " mati." << endl;
    this->death();
}

void Electricmon::showDetail(){
    cout << "Nama " << this->name << endl;
    cout << "Nama parent " << this->parentName << " spesiesnya " << this->parentSpecies << "." << endl;
    cout << "Skill ";
    // for (int i=0; i < this->countSkill; i++){
    //     cout << learnedSkill[i];
    //     if (i != this->countSkill-1) {
    //         cout << ", ";
    // }
    cout << endl;
    cout << "Element ";
    // for (int i=0; i < this->countElement; i++){
    //     cout << elements[i];
    //     if (i != this->countElement-1) {
    //         cout << ", ";
    // }
    cout << endl;
    cout << "Level " << this->level << endl;
    cout << "Current Exp " << this->experience << endl;
    cout << "Akumulasi Exp " << this->maxCumulativeExperience << endl;
}

Groundmon::Groundmon(string name, string _parentName, string _parentSpecies) : Engimon(name){
    this->species = "Groundmon";
    this->parentName = _parentName;
    this->parentSpecies = _parentSpecies;
    // Skill *learnedSkill[4];
    // Skill skillfire(); ???
    // learnedSkill[0] = skillfire
    // element pake list kayanya ya ? declare elements
    // Element elementfire(); ???
    // elements[0] = elementfire
    this->countSkill = 1;
    this->countElement = 1;
}

Groundmon::~Groundmon(){
    // delete[] learnedSkill ??
    // delete[] elements ??
}

void Groundmon::death(){
    cout << "Groundmon " << this->name << " mati." << endl;
    this->death();
}

void Groundmon::showDetail(){
    cout << "Nama " << this->name << endl;
    cout << "Nama parent " << this->parentName << " spesiesnya " << this->parentSpecies << "." << endl;
    cout << "Skill ";
    // for (int i=0; i < this->countSkill; i++){
    //     cout << learnedSkill[i];
    //     if (i != this->countSkill-1) {
    //         cout << ", ";
    // }
    cout << endl;
    cout << "Element ";
    // for (int i=0; i < this->countElement; i++){
    //     cout << elements[i];
    //     if (i != this->countElement-1) {
    //         cout << ", ";
    // }
    cout << endl;
    cout << "Level " << this->level << endl;
    cout << "Current Exp " << this->experience << endl;
    cout << "Akumulasi Exp " << this->maxCumulativeExperience << endl;
}

Icemon::Icemon(string name, string _parentName, string _parentSpecies) : Engimon(name){
    this->species = "Icemon";
    this->parentName = _parentName;
    this->parentSpecies = _parentSpecies;
    // Skill *learnedSkill[4];
    // Skill skillfire(); ???
    // learnedSkill[0] = skillfire
    // element pake list kayanya ya ? declare elements
    // Element elementfire(); ???
    // elements[0] = elementfire
    this->countSkill = 1;
    this->countElement = 1;
}

Icemon::~Icemon(){
    // delete[] learnedSkill ??
    // delete[] elements ??
}

void Icemon::death(){
    cout << "Icemon " << this->name << " mati." << endl;
    this->death();
}

void Icemon::showDetail(){
    cout << "Nama " << this->name << endl;
    cout << "Nama parent " << this->parentName << " spesiesnya " << this->parentSpecies << "." << endl;
    cout << "Skill ";
    // for (int i=0; i < this->countSkill; i++){
    //     cout << learnedSkill[i];
    //     if (i != this->countSkill-1) {
    //         cout << ", ";
    // }
    cout << endl;
    cout << "Element ";
    // for (int i=0; i < this->countElement; i++){
    //     cout << elements[i];
    //     if (i != this->countElement-1) {
    //         cout << ", ";
    // }
    cout << endl;
    cout << "Level " << this->level << endl;
    cout << "Current Exp " << this->experience << endl;
    cout << "Akumulasi Exp " << this->maxCumulativeExperience << endl;
}