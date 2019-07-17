#include "TargetAction.h"

void TargetAction::Execute(Hero& Actor)
{
	ChooseTargets(Actor);
	auto TScene= std::make_shared<TargetScene>(PossibleTargets_);
	TScene->Load("");
}

void TargetAction::ChooseTargets(Hero& Actor)
{
	for (auto& Char : Game::CurrentScene->Characters)
	{
		if (Char->Side != Actor.Side)
		{
			PossibleTargets_.push_back(Char);
		}
	}
}
