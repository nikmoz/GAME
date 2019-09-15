#include "TargetAction.h"
#include <iostream>

void TargetAction::Execute(Hero& Actor)
{
	ChooseTargets(Actor);
	auto TScene= std::make_shared<TargetScene>(PossibleTargets_,std::make_shared<TargetAction>(*this),Actor);
	TScene->Load("");
}

void TargetAction::ChooseTargets(Hero& Actor)
{
	for (auto& Char : Game::SceneDeque.front()->Characters)
	{
		if (Char->Side != Actor.Side)
		{
			PossibleTargets_.push_back(Char);
		}
	}
}

inline void TargetAction::Resolve(const std::shared_ptr<Hero>& Targets, Hero& Actor)
{
	std::cout <<Actor.Name<< " hits "<< Targets->Name << std::endl;

	Actor.Graphic->LoadAnimation(AnimationState::Idle);
}
