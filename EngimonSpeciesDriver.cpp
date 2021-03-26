#include <iostream>
#include "Engimon.hpp"
#include "Species.hpp"
#include "Skill.hpp"
#include "Element.hpp"

using namespace std;

int main(){
    Firemon arcanine("archy", "", "", "", "", 31);
    Firemon ninetales("nales", "", "", "", "", 31);
    Skill bite("bite", 2, 60, 1); arcanine.learnSkill(bite);
    Skill flamethrower("flamethrower", 4, 95, 1); arcanine.learnSkill(flamethrower);
    Skill extremespeed("extremespeed", 3, 80, 1); arcanine.learnSkill(extremespeed);
    //
    Skill shadowball("shadowball", 2, 80, 1); ninetales.learnSkill(shadowball);
    Skill fireblast("fireblast", 4, 120, 1); ninetales.learnSkill(fireblast);
    Skill solarbeam("solarbeam", 3, 80, 1); ninetales.learnSkill(solarbeam);
    //
    arcanine.showDetail();
    ninetales.showDetail();
    Engimon fennekin = arcanine+ninetales;
    fennekin.showDetail();
}