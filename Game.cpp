#include "Game.h"

#include "BattleScene.h" //NOTE(Nick): Stays here before I can make state machine for SceneChanging



std::deque<GameDef::ScenePtr> Game::SceneStack{};

void Game::StartGame() 
{

	while (true)
	{
		for(const auto& Scene:SceneStack)
		{
			Scene->Redraw();
		}
		Game::SceneStack.front()->UpdateScene();
	}
};

void Game::InitScene()
{

	Game::SceneStack.push_back(std::make_shared<BattleScene>());

	Game::SceneStack.front()->Load("res/xml/Scene.xml");
};