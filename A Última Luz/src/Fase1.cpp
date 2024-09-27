#include "Fase1.hpp"
#include "Utilities.hpp"

#include <iostream>
#include <random>


void Fase1::init()
{	

    if (paladin_weapon == "Axe")
    {
		paladin = new Paladin(ObjetoDeJogo("Paladin", Sprite("rsc/Sprites/paladinAxe.img"), 30, 36), paladin_weapon);
    	objs.push_back(paladin);
    }
	
    else if (paladin_weapon == "Sword")
    {
        paladin = new Paladin(ObjetoDeJogo("Paladin", Sprite("rsc/Sprites/paladinSword.img"), 30, 36), paladin_weapon);
        objs.push_back(paladin);
    }

    else if (paladin_weapon == "Rapier")
    {
        paladin = new Paladin(ObjetoDeJogo("Paladin", Sprite("rsc/Sprites/paladinRapier.img"), 30, 36), paladin_weapon);
        objs.push_back(paladin);
    }
	
	demon[0] = new Demon(ObjetoDeJogo("Demon", Sprite("rsc/Sprites/DemonMelee.img"), 22, 70));
    objs.push_back(demon[0]);

}

unsigned Fase1::run(SpriteBuffer &screen)
{

	char ent;

	draw(screen);
	system("clear");
	show(screen);
	std::cout << "LIFE: " << paladin->getLife() 
	<< "      DEFENSE: " << paladin->getDefense() 
	<< "      ATTACK: " << paladin->getDamage()
	<<std::endl;

	int killed = 0, n_demon = 1;


	while (true)
	{
		ent = captureKey();

		//keyboard actions
		int posL = paladin->getPosL(), posC = paladin->getPosC();
		
		if (ent == 'w' && paladin->getPosL() > 1)
			paladin->moveUp(1);

		else if (ent == 'a' && paladin->getPosC() > 1)
			paladin->moveLeft(1);

		else if (ent == 's' && paladin->getPosL() < 41)
			paladin->moveDown(1);

		
		else if (ent == 'd' && paladin->getPosC() < 99)
			paladin->moveRight(1);
			
		else if (ent == 'p') 
		{
			for (int d = 0 ; d < n_demon ; d++)
				if (paladin->colideComBordas(*demon[d])) 
				{
					demon[d]->endureAttack(paladin->attack());
					if (!demon[d]->isAlive())
					{
						killed++;
						demon[d]->desativarObj();
					}
				}
		}

		else if (ent == 'q')
			return Fase::END_GAME;

		
		//npc events
		for (int d = 0; d < n_demon; d++)
		{
			if (demon[d] != nullptr)
				demon[d]->moveToPaladin(posL, posC);
		}


		for (int d = 0 ; d < n_demon ; d++)
			if (paladin->colideComBordas(*demon[d])) 
			{
				paladin->endureAttack(demon[d]->attack());
					
				if (!paladin->isAlive())
					return Fase::GAME_OVER;
			}
		

		if (killed == 10)
		{
			setPaladinLife(paladin->getLife());
			setPosL(posL);
			setPosC(posC);
			return Fase::LEVEL_COMPLETE;
		}


		std::random_device rd; 
		std::mt19937 gen(rd()); 
		std::uniform_int_distribution<> distrib(1, 20);
		std::uniform_int_distribution<> distribL(1, 31);
		std::uniform_int_distribution<> distribC(1, 105);

		int number = distrib(gen), randL = distribL(gen), randC = distribC(gen);

		if (number == 1 && n_demon < 10)
		{
			demon[n_demon] = new Demon(ObjetoDeJogo("Demon", Sprite("rsc/Sprites/DemonMelee.img"), randL, randC));
			objs.push_back(demon[n_demon]);
			n_demon++;
		}


		//level uptade
		update();
		draw(screen);
		system("clear");
		show(screen);
		std::cout << "LIFE: " << paladin->getLife() 
		<< "      DEFENSE: " << paladin->getDefense() 
		<< "      ATTACK: " << paladin->getDamage()
		<< std::endl;
	}

	return Fase::END_GAME; 

}
