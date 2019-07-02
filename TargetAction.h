#pragma once
#include "Action.h"
#include "Game.h"
#include "InputHandler.h"
#include "Observer.h"
#include <vector>
#include <iostream>

using TargetPtr = std::shared_ptr<Hero>;

class TargetAction : public Action, public Observer
{
public:

	~TargetAction() = default;

	void Execute(Hero& Actor) override;
	void Update(Keyboard::Keys Key) override;
private:

	virtual void InitTargetAction(Hero& Actor);
	virtual int ChooseTarget(Keyboard::Keys Key);

	std::vector<TargetPtr> PossibleTargets_ = {};

	std::unique_ptr<InputHandler> TargetInputHandler_ = std::make_unique<InputHandler>();
};
