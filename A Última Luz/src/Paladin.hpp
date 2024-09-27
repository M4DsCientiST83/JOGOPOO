#ifndef PALADIN_HPP
#define PALADIN_HPP

#include "ASCII_Engine/ObjetoDeJogo.hpp"

class Paladin : public ObjetoDeJogo
{  

    public:

        Paladin(const ObjetoDeJogo &obj, std::string weapon) 
        : ObjetoDeJogo(obj), life(100), canCure(false), defense(0), damage(0) 
        {
            if (weapon == "Axe")
            {
                damage = 16;
                defense = 4;
                life += 100;
            }
            else if (weapon == "Sword")
            {
                damage = 14;
                defense = 6;
                life += 50;
            }
            else if (weapon == "Rapier")
            {
                damage = 12;
                defense = 8;
                life += 10;
            }
        }

        virtual ~Paladin()	{}
        
        bool isAlive() const {return life != 0;}
        int getLife() const {return life;}
        int getDefense() const {return defense;}
        int getDamage() const {return damage;}
        
        void endureAttack(int attack) {life = (life - (attack-defense) >= 0) ? (life - (attack-defense)):0;}

        void buffDamage() {damage += 10;}
        int attack() const {return damage;}

        void cure() {if (getCanCure()) {life += 10;}}
        bool getCanCure() const {return canCure;}
        void setCanCure() {canCure = true;}
        void setLife(const int n) {life = n;}
        
    private:

        bool canCure;
        int life;
        int defense;
        int damage;
        std::string weapon;

};

#endif 