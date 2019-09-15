#include "TargetScene.h"
#include <iostream>
#include <utility>
#include "Game.h"


TargetScene::TargetScene(std::vector<TargetSceneDef::TargetPtr> Targets,std::shared_ptr<class TargetAction> Action, Hero& Actor): Actor_(Actor), Action_(std::move(Action))
{
	Characters=std::move(Targets);
}

TargetScene::TargetScene(const TargetScene& Target)
	: Scene(Target),Actor_(Target.Actor_)
{
	Characters=Target.Characters;

	Action_=Target.Action_;

	CurrentTarget_=Target.CurrentTarget_;
}

void TargetScene::UpdateScene(const sf::Keyboard::Key Key)
{
	const auto TargetIndex = ChooseTarget(Key);

	if (!TargetIndex.has_value()) {
		return;
	}

	Action_->Resolve(Characters.at(TargetIndex.value()),Actor_);

	Unload();
}

void TargetScene::Redraw(){}

void TargetScene::Load(std::string_view FileName)
{
	Game::SceneDeque.push_front(std::make_shared<TargetScene>(*this));
}

void TargetScene::Unload()
{
	Game::SceneDeque.pop_front();
}

std::optional<int> TargetScene::ChooseTarget(const sf::Keyboard::Key Key)
{

	if (Key == sf::Keyboard::Left)
	{
		if (CurrentTarget_ > 0)
		{
			CurrentTarget_--;
		}
		return std::nullopt;
	}

	if (Key == sf::Keyboard::Right)
	{
		if (static_cast<unsigned int>(CurrentTarget_) < Characters.size() - 1)
		{
			CurrentTarget_++;
		}
		return std::nullopt;
	}

	if (Key == sf::Keyboard::Enter)
	{
		return CurrentTarget_;
	}
	return std::nullopt;
}
