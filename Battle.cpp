#include "Player.hpp"
#include "Element.hpp"
#include "point.h"
#include "Maps.h"
#include <cstdlib>
using namespace std;

void Player::printAsciiArt(string name) {
    string x;
    ifstream inFile;

    inFile.open("./ascii/" + name + ".txt");

    while (getline(inFile,x)) {
        cout << x << endl ;
    }

    inFile.close();
}

int Player::calculateMaxAdvantageElement(Engimon sourceEngimon, Engimon comparedEngimon) {
    int advantage1;
    int advantage2;
    int maxAdvantage;
    Element * sourceElements = sourceEngimon.getElements();
    Element * comparedElements = comparedEngimon.getElements();
    if (sourceEngimon.getCountElement() == 2 && comparedEngimon.getCountElement() == 2)
    {
        for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < 2; j++)
                {
                    advantage1 = sourceElements[i].getAdvantage(comparedElements[j]);
                    if (maxAdvantage < advantage1)
                    {
                        maxAdvantage = advantage1;
                    }
                }
            }
    }
    else if (sourceEngimon.getCountElement() == 2)
    {  
        int advantage1 = sourceElements[0].getAdvantage(comparedElements[0]);
        int advantage2 = sourceElements[1].getAdvantage(comparedElements[0]);
        if (advantage1 >= advantage2)
            maxAdvantage = advantage1;
        else
            maxAdvantage = advantage2;
    }
    else if (comparedEngimon.getCountElement() == 2)
    {
        int advantage1 = sourceElements[0].getAdvantage(comparedElements[0]);
        int advantage2 = sourceElements[0].getAdvantage(comparedElements[1]);
        if (advantage1 >= advantage2)
            maxAdvantage = advantage1;
        else
            maxAdvantage = advantage2;
    }
    else
    {
        int advantage1 = sourceElements[0].getAdvantage(comparedElements[0]);
        int advantage2 = comparedElements[0].getAdvantage(sourceElements[0]);
    }
    
    return maxAdvantage;
}

int Player::calculateSkillPower(Engimon engimon) {
    int skillPower = 0;
    Skill* engimonSkills = engimon.getLearnedSkills();
    for (int i = 0; i < engimon.getCountSkill(); i++)
    {
        skillPower += engimonSkills[i].getBasePower()*engimonSkills[i].getMasteryLevel();
    }

    return skillPower;
}

void Player::battle(Maps& M) {
    // cek adjacent tiles 
    list<pair<Engimon,point>> wildEngimons = M.getWildEngimons();
    Engimon opponent;
    int powerPlayer = 0;
    int powerOpp = 0;
    int maxAdvantagePlayer;
    int maxAdvantageOpp;
    int wildEngimonX;
    int wildEngimonY;
    bool isEngimonAdjacent = false;
    bool battleEnded = false;

    // cek tempat engimon
    for (auto const& pairEngimonPoint : wildEngimons)
    {
        wildEngimonX = pairEngimonPoint.second.getX();
        wildEngimonY = pairEngimonPoint.second.getY();
        if (abs(wildEngimonX-playerPosition.getX()) <= 1 && abs(wildEngimonY-playerPosition.getY()) <= 1)
        {
            isEngimonAdjacent = true;
            Engimon opponent = pairEngimonPoint.first; // pake operator= harusnya
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
            // Element * activeEngimonElements = activeEngimon.getElements();
            // Element * opponentElements = opponent.getElements();
            // if (activeEngimon.getCountElement() == 2 && opponent.getCountElement() == 2)
            // {
            //     for (int i = 0; i < 2; i++)
            //     {
            //         for (int j = 0; j < 2; j++)
            //         {
            //             int advantage = activeEngimonElements[i].getAdvantage(opponentElements[j]);
            //             if (maxAdvantagePlayer < advantage)
            //             {
            //                 maxAdvantagePlayer = advantage;
            //             }
            //         }
            //     }

            //     for (int i = 0; i < 2; i++)
            //     {
            //         for (int j = 0; j < 2; j++)
            //         {
            //             int advantage = activeEngimonElements[i].getAdvantage(opponentElements[j]);
            //             if (maxAdvantageOpp < advantage)
            //             {
            //                 maxAdvantageOpp = advantage;
            //             }
            //         }
            //     }
            // }

            // else if (activeEngimon.getCountElement() == 2)
            // {
            //     int advantage1 = activeEngimonElements[0].getAdvantage(opponentElements[0]);
            //     int advantage2 = activeEngimonElements[1].getAdvantage(opponentElements[0]);
            //     if (advantage1 >= advantage2)
            //         maxAdvantagePlayer = advantage1;
            //     else
            //         maxAdvantagePlayer = advantage2;
                
            //     advantage1 = opponentElements[0].getAdvantage(activeEngimonElements[0]);
            //     advantage2 = opponentElements[0].getAdvantage(activeEngimonElements[1]);
            //     if (advantage1 >= advantage2)
            //         maxAdvantageOpp = advantage1;
            //     else
            //         maxAdvantageOpp = advantage2;
            // }

            // else if (opponent.getCountElement() == 2)
            // {
            //     int advantage1 = opponentElements[0].getAdvantage(activeEngimonElements[0]);
            //     int advantage2 = opponentElements[1].getAdvantage(activeEngimonElements[0]);
            //     if (advantage1 >= advantage2)
            //         maxAdvantageOpp = advantage1;
            //     else
            //         maxAdvantageOpp = advantage2;
                
            //     advantage1 = activeEngimonElements[0].getAdvantage(opponentElements[0]);
            //     advantage2 = activeEngimonElements[0].getAdvantage(opponentElements[1]);
            //     if (advantage1 >= advantage2)
            //         maxAdvantageOpp = advantage1;
            //     else
            //         maxAdvantageOpp = advantage2;
            // }

            // else
            // {
            //     int advantage1 = activeEngimonElements[0].getAdvantage(opponentElements[0]);
            //     int advantage2 = opponentElements[0].getAdvantage(activeEngimonElements[0]);
            // }

            // hitung total power dari skill
            powerPlayer += calculateSkillPower(activeEngimon);
            powerOpp += calculateSkillPower(opponent);
            // Skill* engimonSkills = activeEngimon.getLearnedSkills();
            // for (int i = 0; i < activeEngimon.getCountSkill(); i++)
            // {
            //     powerPlayer += engimonSkills[i].getBasePower()*engimonSkills[i].getMasteryLevel();
            // }
            
            // Skill * opponentSkills = opponent.getLearnedSkills();
            // for (int i = 0; i < opponent.getCountSkill(); i++)
            // {
            //     powerOpp += opponentSkills[i].getBasePower()*opponentSkills[i].getMasteryLevel();
            // }

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
                    int expEarned = (activeEngimon.getLevel()/opponent.getLevel()) * 100;
                    printAsciiArt("win");
                    cout << "Your " << activeEngimon.getName() << "got " << expEarned << " exp!" << endl;
                    inventoryE.addItem(opponent);
                    printAsciiArt("pokeball");
                    cout << "You got " << opponent.getName() << endl;
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
                opponent.death();
                callEngimon();
                battleEnded = true;
            }
            
        } while (!battleEnded);
    }
}