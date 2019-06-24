#include "SideAction.h"
void SideAction::execute(Hero& actor) {
	if (actor.Side == HeroeDefs::hero)
	{
		std::cout << "Hero" << std::endl;
	}
	else if (actor.Side == HeroeDefs::enemy)
	{
		std::cout << "Enemy" << std::endl;
	}
}


