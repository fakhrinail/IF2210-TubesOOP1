#ifndef __SPECIES__HPP__
#define __SPECIES__HPP__

#include <iostream>
#include "Engimon.hpp"
#include "Skill.hpp"
#include "Element.hpp"

// element fire
class Firemon : public Engimon {
    public:
        Firemon(string, string, string, string, string, int);
        ~Firemon();
        void interact();
};

// element water
class Watermon : public Engimon {
    public:
        Watermon(string, string, string, string, string, int);
        ~Watermon();
        void interact();
};

// element electric
class Electricmon : public Engimon {
    public:
        Electricmon(string, string, string, string, string, int);
        ~Electricmon();
        void interact();
};

// element ground
class Groundmon : public Engimon {
    public:
        Groundmon(string, string, string, string, string, int);
        ~Groundmon();
        void interact();
};

// element ice
class Icemon : public Engimon {
    public:
        Icemon(string, string, string, string, string, int);
        ~Icemon();
        void interact();
};

// element fire, electric
class Itachimon : public Engimon {
    public:
        Itachimon(string, string, string, string, string, int);
        ~Itachimon();
        void interact();
};

// element water, ice
class Telermon : public Engimon {
    public:
        Telermon(string, string, string, string, string, int);
        ~Telermon();
        void interact();
};

// element water, ground
class Narutomon : public Engimon {
    public:
        Narutomon(string, string, string, string, string, int);
        ~Narutomon();
        void interact();
};

#endif