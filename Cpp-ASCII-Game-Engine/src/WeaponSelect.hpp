#ifndef WEAPONSELECT_HPP
#define WEAPONSELECT_HPP

#include "ASCII_Engine/Fase.hpp"

class WeaponSelect : public Fase
{
    public:

        WeaponSelect(std::string name, const Sprite &bkg) : Fase(name,bkg), weapon_selected(""), selected(false) {}

        virtual ~WeaponSelect() {}
        
        virtual void init();
        virtual unsigned run(SpriteBuffer &screen);

        std::string getWeapon() const {return weapon_selected;}

    private:
    
        std::string weapon_selected;
        bool selected;

};

#endif 