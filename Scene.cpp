#include "Scene.h"

#include "NameAction.h"
#include "SideAction.h"
using std::move;
using std::shared_ptr;

void Scene::AddCharacter(shared_ptr<Hero> Character)
{
	this->Characters.push_back(Character);
};
/*THEME(Nick):Turn() {
	Problem 1:How to change targets without passing Characters to Hero Class(tried GameClass with static, but it didn'n look nice)
	Problem 2:Attack and Defend cosumes turn, while ChangeTarget doesn't
	Problem 3:Skill system allows for multiple target types and multiple turn actions, which leads to bigger problem than problem 1

	Solution 1(checking...):
	Create LoadAction() that loads Action list for scene(probably move to global scene load later)
	Create ChooseAction() that returns Action(Comman pattern), solves problem 2 (Done)
	Execute Action, which leadû to finding target and executing one of the functions in Hero, solves problems 1 and 3(?)
};*/
void Scene::Turn() 
{
	SetupActions("res/Standart.xml");
	for (auto& Char:Characters)
	{
		std::cout << Char->Name << '\n';
		Action* TurnAction = ChooseAction();
		TurnAction->execute(*Char);
	}
}
Action* Scene::ChooseAction()//TODO(Nick):Read about Factory method
{
	auto i(0);
	static bool KeyPressed = false;
	while (true)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			if (!KeyPressed)
			{
				KeyPressed = true;
				if (i < Actions.size() - 1)
				{
					i++;
				}
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			if (!KeyPressed)
			{
				KeyPressed = true;
				if (i > 0)
				{
					i--;
				}
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			if (!KeyPressed)
			{
				KeyPressed = true;
				return Actions.at(i);
			}
		}
		else
		{
			KeyPressed = false;
		}
	}
};
void Scene::SetupActions(std::string ActionPath)//TODO(Nick): Change to load function
{
	DOMParser::StartParsing(ActionPath);
	this->Actions.push_back(new NameAction);
	this->Actions.push_back(new SideAction);
}
