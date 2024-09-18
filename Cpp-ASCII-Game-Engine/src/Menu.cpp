#include "Menu.hpp"
#include "Utilities.hpp"

void Menu::init()
{
	start_button = 'a';
}

unsigned Menu::run(SpriteBuffer &screen)
{
	char ent;

	//Print StartScreen.
	draw(screen);
	system("clear");
	show(screen);


	while (true)
	{
		//Reading Entrance.
		ent = captureKey();

		if (ent == 'q')
			return Fase::END_GAME;
		
		else if (ent == 'p')
			return Fase::LEVEL_COMPLETE;
		
	}
	
	return Fase::END_GAME; 
}