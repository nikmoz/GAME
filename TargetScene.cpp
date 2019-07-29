#include "TargetScene.h"
#include <iostream>
#include <utility>
#include "Game.h"


TargetScene::TargetScene(std::vector<TargetSceneDef::TargetPtr> Targets,std::shared_ptr<class TargetAction> Action): Action_(std::move(Action)) {
	Characters=std::move(Targets);
	TargetInputHandler_ = std::make_unique<InputHandler>();
	TargetInputHandler_->Subscribe(this);
}

TargetScene::TargetScene(const TargetScene& Target)
	: Scene(Target)
{
	Characters=Target.Characters;

	TargetInputHandler_ = std::make_unique<InputHandler>();
	TargetInputHandler_->Subscribe(this);

	Action_=Target.Action_;
	CurrentTarget_=Target.CurrentTarget_;
}


void TargetScene::Update(const sf::Keyboard::Key Key)
{
	const auto TargetIndex = ChooseTarget(Key);

	if (!TargetIndex.has_value()) {
		return;
	}

	Action_->Resolve(Characters.at(TargetIndex.value()));
	
	Unload();

}

void TargetScene::UpdateScene()
{
	TargetInputHandler_->HandleInput();
}

void TargetScene::Redraw(){}

void TargetScene::Load(const std::string& FileName)
{
	Game::SceneStack.push_front(std::make_shared<TargetScene>(*this));
}

void TargetScene::Unload()
{
	Game::SceneStack.pop_front();
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
