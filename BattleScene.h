#pragma once
#include "Hero.h"
#include "Scene.h"
#include "Observer.h"
#include "InputHandler.h"
#include <vector>
#include <fstream>
#include "TagXmlParser.h"

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

	void AddCharacter(TargetPtr&& Character) noexcept;

	
private:
	unsigned int CurrentChar_ = 0;

	void SetupCharactersPosition() noexcept;

	std::unique_ptr<class InputHandler> TurnInputHandler_;
	
	std::vector<ActionPtr> Actions_;
	ActionPtr ChooseAction(sf::Keyboard::Key Key);
	bool CheckActionQueue();
	
};



