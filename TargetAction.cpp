#include "TargetAction.h"

void TargetAction::Execute(Hero& Actor)
{
	ChooseTargets(Actor);
	static auto TScene= std::make_shared<TargetScene>(PossibleTargets_);

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
