#include "TargetScene.h"
#include <iostream>
#include <utility>
#include "Game.h"

TargetScene::TargetScene(std::vector<TargetSceneDef::TargetPtr> Targets)
{
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

	PreviousScene_=Target.PreviousScene_;

	CurrentTarget_=Target.CurrentTarget_;
}


void TargetScene::Update(const sf::Keyboard::Key Key)
{
	const auto TargetIndex = ChooseTarget(Key);

	if (TargetIndex == -1) {
		return;
	}

	std::cout << "Target Name:" << Characters.at(TargetIndex)->Name << std::endl;
	Unload();

}

void TargetScene::UpdateScene()
{
	TargetInputHandler_->HandleInput();
}

void TargetScene::Redraw()
{
	PreviousScene_->Redraw();
}

void TargetScene::Load(const std::string& FileName)
{
	PreviousScene_=Game::CurrentScene;
	Game::CurrentScene=std::make_shared<TargetScene>(*this);
}

void TargetScene::Unload()
{

	Game::CurrentScene=PreviousScene_;

}

int TargetScene::ChooseTarget(const sf::Keyboard::Key Key)
{

	if (Key == sf::Keyboard::Left)
	{
		if (CurrentTarget_ > 0)
		{
			CurrentTarget_--;
		}
		return -1;
	}

	if (Key == sf::Keyboard::Right)
	{
		if (static_cast<unsigned int>(CurrentTarget_) < Characters.size() - 1)
		{
			CurrentTarget_++;
		}
		return -1;
	}

	if (Key == sf::Keyboard::Enter)
	{
		return CurrentTarget_;
	}
	return -1;
}
