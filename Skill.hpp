#ifndef SKILL_HPP
#define SKILL_HPP

#include "Element.hpp"
using namespace std;

class Skill {
protected:
    char* skillName;
    int masteryLevel;
    float basePower;
    bool compatibleElements[5];
public:
    //4 Sekawan
    Skill(); //Perlu karena ada array of string nantinya
    Skill(char* name, int ml, float bp, bool *ce); //Diasumsikan panjang array boolean ialah 5 
    Skill& operator=(const Skill& other); //Perlu cctor saat membuat salinan skill drop
    ~Skill();
    //Getters
    char* getSkillName();
    int getMasteryLevel();
    float getBasePower();
    //Methods
    void addMasteryLevel();
    float totalPower() const;
    bool learnable(const Element& e) const;
};

#endif