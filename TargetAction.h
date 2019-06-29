#pragma once
#include "Action.h"
#include "InputHandler.h"
#include "Observer.h"
#include <vector>

using HeroPtr = std::shared_ptr<Hero>;

class TargetAction :public Action, public Observer
{
public:

	~TargetAction()=default;

	void execute(Hero& actor) override;
	virtual void update(Keyboard::Keys Key) override;
private:

	virtual void InitTargetAction(Hero& actor);
	virtual int ChooseTarget(Keyboard::Keys Key);

	std::vector<HeroPtr> PossibleTargets;

	std::unique_ptr<InputHandler> TargetInputHandler= std::make_unique<InputHandler>();
};

