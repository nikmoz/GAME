#include "NameAction.h"

void NameAction::Execute(Hero& Actor)
{
	std::cout << Actor.Name << std::endl;

	Actor.Graphic->LoadAnimation(AnimationState::Idle);
}
