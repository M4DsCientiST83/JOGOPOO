#include "FaseFinal.hpp"
#include "Utilities.hpp"

#include <iostream>
#include <random>


void FaseFinal::init()
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
    paladin->buffDamage();


	dragon = new Dragon(ObjetoDeJogo("dragon", Sprite("rsc/Sprites/DragonBoss.img"), 25, 44));
    objs.push_back(dragon);

}

unsigned FaseFinal::run(SpriteBuffer &screen)
{

	char ent;

	int count_paladin_cure = 5, slow = 0;

	draw(screen);
	system("clear");
	show(screen);
	std::cout << "LIFE: " << paladin->getLife() 
	<< "      DEFENSE: " << paladin->getDefense() 
	<< "      ATTACK: " << paladin->getDamage()
	<< "	  BOSS HP: " << dragon->getLife()
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
			if (paladin->colideCom(*dragon)) 
			{
				dragon->endureAttack(paladin->attack());
				if (!dragon->isAlive())
				{
					dragon->desativarObj();
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
		if (slow % 3 == 0)
        {
            dragon->moveToPaladin(posL, posC);
        }

        if (slow % 20 == 0)
        { 
            ObjetoDeJogo *ball = new ObjetoDeJogo("energyball", Sprite("rsc/Sprites/EnergyBall.img"), 0, posC);
            energyball.push_back(ball);
        }

        for (auto eb : energyball) 
        {
            eb->moveDown(1);

            if (eb->colideCom(*paladin))
            {
                paladin->endureAttack(dragon->energyBall());
                eb->desativarObj();
            }
        }  

		if (paladin->colideCom(*dragon)) 
		{
			paladin->endureAttack(dragon->attack());
				
			if (!paladin->isAlive())
				return Fase::GAME_OVER;
		}


		//level uptade
        slow++;
		update();
		draw(screen);
		system("clear");
		show(screen);
		std::cout << "LIFE: " << paladin->getLife() 
		<< "      DEFENSE: " << paladin->getDefense() 
		<< "      ATTACK: " << paladin->getDamage()
		<< "	  BOSS HP: " << dragon->getLife()
		<< std::endl;
	}

	return Fase::END_GAME; 

}

void FaseFinal::draw(SpriteBase &screen, int x, int y)
{
    background->draw(screen, 0, 0);
    
    for (auto obj : objs) 
        obj->draw(screen, obj->getPosL(), obj->getPosC());

    for (auto eb : energyball)
        eb->draw(screen, eb->getPosL(), eb->getPosC());
}
