#include "TargetAction.h"
#include <iostream>

void TargetAction::Execute(Hero& Actor)
{
	ChooseTargets(Actor);
	auto TScene= std::make_shared<TargetScene>(PossibleTargets_,std::make_shared<TargetAction>(*this));
	TScene->Load("");
}

void TargetAction::ChooseTargets(Hero& Actor)
{
	for (auto& Char : Game::SceneStack.front()->Characters)
	{
		if (Char->Side != Actor.Side)
		{
			PossibleTargets_.push_back(Char);
		}
	}
}

inline void TargetAction::Resolve(const std::shared_ptr<Hero>& Targets)
{
	std::cout << "Target Name:" << Targets->Name << std::endl;
}
