#include "Skill.hpp"
using namespace std;

Element Fire("Fire");

int main(){
    Skill Skill0();
    bool *comp = new bool[5];
    for(int i=0; i<5; i++){
        comp[5] = false;
    }
    comp[3] = true;
    Skill Skill1("Earthquake", 2, 100, comp);
    Skill1.addMasteryLevel();
    cout << Skill1.learnable(Fire) << endl;
    cout << Skill1.totalPower() << endl;
}