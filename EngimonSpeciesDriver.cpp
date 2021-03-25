#include <iostream>
#include "Engimon.hpp"
#include "Species.hpp"
#include "Skill.hpp"
#include "Element.hpp"

int main() {
  Engimon* listEngimon[4];
  Firemon fire("fire1", "", "");
  listEngimon[0] = &fire;
  listEngimon[1] = new Watermon("water1", "bopak", "lady gaga");

  //detail
  listEngimon[0]->showDetail();
  listEngimon[1]->showDetail();

  //interact coba
  listEngimon[0]->interact();
  listEngimon[1]->interact();

  listEngimon[0]->death();

  return 0;
}