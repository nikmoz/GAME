#pragma once
#include "Hero.h"
#include "WindowScene.h"
#include <vector>
#include <thread>
class Scene
{
public:
	Scene(int SceneWidth, int SceneHeight);



	std::vector<std::shared_ptr<Hero>> Characters;
	//std::unique_ptr<sf::RenderWindow> WindowScene;

	void AddCharacter(std::shared_ptr<Hero> Character);
	void SetupCharacter();
	void RenderScene();
	void Turn();

	~Scene() = default;
private:
	int SceneWidth = 0;
	int SceneHeight = 0;
};



