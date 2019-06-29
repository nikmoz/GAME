#include "Game.h"

using std::shared_ptr;
using std::unique_ptr;
int Game::WindowHeight = 400;
int Game::WindowWidth = 400;

shared_ptr<Scene> Game::CurrentScene = nullptr;
unique_ptr<InputHandler> Game::TurnInputHandler = std::make_unique<InputHandler>();

void Game::StartGame() 
{
	Render::SetupCharacters();

	while (true)
	{
		Render::RenderScene();

		if (Game::CheckActionQueue())
		{
			TurnInputHandler->HandleInput();
		}
		
	}
};
bool Game::CheckActionQueue()//NOTE(Nick): Cause some actions may have countdown, i probably should switch to vector instead of queue
{
	if (Game::CurrentScene->ActionQueue.size() == 0)
	{
		return true;
	}

	ActionPtr CurrentAction = Game::CurrentScene->ActionQueue.front().first;
	HeroPtr CurrentHero = Game::CurrentScene->ActionQueue.front().second;

	CurrentAction->execute(*CurrentHero);

	if (CurrentAction->IsResolved)
	{
		Game::CurrentScene->ActionQueue.pop();
	}

	return false;
};
void Game::InitScene()//NOTE(Nick):Future Load function
{
	Game::CurrentScene = std::make_unique<Scene>();
	shared_ptr<Hero> Uther(new Hero("Uther","res/img/sprite_base_addon_2012_12_14.png", sf::IntRect(10, 10, 70, 70), HeroeDefs::hero));
	shared_ptr<Hero> AUther(new Hero("Arthas","res/img/sprite_base_addon_2012_12_14.png", sf::IntRect(10, 10, 70, 70), HeroeDefs::enemy));

	TurnInputHandler->Subscribe(Game::CurrentScene);

	Game::CurrentScene->SetupActions();//TODO(Nick):Move to normal Load

	Game::CurrentScene->AddCharacter(move(Uther));
	Game::CurrentScene->AddCharacter(move(AUther));
};