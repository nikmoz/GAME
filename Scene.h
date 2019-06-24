#pragma once
#include "Hero.h"
#include "WindowScene.h"
#include <vector>
#include <thread>
class Scene
{
public:
	Scene()=default;

	std::vector<std::shared_ptr<Hero>> Characters;

	//void Turn();
	void AddCharacter(std::shared_ptr<Hero> Character);

	~Scene() = default;
};



