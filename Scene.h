#pragma once
#include "Hero.h"
#include "Observer.h"
#include "DOMParser.h"
#include "Action.h"
#include <vector>
#include <thread>
#include "NameAction.h"
#include "SideAction.h"

class Scene:public Observer
{
public:
	Scene()=default;
	std::vector<std::shared_ptr<class Hero>> Characters;
	void SetupActions(std::string ActionPath);
	void AddCharacter(std::shared_ptr<class Hero> Character);
	void update(Keyboard::Keys Key)override;

	~Scene() = default;
private:
	int currentChar = 0;
	std::vector<class Action*> Actions;
	class Action* ChooseAction(Keyboard::Keys Key);
};



