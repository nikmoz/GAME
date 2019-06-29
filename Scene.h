#pragma once
#include "Hero.h"
#include "Observer.h"
#include "Action.h"
#include <vector>
#include <thread>
#include <queue>

class Action;

using HeroPtr = std::shared_ptr<Hero>;
using ActionPtr=std::shared_ptr<Action>;



class Scene:public Observer
{
public:
	
	Scene()=default;

	std::queue<std::pair<ActionPtr,HeroPtr>> ActionQueue;
	std::vector<HeroPtr> Characters;

	void SetupActions();
	void AddCharacter(HeroPtr Character);
	void update(Keyboard::Keys Key)override;

	~Scene() = default;
private:
	
	int currentChar = 0;

	
	std::vector<ActionPtr> Actions;

	ActionPtr ChooseAction(Keyboard::Keys Key);
};



