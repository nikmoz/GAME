#pragma once
#include <SFML/Graphics.hpp>
#include "Graphic.h"

using GraphicPtr=std::shared_ptr<Graphic>;

class Render//NOTE(Nick): Moved from static class, so I'm not bound to CurrentScene character set, and can create GUI stack
{
public:
	Render(int RenderWidth, int RenderHeight);
	~Render()=default;
	
	void AddObject(const GraphicPtr& Object) noexcept;

	void RenderScene();

	int RenderWidth;
	int RenderHeight;
private:
	
	std::vector<GraphicPtr> Objects_;
};

