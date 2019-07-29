#pragma once
#include "Hero.h"
#include "Action.h"
#include "Game.h"
#include <vector>
#include "TargetScene.h"

class TargetAction : public Action
{
public:
	~TargetAction()=default;
	virtual void Execute(Hero& Actor) override;
	virtual void ChooseTargets(Hero& Actor);
	virtual void Resolve(const std::shared_ptr<Hero>& Targets);
private:
	std::vector<std::shared_ptr<Hero>> PossibleTargets_ = {};
};
