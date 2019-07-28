#pragma once
#include "Scene.h"
class DialogScene final :
	public Scene
{
	void UpdateScene() override;
	void Redraw() override;
	void Load(const std::string& FileName) override;
	void Unload() override;
};

