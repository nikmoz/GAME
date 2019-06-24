#pragma once

#include <string>
#include "GraphicHero.h"
#include <memory>
namespace HeroeDefs {
	enum Side{hero,enemy};
};

class Hero
{
public:

	Hero(std::string TexturePath, sf::IntRect StartRect,HeroeDefs::Side Side);
	
	HeroeDefs::Side Side;
	void TakeTurn();

	std::unique_ptr<GraphicHero> Graphic;

	~Hero() = default;
private:
};

