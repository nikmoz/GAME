#pragma once

#include "Action.h"
#include "Game.h"
#include "InputHandler.h"
#include "Observer.h"
#include <vector>
#include <iostream>

namespace TargetDef
{
	using TargetPtr = std::shared_ptr<Hero>;	
}


class TargetAction : public Action, public Observer
{
public:

	~TargetAction() = default;

	void Execute(Hero& Actor) override;
	void Update(sf::Keyboard::Key Key) override;
private:

	virtual void InitTargetAction(Hero& Actor);
	virtual int ChooseTarget(sf::Keyboard::Key Key);

	std::vector<TargetDef::TargetPtr> PossibleTargets_ = {};

	std::unique_ptr<InputHandler> TargetInputHandler_ = std::make_unique<InputHandler>();
};
