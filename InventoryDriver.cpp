#include "Inventory.hpp"
#include "Species.hpp"
using namespace std;

template<class T>
int Inventory<T>::maxCapacity = 30;
template<class T>
int Inventory<T>::totalLoad = 0;

int main(){
    Skill Skill1("Earthquake", 0, 100, 31);
    Skill Skill2("Shadow Dance", 0, 50, 23);
    Skill Skill3("Mindbreak", 0, 200, 4);
	cout << Skill1.getSkillName() << endl;
 	cout << Skill2.getSkillName() << endl;
 	cout << Skill3.getSkillName() << endl;
    Inventory<Skill> skillInventory;
    skillInventory.printItem();
    skillInventory.addItem(Skill1);
    skillInventory.addItem(Skill2);
    skillInventory.addItem(Skill1);
    skillInventory.addItem(Skill2);
 	skillInventory.addItem(Skill3);
 	skillInventory.printItem();
 	skillInventory.removeItem(0);
 	skillInventory.removeItem(0);
 	cout << endl;
 	skillInventory.printItem();
 	skillInventory.addItem(Skill1);
 	cout << endl;
 	skillInventory.printItem();
 	for(int i=0; i<30; i++){
		try{
			skillInventory.addItem(Skill1);
		}catch(char const* err){
			cout << err << endl;
		}
 	}
 	cout << endl;
 	skillInventory.printItem();
	skillInventory.getItem(2);
	skillInventory.printItem();
	skillInventory.showDetail(0);
	skillInventory.showDetail(1);
	skillInventory.showDetail(2);

	cout << endl;

	Firemon fire("fire1", "", "");
	Electricmon pikachu("pikachu", "", "");
	Groundmon ningguang("ningguang", "", "groundmon");
	Inventory<Engimon> engimonInventory;
	engimonInventory.addItem(fire);
	engimonInventory.addItem(pikachu);
	engimonInventory.addItem(ningguang);
	engimonInventory.addItem(fire);
	engimonInventory.printItem();
	cout << endl;
	engimonInventory.showDetail(2);
}