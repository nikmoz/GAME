#include "Game.h"

#include "BattleScene.h" //NOTE(Nick): Stays here before I can make state machine for SceneChanging


using std::shared_ptr;


shared_ptr<Scene> Game::CurrentScene = nullptr;

void Game::StartGame() 
{

	while (true)
	{
		Game::CurrentScene->Redraw();
		Game::CurrentScene->UpdateScene();
	}
};

void Game::InitScene()
{
	Game::CurrentScene = std::make_shared<BattleScene>();
	
	Game::CurrentScene->Load("res/xml/Scene.xml");
};