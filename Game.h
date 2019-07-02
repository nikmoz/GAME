#pragma once
#include "Scene.h"
#include <memory>
#include <thread>
class Game
{
public:
	static void StartGame();
	static void InitScene();
	static std::shared_ptr<class Scene> CurrentScene;
};

