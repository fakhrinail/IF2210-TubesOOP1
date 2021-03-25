#include "Player.hpp"
#include "Element.hpp"
#include "point.h"
#include "Maps.h"
#include <cstdlib>
using namespace std;

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

void Player::battle(Maps& M) {
    // cek adjacent tiles 
    list<pair<Engimon,point>> wildEngimons = M.getWildEngimons();
    Engimon opponent("template", "template", "template", "template", 0);
    int powerPlayer = 0;
    int powerOpp = 0;
    int maxAdvantagePlayer = -1;
    int maxAdvantageOpp = -1;
    bool isEngimonAdjacent = false;
    bool battleEnded = false;

    // cek tempat engimon
    for (auto const& pairEngimonPoint : wildEngimons)
    {
        int engimonX = pairEngimonPoint.second.getX();
        int engimonY = pairEngimonPoint.second.getY();
        if (abs(engimonX-playerPosition.getX()) <= 1 && abs(engimonY-playerPosition.getY()) <= 1)
        {
            isEngimonAdjacent = true;
            Engimon opponent = pairEngimonPoint.first; // pake operator= harusnya
            opponent.showDetail();
            break;
        }
    }
    
    if (!isEngimonAdjacent)
    {
        cout << "Tidak ada engimon di dekat Anda" << endl;
    }
    else
    {
        // do compare stats
        do
        {
            // ambil advantage
            // TODO : rapiin masukin ke method antara
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
            // TODO : bikin method antara jg
            Skill* engimonSkills = activeEngimon.getLearnedSkills();
            for (int i = 0; i < activeEngimon.getCountSkill(); i++)
            {
                powerPlayer += engimonSkills[i].getBasePower()*engimonSkills[i].getMasteryLevel();
            }
            
            Skill * opponentSkills = opponent.getLearnedSkills();
            for (int i = 0; i < opponent.getCountSkill(); i++)
            {
                powerOpp += opponentSkills[i].getBasePower()*opponentSkills[i].getMasteryLevel();
            }

            powerPlayer += activeEngimon.getLevel()*maxAdvantagePlayer;
            powerOpp += opponent.getLevel()*maxAdvantageOpp;

            // compare stats
            // bisa draw
            // TODO : bikin condition engimon habis
            if (powerPlayer < powerOpp)
            {
                // TODO : bikin layar ascii 
                cout << "RIP " << activeEngimon.getName() << ", oh well it's dead" << endl;
                activeEngimon.death(); // ??? bisa delete langsung atau harus simpan temp dulu
                cout << "Choose a new Engimon!" << endl;
                callEngimon();
            }
            else if (powerPlayer > powerOpp)
            {
                try
                {
                    // TODO : bikin layar ascii
                    int expEarned = (activeEngimon.getLevel()/opponent.getLevel()) * 100;
                    cout << "Congrats! You win" << endl;
                    cout << "Your " << activeEngimon.getName() << "got " << expEarned << " exp!" << endl;
                    // TODO : remove dari list wild engimon
                    inventoryE.addItem(opponent);
                    cout << "You got " << opponent.getName() << endl;
                }
                catch(char* const err)
                {
                    cout << "Your inventory is already full" << endl;
                }

                battleEnded = true;
            }
            else
            {
                // TODO : bikin layar ascii
                cout << "Well, you are both dead :(" << endl;
                opponent.death();
                callEngimon();
                battleEnded = true;
            }
            
        } while (!battleEnded);
    }
}