#ifndef MONSTER_HPP
#define MONSTER_HPP

#include "ASCII_Engine/ObjetoDeJogo.hpp"

class Monster : public ObjetoDeJogo
{

    public:

        Monster(const ObjetoDeJogo &obj, int lf, int def, int dmg) : ObjetoDeJogo(obj), life(lf), defense(def), damage(dmg) {}
        
        virtual ~Monster(){}
        
        bool isAlive() const {return life != 0;}
        
        void endureAttack(int attack) 
        {
            life = (life - attack >= 0) ? (life - attack):0;
        }
        
        int attack() 
        { 
            return damage;
        }

        void setLife(int lf) {life = lf;}
        int getLife() const {return life;}

        void setDefense(int def) {defense = def;}
        int getDefense() const {return defense;}

        void setDamage(int dmg) {damage = dmg;}
        int getDamage() const {return damage;}

    private:

        int life;
        int defense;
        int damage;

};

#endif 