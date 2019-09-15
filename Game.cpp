#include "Game.h"

#include "BattleScene.h" 


std::unique_ptr<InputHandler> Game::InputPtr_ = std::make_unique<InputHandler>();
std::deque<GameDef::ScenePtr> Game::SceneDeque{};

void Game::StartGame() 
{
	while (true)
	{
		auto Key=Game::InputPtr_->HandleInput();
		if(Key!=sf::Keyboard::Unknown)
		{
			Game::SceneDeque.front()->UpdateScene(Key);
		}

		Game::SceneDeque.front()->Redraw();
	}
};

void Game::InitGame()
{

	Game::SceneDeque.push_back(std::make_shared<BattleScene>());

	Game::SceneDeque.front()->Load("res/xml/Scene.xml");
}

