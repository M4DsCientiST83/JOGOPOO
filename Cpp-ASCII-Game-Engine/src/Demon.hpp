#ifndef DEMON_HPP
#define DEMON_HPP

#include "Monster.hpp"

class Demon : public Monster
{
    public:

        Demon(const ObjetoDeJogo &obj, int lf=10, int def=2, int dmg=10) : Monster(obj, lf, def, dmg) {}
};

#endif