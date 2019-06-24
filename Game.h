#pragma once
#include "Scene.h"
#include "Render.h"
#include <memory>
#include <thread>
class Game
{
public:
	static void StartGame();
	static void InitScene();
	static std::unique_ptr<Scene> CurrentScene;
	static int WindowWidth;
	static int WindowHeight;
};

