#include "Skill.hpp"
using namespace std;

Element Fire("Fire");

int main(){
    Skill Skill0();
    Skill Skill1("Earthquake", 2, 100, 31);
    Skill Skill2("Earthquake", 3, 100, 31);
    Skill Skill3("Earthquake", 3, 100, 31);
    Skill dummy("Dummy", 0, 0, 0);
    cout << (Skill1 < Skill2) << endl;
    Skill Skill4 = Skill1 + Skill2;
    Skill4.showDetail();
    Skill4 = Skill2 + Skill3;
    Skill2.addMasteryLevel();
    cout << (Skill3 < Skill2) << endl;
    Skill4.showDetail();
}