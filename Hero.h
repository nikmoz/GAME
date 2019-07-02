#pragma once

#include <string>
#include "GraphicHero.h"
#include <memory>
namespace HeroDefinitions {
	enum Side{Hero,Enemy};
};

class Hero
{
public:

	Hero(std::string Name, const std::string& TexturePath, sf::IntRect StartRect,HeroDefinitions::Side Side);
	
	std::string Name;
	HeroDefinitions::Side Side;

	std::shared_ptr<class GraphicHero> Graphic;

	~Hero() = default;
};

