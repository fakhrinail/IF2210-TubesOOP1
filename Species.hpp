#ifndef __SPECIES__HPP__
#define __SPECIES__HPP__

#include <iostream>
#include "Engimon.hpp"
#include "Skill.hpp"
#include "Element.hpp"

class Firemon : public Engimon {
    public:
        Firemon(string, string, string);
        ~Firemon();
        void interact();
};

class Watermon : public Engimon {
    public:
        Watermon(string, string, string);
        ~Watermon();
        void interact();
};

class Electricmon : public Engimon {
    public:
        Electricmon(string, string, string);
        ~Electricmon();
        void interact();
};
class Groundmon : public Engimon {
    public:
        Groundmon(string, string, string);
        ~Groundmon();
        void interact();
};

class Icemon : public Engimon {
    public:
        Icemon(string, string, string);
        ~Icemon();
        void interact();
};

#endif