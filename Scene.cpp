#include "Scene.h"

using std::move;

void Scene::AddCharacter(HeroPtr Character)
{
	this->Characters.push_back(Character);
};
/*THEME(Nick):Turn() 
	Problem 1:How to change targets without passing Characters to Hero Class(tried GameClass with static, but it didn'n look nice)
	Problem 2:Attack and Defend cosumes turn, while ChangeTarget doesn't
	Problem 3:Skill system allows for multiple target types and multiple turn actions, which leads to bigger problem than problem 1

	Solution 1(checking...):
	Create LoadAction() that loads Action list for scene(probably move to global scene load later)
	Create ChooseAction() that returns Action(Comman pattern), solves problem 2 (Done)
	Execute Action, which leadû to finding target and executing one of the functions in Hero, solves problems 1 and 3(?)
*/
/*THEME(Nick):ChooseAction()
	Root 1: In current state scene should know about all actions for each actor
		Branch 1: Loading actions
			Problem 1: Scene can load all actions(which means including all headers which leads to MASSIVE problems with skills) and huge memory problems
			Problem 2: Scene can load only character needed actions, but scene should know how to create every action
		Branch 2: Saving actions
			Problem 1: How and there to save
			Problem 2: How to read
		Solution 1:
			Create set of actions {NextAction,PrevAction,ExecuteAction} and store actions in HeroClass
			The way is see it:Battle starts->Some Game function loads characters->Scene setup charaters Actions->User chooses skill->User chooses Targets->Action executes
			If i store all actions in character, it will be easy to save and load them(because there is only one file for each character to read)
			But if Scene knows about actions, than it should load them every time User chooses SkillAction, or it should save actions in some tricky way
			Yes, i'll have multiple action copies in each hero Object. And it also leads to binding Actions with Actors, so i won't have this execute(Actor) call
			Argument:
				This will keep Scene from knowing all actions, and leads to only 1 action loading on Character init
				More over, it mean, that scene doesn't have same action patter in each battle
				Despite it leads to storing copys of one action in heroes, but their size is so small it will not became a problem
		Solution 2:
			Set of {Attack,Defend,Skill}. Attack and Defend execute Attack and Defend methods in Hero(or just call execute() on Action)
			Skill calls LoadSkills for current Hero, creating new set of actions
		Solution 3:
			Keep it that way, and think of format, that can save all information needed
			Argument:
				Headers aren't this kind of problem you should be thinking of(Spent 30 minutes, trying to figure out why child class can't see its base class)
				Scenes than can have differen set of actions for each encounter(And writing standart set in each standart battle)
	Root 2: Separeted Scene and render means InputHandler code dublication
		Solution 1:
			Create static InputHandler class that notifies each sub on key input. Make Scene and Render subs.
		Solution 2:
			Create static InputHandler class that sends action to each sub. Make Scene and Render subs.
*/

Action* Scene::ChooseAction(Keyboard::Keys Key)//TODO(Nick):Read about Factory method
{
	static auto i(0);
	if (Key==Keyboard::Down)
	{
		if (i < Actions.size() - 1)
		{
			i++;
		}
		return nullptr;
	}
	if (Key == Keyboard::Up)
	{
		if (i > 0)
		{
			i--;
		}
		return nullptr;
	}
	if (Key == Keyboard::Enter)
	{
			auto tmp = i;
			i = 0;
			return Actions.at(tmp);
	}
	return nullptr;
};
void Scene::update(Keyboard::Keys Key)
{
	Action* TurnAction = ChooseAction(Key);
	if (TurnAction == nullptr) { 
		return;
	}
	TurnAction->execute(*Characters.at(currentChar));
	currentChar++;
	if (currentChar >= Characters.size())
	{
		currentChar = 0;
	}
};
void Scene::SetupActions(std::string ActionPath)//TODO(Nick): Change to load function
{
	//DOMParser::StartParsing(ActionPath);
	this->Actions.push_back(new NameAction);
	this->Actions.push_back(new SideAction);
}
