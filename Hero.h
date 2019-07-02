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

	Hero(std::string Name,std::string TexturePath, sf::IntRect StartRect,HeroeDefs::Side Side);
	
	std::string Name;
	HeroeDefs::Side Side;

	std::shared_ptr<class GraphicHero> Graphic;

	~Hero() = default;
};

