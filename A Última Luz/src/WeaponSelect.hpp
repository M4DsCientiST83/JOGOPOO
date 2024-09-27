#ifndef WEAPONSELECT_HPP
#define WEAPONSELECT_HPP

#include "ASCII_Engine/Fase.hpp"

class WeaponSelect : public Fase
{
    public:

        WeaponSelect(std::string name, const Sprite &bkg) : Fase(name,bkg), selected(false) {}

        virtual ~WeaponSelect() {}
        
        virtual void init();
        virtual unsigned run(SpriteBuffer &screen);


    private:
    
        bool selected;

};

#endif 