#ifndef __ENGIMON__HPP__
#define __ENGIMON__HPP__

#include <iostream>
#include "Skill.hpp"
#include "Element.hpp"

using namespace std;

class Engimon {
    protected:
        string name;
        string species;
        string parentName;
        string parentSpecies;
        int countElement;
        int countSkill;
        Element *elements;
        Skill *learnedSkills;
        int level;
        int experience;
        int cumulativeExperience;
        static int maxLevel;
        static int maxCumulativeExperience;

    public:
        // 4 sekawan
        Engimon(string, string, string, string);
        Engimon(const Engimon&);
        Engimon& operator=(const Engimon&);
        virtual ~Engimon();
        // getter setter
        string getName() const;
        int getCountElement();
        int getCountSkill();
        // method lain
        virtual void interact() = 0;
        void addExperience(int);
        void levelUp();
        void death();
        void showDetail();
        void learnSkill(Skill&);
        Engimon& operator+(Engimon&);
        bool operator==(const Engimon&) const;
        friend ostream& operator<<(ostream&, const Engimon&);
};

#endif