#pragma once

#include <string>
#include <memory>
#include "GraphicHero.h"
#include "TagXMLParser.h"
#include "Action.h"


class Action;

namespace HeroDef {
	using ActionPtr=std::shared_ptr<Action>;
	enum Side{Hero,Enemy};
};

class Hero
{
public:
	explicit Hero(std::string_view FileName);

	std::string Name;
	HeroDef::Side Side;

	std::shared_ptr<class GraphicHero> Graphic;

	~Hero() = default;


	unsigned int CurrentAction= 0;
	std::vector<HeroDef::ActionPtr> Actions;
};

