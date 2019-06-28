#include "TargetAction.h"
void TargetAction::InitTargetAction(Hero& actor)
{
	for (auto& Char : Game::CurrentScene->Characters)
	{
		if (Char->Side != actor.Side)
		{
			PossibleTargets.push_back(Char);
		}
	}

	TargetInputHandler->Subscribe(std::shared_ptr<class Observer>(this));

	TargetInputHandler->HandleInput();
};

void TargetAction::execute(Hero& actor)
{
	InitTargetAction(actor);

	
}

void TargetAction::update(Keyboard::Keys Key)
{
	static auto i(0);

	if (Key == Keyboard::Left)
	{
		if (i > 0)
		{
			i++;
		}
	}

	if (Key == Keyboard::Right)
	{
		if (i < PossibleTargets.size() - 1)
		{
			i--;
		}
	}

	if (Key == Keyboard::Enter)
	{
		auto tmp = i;
		i = 0;
		//return;
	}

}