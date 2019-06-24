#include "Game.h"
using namespace std;
int Game::WindowHeight = 400;
int Game::WindowWidth = 400;
unique_ptr<Scene> Game::CurrentScene = nullptr;

void Game::StartGame() 
{
	std::thread GUI(Render::RenderScene);//NOTE(Nick):Check thread and non-thread GUI
	GUI.join();//NOTE(Nick): Probably move this to another function
};
void Game::InitScene()//NOTE(Nick):Future Load function
{
	Game::CurrentScene = std::unique_ptr<Scene>(new Scene);
	shared_ptr<Hero> Uther(new Hero("res/img/sprite_base_addon_2012_12_14.png", sf::IntRect(10, 10, 70, 70), HeroeDefs::hero));
	shared_ptr<Hero> AUther(new Hero("res/img/sprite_base_addon_2012_12_14.png", sf::IntRect(10, 10, 70, 70), HeroeDefs::enemy));
	Game::CurrentScene->AddCharacter(move(Uther));
	Game::CurrentScene->AddCharacter(move(AUther));
};