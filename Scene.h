#pragma once
#include "Hero.h"
#include "DOMParser.h"
#include "Action.h"
#include <vector>
#include <thread>

class Scene
{
public:
	Scene()=default;
	std::vector<std::shared_ptr<Hero>> Characters;
	void Turn();

	void AddCharacter(std::shared_ptr<Hero> Character);
	

	~Scene() = default;
private:
	void SetupActions(std::string ActionPath);
	std::vector<class Action*> Actions;
	class Action* ChooseAction();
};



