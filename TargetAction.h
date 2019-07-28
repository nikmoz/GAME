#pragma once

#include "BattleScene.h"
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
private:
	std::vector<TargetSceneDef::TargetPtr>PossibleTargets_ = {};
};
