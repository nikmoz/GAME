#pragma once
#include "Action.h"
#include "InputHandler.h"
#include "Observer.h"
#include <vector>

using HeroPtr = std::shared_ptr<Hero>;

class TargetAction :public Action, public Observer
{
public:
	~TargetAction() = default;

	void InitTargetAction(Hero& actor);
	
	void execute(Hero& actor) override;
	void update(Keyboard::Keys Key) override;
private:
	std::vector<HeroPtr> PossibleTargets;
	std::unique_ptr<InputHandler> TargetInputHandler;
};

