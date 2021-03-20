#ifndef __ENGIMON__HPP__
#define __ENGIMON__HPP__

#include <iostream>
// #include "Skill.hpp"
// #include "Element.hpp"

using namespace std;

class Engimon {
    private:
        string name;
        // parent name, species belum tau
        // Skill* learnedSkill;
        // Element* elements;
        int level;
        int experience;
        int cumulativeExperience;
        static int maxLevel;
        static int maxCumulativeExperience;

    public:
        Engimon(string);
        ~Engimon();
        void addExperience(int);
        void levelUp();
        void death();
        void showDetail();
        void breed();

};

#endif