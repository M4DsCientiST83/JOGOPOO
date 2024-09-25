#ifndef FASE2_HPP
#define FASE2_HPP

#include "ASCII_Engine/Fase.hpp"
#include "Paladin.hpp"
#include "DemonBoss.hpp"

#include <string>
#include <list>



class Fase2 : public Fase
{

    public:

        Fase2(std::string name, const Sprite &bkg) : Fase(name,bkg) {}

        virtual ~Fase2() {}
        
        
        virtual void init();
        virtual unsigned run(SpriteBuffer &screen);
        
        void setPaladinWeapon(std::string Weapon) {paladin_weapon = Weapon;}
        void setPaladinLife(int Life) {paladinLife = Life;}

        void setPosL(int pl) {posL = pl;}
        void setPosC(int pc) {posC = pc;}

        int getPosL() const {return posL;}
        int getPosC() const {return posC;} 

        bool colideComBloco() const;
        
    private:

        Paladin *paladin;
        int paladinLife, posL, posC;
        std::string paladin_weapon;
        DemonBoss *demonboss;
};

#endif 