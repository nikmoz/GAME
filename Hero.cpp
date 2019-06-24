#include "Hero.h"



Hero::Hero(std::string Name,std::string TexturePath, sf::IntRect StartRect, HeroeDefs::Side Side)
	:Side(std::move(Side)),Name(std::move(Name))
{
	//Graphic init
	Graphic = std::unique_ptr<GraphicHero>(new GraphicHero(TexturePath, StartRect));
	//Game init
}



