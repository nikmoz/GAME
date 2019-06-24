#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"
class Render
{
public:
	Render()=delete;
	~Render()=default;
	static void SetupCharacters();
	static void RenderScene();
};

