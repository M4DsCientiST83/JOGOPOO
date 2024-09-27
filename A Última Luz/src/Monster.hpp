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
            life = (life - (attack-defense) >= 0) ? (life - (attack-defense)):0;
        }
        
        int attack() 
        { 
            return damage;
        }

        void moveToPaladin(int pL, int pC) 
        {
            int l_diff, c_diff;

            if (getPosL() >= pL)
                l_diff = getPosL() - pL;
            
            else 
                l_diff = pL - getPosL();

            if (getPosC() >= pC)
                c_diff = getPosC() - pC;

            else 
                c_diff = pC - getPosC();


            if (l_diff >= c_diff)
            {
                if (getPosL() < pL)
                    moveDown(1);
                
                else if (getPosL() > pL)
                    moveUp(1);
            }
            
            else 
            {
                if (getPosC() < pC)
                    moveRight(1);
                
                else if (getPosC() > pC)
                    moveLeft(1);
            }
                
        }

        void moveAway(int pL, int pC) 
        {
            int l_diff, c_diff;

            if (getPosL() >= pL)
                l_diff = getPosL() - pL;
            
            else 
                l_diff = pL - getPosL();

            if (getPosC() >= pC)
                c_diff = getPosC() - pC;

            else 
                c_diff = pC - getPosC();


            if (l_diff >= c_diff)
            {
                if (getPosL() < pL)
                    moveUp(2);
                
                else if (getPosL() > pL)
                    moveDown(2);
            }
            
            else 
            {
                if (getPosC() < pC)
                    moveLeft(2);
                
                else if (getPosC() > pC)
                    moveRight(2);
            }
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