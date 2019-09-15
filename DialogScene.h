#pragma once
#include "Scene.h"
class DialogScene final :
	public Scene
{
	void UpdateScene(sf::Keyboard::Key) override;
	void Redraw() override;
	void Load(std::string_view FileName) override;
	void Unload() override;
};

