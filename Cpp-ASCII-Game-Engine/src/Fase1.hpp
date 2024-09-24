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

        bool colideComBloco() const;
        
    private:

        std::string paladin_weapon;
        Paladin *paladin; 
        Demon *demon[10];

        std::list<ObjetoDeJogo*> colisoes;
};

#endif 