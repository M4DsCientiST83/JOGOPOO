#include "WeaponSelect.hpp"
#include "Utilities.hpp"

void WeaponSelect::init()
{
    weapon_selected = "none";
}

unsigned WeaponSelect::run(SpriteBuffer &screen)
{
	char ent;
	
	//padrão
	draw(screen);
	system("clear");
	show(screen);
	
	while (true)
	{
		//lendo entrada
        ent = captureKey();

		if (ent == 'a')
        {
            weapon_selected == "Axe";
            return Fase::LEVEL_COMPLETE;
        }
            
		else if (ent == 's')
        {
            weapon_selected == "Sword";
            return Fase::LEVEL_COMPLETE;
        }
            
        else if (ent == 'r')
        {
            weapon_selected == "Rapier";
            return Fase::LEVEL_COMPLETE;
        }
	}
	
	return Fase::END_GAME; 
}