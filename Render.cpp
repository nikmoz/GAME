#include "Render.h"
Render::Render(int RenderWidth, int RendeHeight) :RendeHeight(RendeHeight), RenderWidth(RenderWidth) {};

void Render::RenderScene() {
	static sf::RenderWindow WindowScene(sf::VideoMode(RenderWidth, RendeHeight), "Test");

	if (WindowScene.isOpen())
	{
		sf::Event event;
		while (WindowScene.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
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
void Render::AddCharacter(GraphicHeroPtr Character) 
{
	Characters.push_back(Character);
};