#include "Render.h"

void Render::RenderScene() {
	static sf::RenderWindow WindowScene(sf::VideoMode(Game::WindowWidth,Game::WindowHeight), "Test");

	if (WindowScene.isOpen())
	{
		sf::Event event;
		while (WindowScene.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				WindowScene.close();
			}
		}

		WindowScene.clear();
		for (auto& Char : Game::CurrentScene->Characters) {
			WindowScene.draw(Char->Graphic->Sprite);
		}
		WindowScene.display();
	}
};
void Render::SetupCharacters() {
	auto HeroCount(0);
	auto EnemyCount(0);
	auto SpriteSpace(100);

	for (auto& Char : Game::CurrentScene->Characters) {
		if (Char->Side == HeroeDefs::hero) {
			HeroCount++;
			Char->Graphic->Sprite.setPosition(static_cast<float>(Game::WindowWidth) / 2 - SpriteSpace * HeroCount, static_cast<float>(Game::WindowHeight) / 2);
			
		}
		else if (Char->Side == HeroeDefs::enemy) {
			EnemyCount++;
			Char->Graphic->Sprite.setPosition(static_cast<float>(Game::WindowWidth) / 2 + SpriteSpace * EnemyCount, static_cast<float>(Game::WindowHeight) / 2);
			
		}
	}
};