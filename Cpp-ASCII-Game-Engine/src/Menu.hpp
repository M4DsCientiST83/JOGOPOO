#ifndef MENU_HPP
#define MENU_HPP

#include "ASCII_Engine/Fase.hpp"

class Menu : public Fase
{
    public:

        Menu(std::string name, const Sprite &sscreen) : Fase(name,sscreen) {}

        virtual ~Menu() {}
        
        virtual void init();
        virtual unsigned run(SpriteBuffer &screen);

    private:

        char start_button;

};

#endif 