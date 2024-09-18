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


	//while (true)
	//{
		//lendo entrada
		//getline(std::cin,ent);
		
		//processando entradas
		//int posL = hero->getPosL(), posC = hero->getPosC();
		
		//if (ent == "w" && hero->getPosL() > 10)
		//	hero->moveUp(3);
		//else if (ent == "s" && hero->getPosL() < screen.getAltura() - 15)
		//	hero->moveDown(3);
		//else if (ent == "a" && hero->getPosC() > 12)
		//	hero->moveLeft(3);
		//else if (ent == "d" && hero->getPosC() < screen.getLargura() - hero->getSprite()->getLargura() - 13)
		//	hero->moveRight(3);
		//else if (ent == "x") {
		//	for (int g = 0 ; g < 2 ; g++)
		//		if (hero->colideCom(*guardas[g])) {
		//			guardas[g]->sofrerAtaque(hero->atacar());
		//			if (!guardas[g]->isAlive())
		//				guardas[g]->desativarObj();
		//		}
		//}
		//else if (ent == "q")
		//	return Fase::END_GAME;
			

		//if (colideComBloco()) 
		//	hero->moveTo(posL,posC);
		
		
		//processando eventos
		//for (int g = 0 ; g < 2 ; g++)
		//		if (hero->colideCom(*guardas[g])) {
		//			hero->sofrerAtaque(guardas[g]->atacar());
					
		//			if (!hero->isAlive())
		//				return Fase::GAME_OVER;
		//			
		//			life->setText(std::string(hero->getLife()/5,'#'));
		//		}
		
		//if (hero->colideCom(*chave))
		//{
		//	chave->desativarObj();
		//	miniChave->ativarObj();
		//	hero->pegarChave();
		//}
		//else if (hero->colideCom(*tapetePorta) && hero->possuiChave())
		//{
		//	porta->openTheDoor();
		//}
		//else if (hero->colideCom(*princesa))
		//{
		//	princesa->desativarObj();
		//	hero->salvarPrincesa();
		//}
		//else if (hero->colideCom(*portao) && hero->salvouPrincesa())
		//{
		//	return Fase::LEVEL_COMPLETE;
		//}
		
		
		//padrão
		//update();
		//draw(screen);
		//system("clear");
		//show(screen);
	//}

	
	
	return Fase::END_GAME; 
}

bool Fase1::colideComBloco() const
{
	//for (auto it = colisoes.begin() ; it != colisoes.end() ; ++it)
	//	if (hero->colideCom(**it)) {
	//		return true;
	//	}
	
	//if (hero->colideCom(*porta) && !porta->isOpen() )
	//	return true;
	
	return false;
}
