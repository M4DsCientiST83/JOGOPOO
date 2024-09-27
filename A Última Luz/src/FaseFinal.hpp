#ifndef FASEFINAL_HPP
#define FASEFINAL_HPP

#include "ASCII_Engine/Fase.hpp"
#include "Paladin.hpp"
#include "Dragon.hpp"

#include <string>
#include <list>


class FaseFinal : public Fase
{

    public:

        FaseFinal(std::string name, const Sprite &bkg) : Fase(name,bkg) {}

        virtual ~FaseFinal() {}
        
        virtual void init();
        virtual unsigned run(SpriteBuffer &screen);
        
        void setPaladinWeapon(std::string Weapon) {paladin_weapon = Weapon;}
        void setPaladinLife(int Life) {paladinLife = Life;}

        void setPosL(int pl) {posL = pl;}
        void setPosC(int pc) {posC = pc;}

		virtual void draw(SpriteBase &screen, int x = 0, int y = 0) override;
        
    private:

        Paladin *paladin;
        int paladinLife, posL, posC;
        std::string paladin_weapon;
        
		Dragon *dragon;

		std::list<ObjetoDeJogo *> energyball;
};

#endif 