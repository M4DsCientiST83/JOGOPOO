#ifndef FASE2_HPP
#define FASE2_HPP

#include "ASCII_Engine/Fase.hpp"
#include <string>
#include <list>



class Fase2 : public Fase
{

    public:

        Fase2(std::string name, const Sprite &bkg) : Fase(name,bkg) {}
        Fase2(std::string name, const SpriteAnimado &bkg) : Fase(name,bkg) {}
        virtual ~Fase2() {}
        
        
        virtual void init();
        virtual unsigned run(SpriteBuffer &screen);
        
        bool colideComBloco() const;
        
    private:

        //Enemy *guardas[2];
        //Hero *hero;
        //Door *porta;
        //ObjetoDeJogo *tapetePorta;
        //ObjetoDeJogo *portao;
        //ObjetoDeJogo *chave;
        //ObjetoDeJogo *miniChave;
        //ObjetoDeJogo *princesa;
        
        //TextSprite *life;
        
        //std::list<ObjetoDeJogo*> colisoes;
};

#endif 