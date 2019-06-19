#pragma once
#include "Hero.h"
#include "WindowScene.h"
#include <vector>
class Scene
{
public:
	Scene()=default;

	std::vector<std::shared_ptr<Hero>> Characters;
	void AddCharacter(std::shared_ptr<Hero> Character);
	WindowScene* WindowScene;

	~Scene() = default;
};



