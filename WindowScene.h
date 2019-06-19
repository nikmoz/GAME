#pragma once
#include <SFML/Graphics.hpp>
#include "Hero.h"
class WindowScene
{
public:
	WindowScene(int SceneWidth, int SceneHeight);

	std::vector<std::shared_ptr<Hero>> Characters;
	void SetupCharacter();
	void RenderScene();
	~WindowScene()=default;
private:
	int SceneWidth = 0;
	int SceneHeight = 0;
};

