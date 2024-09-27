#include "Fase2.hpp"
#include "Utilities.hpp"

#include <iostream>
#include <random>


void Fase2::init()
{	

    if (paladin_weapon == "Axe")
    {
		paladin = new Paladin(ObjetoDeJogo("Paladin", Sprite("rsc/Sprites/paladinAxe.img"), posL, posC), paladin_weapon);
    	objs.push_back(paladin);
    }
	
    else if (paladin_weapon == "Sword")
    {
        paladin = new Paladin(ObjetoDeJogo("Paladin", Sprite("rsc/Sprites/paladinSword.img"), posL, posC), paladin_weapon);
        objs.push_back(paladin);
    }

    else if (paladin_weapon == "Rapier")
    {
        paladin = new Paladin(ObjetoDeJogo("Paladin", Sprite("rsc/Sprites/paladinRapier.img"), posL, posC), paladin_weapon);
        objs.push_back(paladin);
    }
	paladin->setLife(paladinLife);
	paladin->setCanCure();

	demonboss = new DemonBoss(ObjetoDeJogo("DemonBoss", Sprite("rsc/Sprites/DemonBoss.img"), 12, 7));
    objs.push_back(demonboss);

}

unsigned Fase2::run(SpriteBuffer &screen)
{

	char ent;

	int count_paladin_cure = 5, count_demonboss_cure = 5;

	draw(screen);
	system("clear");
	show(screen);
	std::cout << "LIFE: " << paladin->getLife() 
	<< "      DEFENSE: " << paladin->getDefense() 
	<< "      ATTACK: " << paladin->getDamage()
	<< "	  BOSS HP: " << demonboss->getLife()
	<<std::endl;


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
			if (paladin->colideCom(*demonboss)) 
			{
				demonboss->endureAttack(paladin->attack());
				if (!demonboss->isAlive())
				{
					demonboss->desativarObj();
					setPaladinLife(paladin->getLife());
					setPosL(posL);
					setPosC(posC);
					return Fase::LEVEL_COMPLETE;
				}
			}
		}

		else if (ent == 'l')
		{
			if (count_paladin_cure > 0)
			{
				paladin->cure();
				count_paladin_cure--;
			}
		}

		else if (ent == 'q')
			return Fase::END_GAME;
		
		//npc events

		if (demonboss->getLife() < 20 && count_demonboss_cure > 0)
		{
			demonboss->moveAway(posL, posC);
			demonboss->cure();
			count_demonboss_cure--;
		}

		else if (demonboss->getLife() >= 20 || count_demonboss_cure <= 0)
			demonboss->moveToPaladin(posL, posC);


		if (paladin->colideCom(*demonboss)) 
		{
			paladin->endureAttack(demonboss->attack());
				
			if (!paladin->isAlive())
				return Fase::GAME_OVER;
		}


		//level uptade
		update();
		draw(screen);
		system("clear");
		show(screen);
		std::cout << "LIFE: " << paladin->getLife() 
		<< "      DEFENSE: " << paladin->getDefense() 
		<< "      ATTACK: " << paladin->getDamage()
		<< "	  BOSS HP: " << demonboss->getLife()
		<< std::endl;
	}

	return Fase::END_GAME; 

}
