#ifndef GAMEOVER_HPP
#define GAMEOVER_HPP

#include "ASCII_Engine/Fase.hpp"

class GameOver : public Fase
{
    public:

        GameOver(std::string name, const Sprite &sscreen) : Fase(name,sscreen) {}

        virtual ~GameOver() {}
        
        virtual void init();
        virtual unsigned run(SpriteBuffer &screen);

    private:

        bool loser;

};

#endif 