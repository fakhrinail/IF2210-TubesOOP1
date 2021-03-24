#include "Species.hpp"
#include <iostream>

using namespace std;

Firemon::Firemon(string _name, string _parentName, string _parentSpecies) : Engimon(_name, "Firemon", _parentName, _parentSpecies){
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
    this->~Firemon();
}

void Firemon::showDetail(){
    Engimon::showDetail();
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
}

Watermon::Watermon(string _name, string _parentName, string _parentSpecies) : Engimon(_name, "Watermon", _parentName, _parentSpecies){
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
    this->~Watermon();
}

void Watermon::showDetail(){
    Engimon::showDetail();
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
}

Electricmon::Electricmon(string _name, string _parentName, string _parentSpecies) : Engimon(_name, "Electricmon", _parentName, _parentSpecies){
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
    this->~Electricmon();
}

void Electricmon::showDetail(){
    Engimon::showDetail();
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
}

Groundmon::Groundmon(string _name, string _parentName, string _parentSpecies) : Engimon(_name, "Groundmon", _parentName, _parentSpecies){
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
    this->~Groundmon();
}

void Groundmon::showDetail(){
    Engimon::showDetail();
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
}

Icemon::Icemon(string _name, string _parentName, string _parentSpecies) : Engimon(_name, "Icemon", _parentName, _parentSpecies){
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
    this->~Icemon();
}

void Icemon::showDetail(){
    Engimon::showDetail();
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
}