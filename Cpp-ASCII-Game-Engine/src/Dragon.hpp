#ifndef DRAGON_HPP
#define DRAGON_HPP

#include "Monster.hpp"

class Dragon : public Monster
{
    public:
        
        Dragon(const ObjetoDeJogo &obj, int lf=100, int def=10, int dmg=0) : Monster(obj, lf, def, dmg) {}

        int energyBall() const {return 30;}
};

#endif