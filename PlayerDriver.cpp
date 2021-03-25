#include "Player.hpp"
using namespace std;

int InventoryParent::maxCapacity = 30;
int InventoryParent::totalLoad = 0;

int main(){
    Skill Skill1("Earthquake", 0, 100, 31);
    Skill Skill2("Shadow Dance", 0, 50, 23);
    Skill Skill3("Mindbreak", 0, 200, 4);
    Firemon Kinon("fire1", "Bapak", "Cowok", "Ibu", "Cowok", 1);
    Electricmon pikachu("pikachu", "Bapak", "Cewek", "Ibu", "Cewek", 5);
	Groundmon ningguang("ningguang", "Bapak", "Cewek", "Ibu", "Cowok", 3);
    Player Syamil(Kinon);
    Syamil.addEngimon(Kinon);
    Syamil.addEngimon(pikachu);
    Syamil.addEngimon(ningguang);
    Syamil.addEngimon(Kinon);
    Syamil.addEngimon(pikachu);
    Syamil.addEngimon(ningguang);
    for(int i=0; i<7; i++){
        Syamil.addSkill(Skill1);
        Syamil.addSkill(Skill2);
        Syamil.addSkill(Skill3);
    }
    for(int i=0; i<5; i++){
        try{
            Syamil.addSkill(Skill1);
        }catch(const char* err){
            cout << err << endl;
        }
    }
    for(int i=0; i<10; i++){
        Syamil.printAllInventory();
        Syamil.manageActiveEngimon();
    }
}