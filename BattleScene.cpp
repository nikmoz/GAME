#include "BattleScene.h"

#include "NameAction.h"
#include "SideAction.h"
#include "TargetAction.h"

using std::move;

void BattleScene::AddCharacter(HeroPtr Character)
{
	Characters.push_back(Character);
	Render->AddCharacter(Character->Graphic);
};
/*THEME(Nick):Turn() 
	Problem 1:How to change targets without passing Characters to Hero Class(tried GameClass with static, but it didn'n look nice)
	Problem 2:Attack and Defend cosumes turn, while ChangeTarget doesn't
	Problem 3:Skill system allows for multiple target types and multiple turn actions, which leads to bigger problem than problem 1

	Solution 1(checking...):
	Create Action stack and countdown param in Action
	Create LoadAction() that loads Action list for scene(probably move to global scene load later) (Check next ChooseAction() THEME)
	Create ChooseAction() that returns Action(Comman pattern)(Done)
	Execute Action, which leads to finding out target and executing one of the functions in Hero
*/
/*THEME(Nick):ChooseAction()
	The way is see it:
	Battle starts->
	Some Game function loads characters->
	Scene setups charaters Actions->
	User chooses skill->
	User chooses Targets->
	Action executes->
	Tasks being cheecked

	Root 1: In current state scene should know about all actions for each actor
		Solution 1:
			Create set of actions {NextAction,PrevAction,ExecuteAction} and store actions in HeroClass
			Argument:
				This will keep Scene from knowing all actions, and leads to only 1 actions loading, on Character init
				More over, it means, that scene doesn't have same action patter in each battle
				Despite it leads to storing copys of one action in heroes, but their size is so small it will not became a problem
		Solution 2:
			Set of {Attack,Defend,Skill}. Attack and Defend execute Attack and Defend methods in Hero(or just call execute() on Action)
			Skill calls LoadSkills for current Hero, creating new set of actions
			Argument:
				No copies of standart actions in standart encounters
				This will move all action resolving staff into Hero class, and easy tom implement, 
				but I'l be stuck with same Attack,Defend, Skill (and future Party) pattern
		Solution 3:
			Keep it that way, and think of format, that can save all information needed
			Argument:
				Headers aren't this kind of problem you should be thinking of
				Scenes than can have differen set of actions for each encounter(And writing standart set in each standart battle)

	Root 2: Where is loading actions supposed to happen?
		Solution 1: On Character init (seems nice, but restrictive)
			Argument:
				Keeps character data in character class
				Creates copies of standart actions(if second solutions isn't choosed)
				Don't sure how to create special scene-based actions
		Solution 2: On Scene init (seems really bad)
			Argument:
				Easy scene-based actions creation
				Scene should know about all characters skills
		Solution 3: On Calling Skill action (seems interesting, but with ugly code)
			Argument:
				Easy scene-based  and plot-based actions creation
				Scene should know about all characters skills
				Loads skills only if needed

	Root 3: Separeted Scene and render means InputHandler code dublication
		Solution 1:
			Create static InputHandler class that notifies each sub on key input. Make Scene and Render subs.(Done)
		Solution 2:
			Create static InputHandler class that sends action to each sub. Make Scene and Render subs.
*/

ActionPtr BattleScene::ChooseAction(Keyboard::Keys Key)//TODO(Nick):Read about Factory method
{
	static auto i(0);

	if (Key==Keyboard::Down)
	{
		if (i < Actions.size() - 1)
		{
			i++;

			std::cout << "Current Action:" << i<< std::endl;
		}
		return nullptr;
	}

	if (Key == Keyboard::Up)
	{
		if (i > 0)
		{
			i--;

			std::cout << "Current Action:" << i << std::endl;
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

void BattleScene::update(Keyboard::Keys Key)
{
	ActionPtr TurnAction = ChooseAction(Key);

	if (TurnAction == nullptr) { 
		return;
	}

	std::cout <<"Current Char:"<< Characters.at(currentChar)->Name << std::endl;

	TurnAction->execute(*Characters.at(currentChar));
	if (!TurnAction->IsResolved)
	{
		HeroPtr Char = Characters.at(currentChar);
		ActionQueue.push(std::make_pair(TurnAction, Char));
	}

	currentChar++;
	if (currentChar >= Characters.size())
	{
		currentChar = 0;
	}
};

void BattleScene::UpdateScene()
{
	if (CheckActionQueue())
	{
		TurnInputHandler->HandleInput();
	}
};

void BattleScene::Redraw()
{
	Render->RenderScene();
};

void BattleScene::Load()//TODO(Nick): Figure out normal loading variant
{
	Render = std::make_unique<class Render>(400,400);

	HeroPtr Uther(new Hero("Uther", "res/img/sprite_base_addon_2012_12_14.png", sf::IntRect(10, 10, 70, 70), HeroeDefs::hero));
	HeroPtr AUther(new Hero("Arthas", "res/img/sprite_base_addon_2012_12_14.png", sf::IntRect(10, 10, 70, 70), HeroeDefs::enemy));

	AddCharacter(move(Uther));
	AddCharacter(move(AUther));
	SetupCharactersPosition();

	TurnInputHandler= std::make_unique<class InputHandler>();
	TurnInputHandler->Subscribe(std::shared_ptr<Observer>(this));

	this->Actions.push_back(ActionPtr(new NameAction));
	this->Actions.push_back(ActionPtr(new SideAction));
	this->Actions.push_back(ActionPtr(new TargetAction));

}

bool BattleScene::CheckActionQueue()//NOTE(Nick): Cause some actions may have countdown, i probably should switch to vector instead of queue
{
	if (ActionQueue.size() == 0)
	{
		return true;
	}

	ActionPtr CurrentAction = ActionQueue.front().first;
	HeroPtr CurrentHero = ActionQueue.front().second;

	CurrentAction->execute(*CurrentHero);

	if (CurrentAction->IsResolved)
	{
		ActionQueue.pop();
	}

	return false;
};

void BattleScene::SetupCharactersPosition() {
	auto HeroCount(0);
	auto EnemyCount(0);
	auto SpriteSpace(100);

	for (auto& Char : Characters)
	{
		if (Char->Side == HeroeDefs::hero) {
			HeroCount++;
			Char->Graphic->Sprite.setPosition(static_cast<float>(Render->RenderWidth) / 2 - SpriteSpace * HeroCount, static_cast<float>(Render->RendeHeight) / 2);

		}
		else if (Char->Side == HeroeDefs::enemy) {
			EnemyCount++;
			Char->Graphic->Sprite.setPosition(static_cast<float>(Render->RenderWidth) / 2 + SpriteSpace * EnemyCount, static_cast<float>(Render->RendeHeight) / 2);

		}
	}
};