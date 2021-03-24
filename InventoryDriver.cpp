#include "Inventory.hpp"
using namespace std;

int main(){
    Skill Skill1("Earthquake", 0, 100, 31);
    Skill Skill2("Shadow Dance", 0, 50, 23);
    Skill Skill3("Mindbreak", 0, 200, 4);
    Inventory<Skill> skillInventory;
    skillInventory.printItem();
    skillInventory.addItem(Skill1);
    skillInventory.addItem(Skill2);
    skillInventory.addItem(Skill1);
    skillInventory.addItem(Skill2);
    skillInventory.printItem();
}