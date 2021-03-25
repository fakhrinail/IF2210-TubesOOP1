#ifndef SKILL_HPP
#define SKILL_HPP

#include "Element.hpp"
using namespace std;

class Skill {
protected:
    string skillName;
    int masteryLevel;
    float basePower;
    int compatibleElements; //bernilai 0-31, tiap digit dalam representasi binernya menandakan kompatibilitas untuk setiap elemen
public:
    //4 Sekawan
    Skill(); //Perlu karena ada array of string nantinya
    Skill(string name, int ml, float bp, int ce); //Diasumsikan panjang array boolean ialah 5 
    Skill& operator=(const Skill& other); //Perlu cctor saat membuat salinan skill drop
    ~Skill();
    //Getters
    string getSkillName() const;
    int getMasteryLevel();
    float getBasePower();
    //Methods
    void addMasteryLevel();
    float totalPower() const;
    bool learnable(const Element& e) const;
    bool operator==(const Skill& other) const;
    void showDetail() const;
    friend ostream& operator<<(ostream& os, const Skill& s);
};

#endif