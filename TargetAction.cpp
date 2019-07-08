#include "TargetAction.h"

void TargetAction::InitTargetAction(Hero& Actor)
{
	PossibleTargets_ = {};

	for (auto& Char : Game::CurrentScene->Characters)
	{
		if (Char->Side != Actor.Side)
		{
			PossibleTargets_.push_back(Char);
		}
	}
	if (TargetInputHandler_->Subs.empty()) {
		TargetInputHandler_->Subscribe(std::shared_ptr<class Observer>(this));
	}
};

int TargetAction::ChooseTarget(const Keyboard::Keys Key)
{
	static auto I(0U);

	if (Key == Keyboard::Left)
	{
		if (I > 0)
		{
			I++;
		}
		return -1;
	}

	if (Key == Keyboard::Right)
	{
		if (I < PossibleTargets_.size() - 1)
		{
			I--;
		}
		return -1;
	}

	if (Key == Keyboard::Enter)
	{
		const auto Tmp = I;
		I = 0;
		return Tmp;
	}
	return -1;
};

void TargetAction::Execute(Hero& Actor)
{
	IsResolved = false;

	InitTargetAction(Actor);
	TargetInputHandler_->HandleInput();
}

void TargetAction::Update(const Keyboard::Keys Key)
{
	const auto TargetIndex = ChooseTarget(Key);

	if (TargetIndex == -1) {
		return;
	}

	std::cout << "Target Name:" << PossibleTargets_.at(TargetIndex)->Name << std::endl;

	IsResolved = true;
}
