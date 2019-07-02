#pragma once
#include <SFML/Graphics.hpp>
#include "GraphicHero.h"

using GraphicHeroPtr=std::shared_ptr<GraphicHero>;

class Render//NOTE(Nick): Moved from static class, so I'm not bound to CurrentScene character set, and can creat GUI stack
{
public:
	Render(int RenderWidth, int RendeHeight);
	~Render()=default;

	std::vector<GraphicHeroPtr> Characters;
	void AddCharacter(GraphicHeroPtr Character);

	void RenderScene();

	int RenderWidth;
	int RendeHeight;

};

