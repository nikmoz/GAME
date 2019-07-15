#pragma once
#include "Hero.h"
#include "Scene.h"
#include "Observer.h"
#include "InputHandler.h"
#include <vector>
#include <queue>
#include "TagXMLParser.h"

namespace BattleSceneDef
{
	using ActionPtr=std::shared_ptr<class Action>;
}

class BattleScene:public Scene,public Observer
{
public:
	
	BattleScene();
	~BattleScene() = default;


	void Load(const std::string& FileName) override;

	void UpdateScene() override; //Calculates scene next state
	void Update(sf::Keyboard::Key Key)override;//Reacts to key Input

	void Unload() override {};
	void Redraw() override;

	void AddCharacter(SceneDef::TargetPtr&& Character) noexcept;

	
private:
	unsigned int CurrentChar_ = 0;

	void SetupCharactersPosition() noexcept;

	std::unique_ptr<class InputHandler> TurnInputHandler_;
	
	std::vector< BattleSceneDef::ActionPtr> Actions_;
	BattleSceneDef::ActionPtr ChooseAction(sf::Keyboard::Key Key);

	bool CheckActionQueue();
	std::queue<std::pair< BattleSceneDef::ActionPtr,SceneDef::TargetPtr>> ActionQueue_;
};



