#ifndef PALADIN_HPP
#define PALADIN_HPP

#include "ASCII_Engine/ObjetoDeJogo.hpp"

class Paladin : public ObjetoDeJogo
{  

    public:

        Paladin(const ObjetoDeJogo &obj, std::string weapon) 
        : ObjetoDeJogo(obj), life(50), canCure(false), defense(0), damage(0) 
        {
            if (weapon == "Axe")
            {
                damage = 10;
                defense = 3;
                life += 15;
            }
            else if (weapon == "Sword")
            {
                damage = 9;
                defense = 4;
                life += 10;
            }
            else if (weapon == "Rapier")
            {
                damage = 8;
                defense == 6;
            }
        }

        virtual ~Paladin()	{}
        
        bool isAlive() const {return life != 0;}
        int getLife() const {return life;}
        int getDefense() const {return defense;}
        
        void endureAttack(int attack) {life = (life - attack >= 0) ? (life - attack):0;}

        void buffDamage() {damage += 10;}
        int attack() const {return damage;}

        void cure() {life += 10;}
        bool getCanCure() const {return canCure;}
        void setCanCure() {canCure = true;}
        
    private:

        bool canCure;
        int life;
        int defense;
        int damage;
        std::string weapon;

};

#endif 