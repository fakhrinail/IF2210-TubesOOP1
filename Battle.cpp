#include "PlayerMaps.hpp"
#include <bits/stdc++.h>
using namespace std;

void printAsciiArt(string name) {
    string x;
    ifstream inFile;
    string filename = "./ascii/" + name + ".txt";
    inFile.open(filename.c_str());

    while (getline(inFile,x)) {
        cout << x << endl ;
    }

    inFile.close();
}

float calculateMaxAdvantageElement(Engimon sourceEngimon, Engimon comparedEngimon) {
    float maxAdvantage = 0.0;
    Element E1, E2;
    for(int i=0; i<sourceEngimon.getCountElement(); i++){
        for(int j=0; j<comparedEngimon.getCountElement(); j++){
            E1 = sourceEngimon.getElements()[i];
            E2 = comparedEngimon.getElements()[j];
            maxAdvantage = max(maxAdvantage, E1.getAdvantage(E2));
        }
    }
    return maxAdvantage;
}

float calculateSkillPower(Engimon engimon) {
    float skillPower = 0;
    Skill* engimonSkills = engimon.getLearnedSkills();
    for (int i = 0; i < engimon.getCountSkill(); i++)
    {
        skillPower += engimonSkills[i].totalPower();
    }

    return skillPower;
}

void Player::battle(Maps& M) {
    // cek adjacent tiles 
    list<pair<Engimon,point> > wildEngimons = M.getWildEngimons();
    list<pair<Engimon,point> > :: iterator itr;
    Engimon opponent;
    float powerPlayer = 0.0;
    float powerOpp = 0.0;
    float maxAdvantagePlayer;
    float maxAdvantageOpp;
    int wildEngimonX;
    int wildEngimonY;
    bool isEngimonAdjacent = false;
    bool battleEnded = false;

    // cek tempat engimon
    for(itr = wildEngimons.begin(); itr!= wildEngimons.end(); itr++){
        pair<Engimon,point> pairEngimonPoint = *itr;
        wildEngimonX = pairEngimonPoint.second.getX();
        wildEngimonY = pairEngimonPoint.second.getY();
        if (abs(wildEngimonX-playerPosition.getX()) + abs(wildEngimonY-playerPosition.getY()) <= 1)
        {
            isEngimonAdjacent = true;
            opponent = pairEngimonPoint.first; // pake operator= harusnya
            activeEngimon.showDetail();
            printAsciiArt("battle");
            opponent.showDetail();
            break;
        }
    }
    if (!isEngimonAdjacent)
    {
        cout << "There is no engimon adjacent to you" << endl;
    }
    else
    {
        // do compare stats
        do
        {
            // ambil advantage
            maxAdvantagePlayer = calculateMaxAdvantageElement(activeEngimon, opponent);
            maxAdvantageOpp = calculateMaxAdvantageElement(opponent, activeEngimon);
            
            // hitung total power dari skill
            powerPlayer += calculateSkillPower(activeEngimon);
            powerOpp += calculateSkillPower(opponent);

            // hitung total power
            powerPlayer += activeEngimon.getLevel()*maxAdvantagePlayer;
            powerOpp += opponent.getLevel()*maxAdvantageOpp;
            cout << activeEngimon.getName() << "has " << powerPlayer << " VS " << opponent.getName() << " with " << powerOpp << endl;

            // compare stats
            // TODO : bikin condition engimon habis
            if (powerPlayer < powerOpp) // kalah
            {
                printAsciiArt("rip");
                cout << "RIP " << activeEngimon.getName() << ", oh well anyway" << endl;
                cout << "Choose a new Engimon!" << endl;
                activeEngimon.death(); // ??? bisa delete langsung atau harus simpan temp dulu
                callEngimon();
            }
            else if (powerPlayer > powerOpp) // menang
            {
                try
                {
                    int expEarned = (opponent.getLevel() * 100 / activeEngimon.getLevel());
                    printAsciiArt("win");
                    cout << "Your " << activeEngimon.getName() << "got " << expEarned << " exp!" << endl;
                    activeEngimon.addExperience(expEarned);
                    
                    inventoryE.addItem(opponent);
                    printAsciiArt("pokeball");
                    cout << "You got " << opponent.getName() << endl;
                    inventoryS.addItem(opponent.getLearnedSkills()[0]);
                    cout << "You got skill " << opponent.getLearnedSkills()[0].getSkillName() << endl;
                }
                catch(char* const err)
                {
                    cout << "Your inventory is already full" << endl;
                }

                battleEnded = true;
            }
            else // seri
            {
                printAsciiArt("rip");
                cout << "Well, you are both dead :(" << endl;
                activeEngimon.death();
                point wildEngimonPoint(wildEngimonX, wildEngimonY);
                M.deleteWildEngimon(wildEngimonPoint);
                try
                {
                    inventoryE.addItem(opponent);
                    printAsciiArt("pokeball");
                    cout << "You got " << opponent.getName() << endl;
                    inventoryS.addItem(opponent.getLearnedSkills()[0]);
                    cout << "You got skill " << opponent.getLearnedSkills()[0].getSkillName() << endl;
                }
                catch(char* const err)
                {
                    cout << "Your inventory is already full" << endl;
                }
                opponent.death();
                callEngimon();
                battleEnded = true;
            }
            
        } while (!battleEnded);
    }
}