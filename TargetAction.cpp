#include "TargetAction.h"

void TargetAction::InitTargetAction(Hero& actor)
{
	if (PossibleTargets.size() == 0) {
		for (auto& Char : Game::CurrentScene->Characters)
		{
			if (Char->Side != actor.Side)
			{
				PossibleTargets.push_back(Char);
			}
		}

		TargetInputHandler->Subscribe(std::shared_ptr<class Observer>(this));
	}
};

int TargetAction::ChooseTarget(Keyboard::Keys Key)
{
	static auto i(0);

	if (Key == Keyboard::Left)
	{
		if (i > 0)
		{
			i++;
		}
		return -1;
	}

	if (Key == Keyboard::Right)
	{
		if (i < PossibleTargets.size() - 1)
		{
			i--;
		}
		return -1;
	}

	if (Key == Keyboard::Enter)
	{
		auto tmp = i;
		i = 0;
		return i;
	}
	return -1;
};

void TargetAction::execute(Hero& actor)
{
	InitTargetAction(actor);

	TargetInputHandler->HandleInput();
}

void TargetAction::update(Keyboard::Keys Key)
{
	int TargetIndex = ChooseTarget(Key);

	if (TargetIndex == -1) {
		return;
	}
	
	std::cout << "Target Name:" << PossibleTargets.at(TargetIndex)->Name << std::endl;
	
	IsResolved = true;
}