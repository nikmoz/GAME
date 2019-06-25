#pragma once
#include "Hero.h"
#include "Observer.h"
#include "DOMParser.h"
#include "Action.h"
#include <vector>
#include <thread>

class Scene:public Observer
{
public:
	Scene()=default;
	std::vector<std::shared_ptr<Hero>> Characters;
	void Turn();
	void SetupActions(std::string ActionPath);
	void AddCharacter(std::shared_ptr<Hero> Character);
	void update(Keyboard::Keys Key) override {};

	~Scene() = default;
private:
	int currentChar = 0;
	std::vector<class Action*> Actions;
	class Action* ChooseAction();
};



