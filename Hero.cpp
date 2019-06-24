#include "Hero.h"



Hero::Hero(std::string TexturePath, sf::IntRect StartRect, HeroeDefs::Side Side):Side(std::move(Side))
{
	//Graphic init
	Graphic = std::unique_ptr<GraphicHero>(new GraphicHero(TexturePath, StartRect));
	//Game init

}
void Hero::TakeTurn() {

}


