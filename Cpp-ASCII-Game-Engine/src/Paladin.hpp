#ifndef PALADIN_HPP
#define PALADIN_HPP

#include "ASCII_Engine/ObjetoDeJogo.hpp"

class Paladin : public ObjetoDeJogo
{  

    public:

        Paladin(const ObjetoDeJogo &obj, int life=50, std::string weapon, int defense, int damage) 
        : ObjetoDeJogo(obj), life(life), canCure(false) 
        {
            if (weapon == "Hammer")
            {
                damage = 12;
                defense = 8;
                life += 20;
            }
            else if (weapon == "Sword")
            {
                damage = 10;
                defense = 10;
                life += 10;
            }
            else if (weapon == "Rapier")
            {
                damage = 8;
                defense == 14;
            }
        }

        virtual ~Paladin()	{}
        
        bool isAlive() const {return life != 0;}
        int getLife() const {return life;}
        int getDefense() const {return defense;}
        
        void endureAttack(int attack) {life = (life - attack >= 0) ? (life - attack):0;}

        void buffDamage() {damage += 10;}
        int attack() const {return damage;}

        int cure() {life += 10;}
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