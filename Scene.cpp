#include "Scene.h"
using std::move;
using std::shared_ptr;

Scene::Scene(int SceneWidth, int SceneHeight) :SceneWidth(move(SceneWidth)), SceneHeight(move(SceneHeight)){
};
void Scene::AddCharacter(shared_ptr<Hero> Character) {
	this->Characters.push_back(Character);
};
void Scene::Turn() {
	for (auto& Char : Characters) {
		Char->TakeTurn();
	}
};
void Scene::RenderScene() {
	sf::RenderWindow WindowScene(sf::VideoMode(this->SceneWidth, this->SceneHeight), "Test");
	SetupCharacter();

	while (WindowScene.isOpen())
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
		for (auto& Char : this->Characters) {
			WindowScene.draw(Char->Sprite);
		}
		WindowScene.display();
	}
};
void Scene::SetupCharacter() {
	int HeroCount = 1;
	int EnemyCount = 1;
	int SpriteSpace = 100;

	for (auto& Char : this->Characters) {
		if (Char->Side == HeroeDefs::hero) {
			Char->Sprite.setPosition(static_cast<float>(this->SceneWidth) / 2 - SpriteSpace * HeroCount, static_cast<float>(this->SceneHeight) / 2);
			HeroCount++;
		}
		else if (Char->Side == HeroeDefs::enemy) {
			Char->Sprite.setPosition(static_cast<float>(this->SceneWidth) / 2 + SpriteSpace * EnemyCount, static_cast<float>(this->SceneHeight) / 2);
			EnemyCount++;
		}
	}
	return;
};