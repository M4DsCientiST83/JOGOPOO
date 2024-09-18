#include "Fase1.hpp"
#include "Utilities.hpp"

#include <iostream>


void Fase1::init()
{	
	//Objetos de jogo
    demon[0] = new Demon(ObjetoDeJogo("Demon", Sprite("rsc/Sprites/DemonMelee.img"), 73, 22));
    objs.push_back(demon[0]);

    if (paladin_weapon == "Axe")
    {
        paladin = new Paladin(ObjetoDeJogo("Paladin", Sprite("rsc/Sprites/HeroAxe.img"), 36, 22), paladin_weapon);
        objs.push_back(paladin);
    }
	
    else if (paladin_weapon == "Sword")
    {
        paladin = new Paladin(ObjetoDeJogo("Paladin", Sprite("rsc/Sprites/HeroSword.img"), 36, 22), paladin_weapon);
        objs.push_back(paladin);
    }

    else if (paladin_weapon == "Rapier")
    {
        paladin = new Paladin(ObjetoDeJogo("Paladin", Sprite("rsc/Sprites/HeroRapier.img"), 36, 22), paladin_weapon);
        objs.push_back(paladin);
    }

}

unsigned Fase1::run(SpriteBuffer &screen)
{
	char ent;

	draw(screen);
	system("clear");
	show(screen);

    ent = captureKey();
	
    if (ent == 'q')
        return Fase::END_GAME;




	
	
	return Fase::END_GAME; 
}

bool Fase1::colideComBloco() const
{
	
	return false;
}
