#ifndef GAME_HPP
#define GAME_HPP

#include "Menu.hpp"
#include "WeaponSelect.hpp"
#include "Fase1.hpp"
#include "Fase2.hpp"
#include "FaseFinal.hpp"
#include "ASCII_Engine/Sprite.hpp"

class Game
{
    public:

        Game(){}
        ~Game(){}
        
        static void run()
        {
            SpriteBuffer buffer(110,45), buffer2(99,36), buffer3(79,40);
        
            Menu menu("Menu", Sprite ("rsc/Sprites/StartScreen.img"));
            WeaponSelect weaponselection("WeaponSelect", Sprite ("rsc/Sprites/Weapons.img"));

            
            int r1 = menu.run(buffer), r2;
            buffer.clear();


            if (r1 == Fase::LEVEL_COMPLETE)
            {
                r2 = weaponselection.run(buffer2);
                buffer2.clear();
            }
            
            if (r2 == Fase::LEVEL_COMPLETE)
            {
                std::string weapon = weaponselection.getWeapon();
                Fase1 fase1("Fase1",Sprite ("rsc/Sprites/Scene.img"), weapon);
                fase1.init();
                fase1.run(buffer3);
                buffer2.clear();
            }

            //fase1.init();
            //int ret1 = fase1.run(buffer);
            //if ( ret1 != Fase::GAME_OVER && ret1 != Fase::END_GAME){
            
                //buffer.clear();
                //faseFinal.init();
                //faseFinal.run(buffer);
            //}
            //else
                //std::cout << "GAME OVER" << std::endl;
            
            //std::cout << "Saindo..." << std::endl;

            //FaseLevel1 fase1("Fase1",Sprite("rsc/fase2.img"));
            //FaseFinal faseFinal("Fase1",Sprite("rsc/title1Gothic.img"));

            
        }

};

#endif 
