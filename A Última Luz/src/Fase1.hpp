#ifndef FASE1_HPP
#define FASE1_HPP

#include "ASCII_Engine/Fase.hpp"
#include "Paladin.hpp"
#include "Demon.hpp"

#include <string>
#include <list>



class Fase1 : public Fase
{

    public:

        Fase1(std::string name, const Sprite &bkg) : Fase(name,bkg) {}

        virtual ~Fase1() {}
        
        
        virtual void init();
        virtual unsigned run(SpriteBuffer &screen);

        std::string getPaladinWeapon() const {return paladin_weapon;}
        void setPaladinWeapon(std::string Weapon) {paladin_weapon = Weapon;}

        int getPaladinLife() const {return paladinLife;}
        void setPaladinLife(int Life) {paladinLife = Life;}

        void setPosL(int pl) {posL = pl;}
        void setPosC(int pc) {posC = pc;}

        int getPosL() const {return posL;}
        int getPosC() const {return posC;} 
        
    private:

        std::string paladin_weapon;
        int paladinLife, posL, posC;
        Paladin *paladin; 
        Demon *demon[10];

        std::list<ObjetoDeJogo*> colisoes;
};

#endif 