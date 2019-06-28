#include "Game.h"

using std::shared_ptr;
int Game::WindowHeight = 400;
int Game::WindowWidth = 400;
shared_ptr<Scene> Game::CurrentScene = nullptr;

void Game::StartGame() 
{
	Render::SetupCharacters();

	InputHandler::Subscribe(Game::CurrentScene);

	Game::CurrentScene->SetupActions("res/Standart.xml");//TODO(Nick):Move to normal Load

	while (true)
	{
		InputHandler::HandleInput();
		Render::RenderScene();
	}
};
void Game::InitScene()//NOTE(Nick):Future Load function
{
	Game::CurrentScene = std::make_unique<Scene>();
	shared_ptr<Hero> Uther(new Hero("Uther","res/img/sprite_base_addon_2012_12_14.png", sf::IntRect(10, 10, 70, 70), HeroeDefs::hero));
	shared_ptr<Hero> AUther(new Hero("Arthas","res/img/sprite_base_addon_2012_12_14.png", sf::IntRect(10, 10, 70, 70), HeroeDefs::enemy));
	Game::CurrentScene->AddCharacter(move(Uther));
	Game::CurrentScene->AddCharacter(move(AUther));
};