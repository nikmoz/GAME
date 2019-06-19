#pragma once
#include <vector>
#include <memory>
#include "Hero.h"
class Game
{
public:
	static std::vector<std::shared_ptr<Hero>> Characters;
	static void AddCharacter(std::shared_ptr<Hero> Character);
};

