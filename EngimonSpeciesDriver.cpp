#include <iostream>
#include "Engimon.hpp"
#include "Species.hpp"
#include "Skill.hpp"
#include "Element.hpp"

using namespace std;

int main() {
  Engimon* listEngimon[4];
  Firemon fire("fire1", "", "", "", "", 1);
  listEngimon[0] = &fire;
  listEngimon[1] = new Watermon("water1", "bopak", "lady gaga", "bapok", "gagah", 1);

  //detail
  listEngimon[0]->showDetail();
  listEngimon[1]->showDetail();

  cout << "\nlearn skill" << endl;
  Skill sharingan("sharingan", 0, 100, 1);
  listEngimon[0]->learnSkill(sharingan);
  listEngimon[0]->learnSkill(sharingan);
  Skill shaingan("shaingan", 0, 100, 1);
  listEngimon[0]->learnSkill(shaingan);
  Skill sharinggan("sharinggan", 0, 100, 1);
  listEngimon[0]->learnSkill(sharinggan);
  Skill sharinan("sharinan", 0, 100, 1);
  listEngimon[0]->learnSkill(sharinan);
  listEngimon[0]->addExperience(4000);
  cout << listEngimon[0]->getCountSkill() << 
  listEngimon[1]->getCountElement() << listEngimon[1]->getName() << endl;

  cout << "\ndetail setelah ditambah" << endl;
  listEngimon[0]->showDetail();

  //interact coba
  cout << "\ninteract engimon" << endl;
  listEngimon[0]->interact();
  listEngimon[1]->interact();

  listEngimon[0]->death();

  return 0;
}