#include "PlayerMaps.hpp"
using namespace std;

int InventoryParent::maxCapacity = 30;
int InventoryParent::totalLoad = 0;

int main(){
    Maps M("tes.txt", 20, 25);
    Firemon Kinon("fire1", "Bapak", "Cowok", "Ibu", "Cowok", 25);
    Player Syamil(Kinon);
    Syamil.doCommands(M);
}


