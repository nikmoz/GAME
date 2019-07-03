#include "Hero.h"


Hero::Hero(std::string Name, const std::string& TexturePath, sf::IntRect StartRect, const HeroDefinitions::Side Side,
         std::chrono::seconds AnimationDuration, int AnimationFrames, int SpriteSpacing)
:Name(std::move(Name)), Side(Side)
{
	//Graphic init
	Graphic = std::make_unique<GraphicHero>(TexturePath, StartRect,AnimationDuration,AnimationFrames,SpriteSpacing);
	//Game init
}



