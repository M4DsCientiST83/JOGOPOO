#ifndef DEMONBOSS_HPP
#define DEMONBOSS_HPP

#include "Monster.hpp"

class DemonBoss : public Monster
{
    public:

        DemonBoss(const ObjetoDeJogo &obj, int lf=50, int def=5, int dmg=15) : Monster(obj, lf, def, dmg) {}

        void buffAttack() {setDamage(20);}
        void cure() {setLife(getLife() + 5);}
};

#endif