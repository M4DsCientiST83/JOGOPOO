#include "GameOver.hpp"
#include "Utilities.hpp"

void GameOver::init()
{
	loser = true;
}

unsigned GameOver::run(SpriteBuffer &screen)
{

	draw(screen);
	system("clear");
	show(screen);

	
	return Fase::END_GAME; 
}
