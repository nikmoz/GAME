#pragma once
#include <SFML/Graphics.hpp>
#include "GraphicHero.h"
#include "Dialog.h"

using GraphicHeroPtr=std::shared_ptr<GraphicHero>;
using DialogPtr=std::shared_ptr<Dialog>;

class Render//NOTE(Nick): Moved from static class, so I'm not bound to CurrentScene character set, and can create GUI stack
{
public:
	Render(int RenderWidth, int RenderHeight);
	~Render()=default;
	
	void AddCharacter(const GraphicHeroPtr& Character) noexcept;
	void AddDialog(const DialogPtr& Dialog) noexcept;

	void RenderScene();

	int RenderWidth;
	int RenderHeight;
private:
	
	std::vector<DialogPtr> Dialogs_;
	std::vector<GraphicHeroPtr> Characters_;
};

