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
            SpriteBuffer buffer(110,45), buffer2(99,36), buffer3(110,45);
        
            Menu menu("Menu", Sprite ("rsc/Sprites/StartScreen.img"));
            WeaponSelect weaponselection("WeaponSelect", Sprite ("rsc/Sprites/Weapons.img"));

            
            int r1 = menu.run(buffer), r2, r3, r4, r5;
            buffer.clear();


            if (r1 == Fase::LEVEL_COMPLETE)
            {
                r2 = weaponselection.run(buffer2);
                buffer2.clear();
            }
            
            if (r1 == Fase::LEVEL_COMPLETE && r2 != Fase::END_GAME)
            {
                Fase1 fase1("Fase1",Sprite("rsc/Sprites/Scene.img"));

                if (r2 == 1)
                    fase1.setPaladinWeapon("Axe");

                else if (r2 == 2)
                    fase1.setPaladinWeapon("Sword");

                else if (r2 == 3)
                    fase1.setPaladinWeapon("Rapier");

                fase1.init();
                r3 = fase1.run(buffer3);

                if (r3 == Fase::LEVEL_COMPLETE)
                {
                    Fase2 fase2("Fase2", Sprite("rsc/Sprites/Scene.img"));

                    fase2.setPaladinWeapon(fase1.getPaladinWeapon());
                    fase2.setPaladinLife(fase1.getPaladinLife());
                    fase2.setPosL(fase1.getPosL());
                    fase2.setPosC(fase1.getPosC());

                    fase2.init();
                    r4 = fase2.run(buffer3);

                    if (r4 == Fase::LEVEL_COMPLETE)
                    {
                        FaseFinal fasefinal("Fase3", Sprite("rsc/Sprites/Scene.img"));

                        fasefinal.setPaladinWeapon(fase2.getPaladinWeapon());
                        fasefinal.setPaladinLife(fase2.getPaladinLife());
                        fasefinal.setPosL(fase2.getPosL());
                        fasefinal.setPosC(fase2.getPosC());

                        fasefinal.init();
                        r5 = fasefinal.run(buffer3);
                    }
                }

            }
        }

};

#endif 
