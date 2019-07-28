#pragma once
#include "Scene.h"
#include <memory>
#include <deque>

namespace GameDef
{
	using ScenePtr=std::shared_ptr<class Scene>;
}
class Game
{
public:
	static void StartGame();
	static void InitScene();

	static std::deque<GameDef::ScenePtr> SceneStack;//NOTE:Probably change to vector, to evade bugs with pop_front()
};

