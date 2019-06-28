#pragma once
#include "InputHandler.h"
#include "Scene.h"
#include "Render.h"
#include <memory>
#include <thread>
class Game
{
public:
	static void StartGame();
	static void InitScene();
	static std::shared_ptr<class Scene> CurrentScene;
	static int WindowWidth;
	static int WindowHeight;
private:
	static std::unique_ptr<class InputHandler> TurnInputHandler;
};

