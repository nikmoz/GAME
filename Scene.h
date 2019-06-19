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

	void Turn();
	void AddCharacter(std::shared_ptr<Hero> Character);

	void SetupCharacter();//TODO:Create Graphic class for this
	void RenderScene();//TODO:Create Graphic class for this
	

	~Scene() = default;
private:
	int SceneWidth = 0;
	int SceneHeight = 0;
};



