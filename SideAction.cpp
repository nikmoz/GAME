#include "SideAction.h"
void SideAction::Execute(Hero& Actor) {
	if (Actor.Side == HeroDef::Hero)
	{
		std::cout << "Hero" << std::endl;
	}
	else if (Actor.Side == HeroDef::Enemy)
	{
		std::cout << "Enemy" << std::endl;
	}
}