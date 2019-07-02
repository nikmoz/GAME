#include "SideAction.h"
void SideAction::Execute(Hero& Actor) {
	if (Actor.Side == HeroDefinitions::Hero)
	{
		std::cout << "Hero" << std::endl;
	}
	else if (Actor.Side == HeroDefinitions::Enemy)
	{
		std::cout << "Enemy" << std::endl;
	}
	IsResolved = true;
}


