#pragma once
#include "Hero.h"
#include "Scene.h"
#include "Observer.h"
#include "Action.h"
#include "InputHandler.h"
#include <vector>


class BattleScene:public Scene,public Observer
{
public:
	
	BattleScene();
	~BattleScene() = default;


	void Load() override;

	void UpdateScene() override; //Calculates scene next state
	void Update(Keyboard::Keys Key)override;//Reacts to key Input

	void Unload() override {};
	void Redraw() override;//TODO(Nick): Move Render Instance here from Game class(probably)

	void AddCharacter(TargetPtr&& Character) noexcept;

	
private:
	unsigned int CurrentChar_ = 0;

	void SetupCharactersPosition() noexcept;

	std::unique_ptr<class InputHandler> TurnInputHandler_;
	
	std::vector<ActionPtr> Actions_;
	ActionPtr ChooseAction(Keyboard::Keys Key);
	bool CheckActionQueue();
	
};



