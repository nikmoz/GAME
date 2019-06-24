#include "Scene.h"
using std::move;
using std::shared_ptr;

void Scene::AddCharacter(shared_ptr<Hero> Character) {
	this->Characters.push_back(Character);
};
/*THEME(Nick):Turn() {
	Problem 1:How to change targets without passing Characters to Hero Class(tried GameClass with static, but it didn'n look nice)
	Problem 2:Attack and Defend cosumes turn, while ChangeTarget doesn't
	Problem 3:Skill system allows for multiple target types and multiple turn actions, which leads to bigger problem than problem 1

	Solution 1(checking...):
	Create ChooseAction() that returns Action(Comman pattern), solves problem 2
	Create ChooseTarget() that calls action passing target and actor, solves problem 1(?)
	Execute Action, which lead to executing one of the functions in Hero, solves problem 3(?)
};*/
