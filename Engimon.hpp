#ifndef __ENGIMON__HPP__
#define __ENGIMON__HPP__

#include <iostream>

using namespace std;

class Engimon {
    protected:
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
        virtual ~Engimon();
        void addExperience(int);
        void levelUp();
        virtual void death();
        virtual void showDetail();
        void breed();

};

#endif