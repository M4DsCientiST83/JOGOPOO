#include "WeaponSelect.hpp"
#include "Utilities.hpp"

void WeaponSelect::init()
{
    selected = true;
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
            return 1;
        }
            
		else if (ent == 's')
        {
            return 2;
        }
            
        else if (ent == 'r')
        {
            return 3;
        }
	}
	
	return Fase::END_GAME; 
}