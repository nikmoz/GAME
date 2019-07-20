#pragma once
#include "Scene.h"
#include "Observer.h"
#include "InputHandler.h"
#include "Game.h"
#include "Hero.h"

class Hero;

namespace TargetSceneDef
{
	using TargetPtr = std::shared_ptr<Hero>;	
}

class TargetScene final :
	public Scene, public Observer
{
public:
	explicit TargetScene(std::vector<TargetSceneDef::TargetPtr> Targets);
	TargetScene(const TargetScene& Target);
	~TargetScene()=default;

	void Update(sf::Keyboard::Key Key) override;

	void UpdateScene() override;
	void Redraw() override;
	void Load(const std::string& FileName) override;
	void Unload() override;
private:
	

	unsigned int ChooseTarget(sf::Keyboard::Key Key);

	unsigned int CurrentTarget_ = 0;

	std::unique_ptr<class InputHandler> TargetInputHandler_;
}; 

