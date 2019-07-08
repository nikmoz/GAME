#pragma once
#include "Hero.h"
#include "Render.h"
#include "Action.h"
#include <vector>
#include <queue>

class Action;

using TargetPtr = std::shared_ptr<Hero>;
using ActionPtr=std::shared_ptr<Action>;

class Scene
{
public:
	virtual ~Scene()=default;
	std::vector<TargetPtr> Characters;

	virtual void UpdateScene()=0;
	virtual void Redraw()=0;//NOTE(Nick):Figure out if I still need Redraw in MVS approach
	virtual void Load(const std::string& FileName)=0;
	virtual void Unload()=0;

protected:
	std::unique_ptr<Render> Render_;

	std::queue<std::pair<ActionPtr, TargetPtr>> ActionQueue_;
};

