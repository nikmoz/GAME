#pragma once
#include "Hero.h"
#include "Render.h"
#include <vector>


namespace SceneDef
{
	using TargetPtr = std::shared_ptr<Hero>;
	
}

class Scene
{
public:

	virtual ~Scene()=default;
	std::vector<SceneDef::TargetPtr> Characters;

	virtual void UpdateScene()=0;
	virtual void Redraw()=0;//NOTE(Nick):Figure out if I still need Redraw in MVS approach
	virtual void Load(const std::string& FileName)=0;
	virtual void Unload()=0;

protected:
	std::shared_ptr<Render> Render_;
	std::shared_ptr<class Scene> PreviousScene_;
};

