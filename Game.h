#pragma once
#include "Scene.h"

#include <memory>
#include <deque>

#include "InputHandler.h"

namespace GameDef
{
	using ScenePtr=std::shared_ptr<class Scene>;
}

class Game
{
public:
	static void StartGame();
	static void InitGame();

	static std::deque<GameDef::ScenePtr> SceneDeque;//NOTE:Probably change to vector, to evade bugs with pop_front()
private:

	static std::unique_ptr<InputHandler> InputPtr_;
};

