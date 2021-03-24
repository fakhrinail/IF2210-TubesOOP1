#ifndef __SPECIES__HPP__
#define __SPECIES__HPP__

#include <iostream>
#include "Engimon.hpp"
// #include "Skill.hpp"
// #include "Element.hpp"

class Firemon : public Engimon {
    protected:
        // Skill* learnedSkill;
        // Element* elements;
        int countSkill;
        int countElement;
    public:
        Firemon(string, string, string);
        ~Firemon();
        void death();
        void showDetail();
};

class Watermon : public Engimon {
    protected:
        // Skill* learnedSkill;
        // Element* elements;
        int countSkill;
        int countElement;
    public:
        Watermon(string, string, string);
        ~Watermon();
        void death();
        void showDetail();
};

class Electricmon : public Engimon {
    protected:
        // Skill* learnedSkill;
        // Element* elements;
        int countSkill;
        int countElement;
    public:
        Electricmon(string, string, string);
        ~Electricmon();
        void death();
        void showDetail();
};

class Groundmon : public Engimon {
    protected:
        // Skill* learnedSkill;
        // Element* elements;
        int countSkill;
        int countElement;
    public:
        Groundmon(string, string, string);
        ~Groundmon();
        void death();
        void showDetail();
};

class Icemon : public Engimon {
    protected:
        // Skill* learnedSkill;
        // Element* elements;
        int countSkill;
        int countElement;
    public:
        Icemon(string, string, string);
        ~Icemon();
        void death();
        void showDetail();
};

#endif