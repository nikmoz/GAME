#pragma once
#include "Hero.h"
#include "Scene.h"
#include "Observer.h"
#include "Action.h"
#include "Render.h"
#include "InputHandler.h"
#include <vector>
#include <queue>


class BattleScene:public Scene,public Observer
{
public:
	
	BattleScene()=default;
	~BattleScene() = default;


	void Load() override;

	void UpdateScene() override; //Calculates scene next state
	void update(Keyboard::Keys Key)override;//Reacts to key Input

	void Unload() override {};
	void Redraw() override;//TODO(Nick): Move Render Instance here from Game class(probably)

	void AddCharacter(HeroPtr Character);

	
private:
	int currentChar = 0;

	void SetupCharactersPosition();

	std::unique_ptr<class InputHandler> TurnInputHandler;
	
	std::vector<ActionPtr> Actions;
	ActionPtr ChooseAction(Keyboard::Keys Key);
	bool CheckActionQueue();
	
};



