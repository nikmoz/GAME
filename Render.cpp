#include "Render.h"
Render::Render(const int RenderWidth, const int RenderHeight) :RenderWidth(RenderWidth), RenderHeight(RenderHeight)
{
	Characters = {};
};

void Render::RenderScene() {
	static sf::RenderWindow WindowScene(sf::VideoMode(RenderWidth, RenderHeight), "Test");

	if (WindowScene.isOpen())
	{
		sf::Event Event{};
		while (WindowScene.pollEvent(Event))
		{
			if (Event.type == sf::Event::Closed)
			{
				WindowScene.close();
			}
		}

		WindowScene.clear();
		for (auto& Char : Characters) {
			WindowScene.draw(Char->Sprite);
		}
		WindowScene.display();
	}
};
void Render::AddCharacter(const GraphicHeroPtr& Character) noexcept
{
	Characters.push_back(Character);
};