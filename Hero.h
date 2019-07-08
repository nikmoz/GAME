#pragma once

#include <string>
#include <fstream>
#include <memory>
#include "GraphicHero.h"
#include "TagXMLParser.h"

namespace HeroDefinitions {
	enum Side{Hero,Enemy};
};

class Hero
{
public:

	explicit Hero(const std::string& FileName);
	
	std::string Name;
	HeroDefinitions::Side Side;

	std::shared_ptr<class GraphicHero> Graphic;

	~Hero() = default;
};

