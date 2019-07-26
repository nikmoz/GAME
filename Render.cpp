#include "Render.h"
Render::Render(const int RenderWidth, const int RenderHeight) :RenderWidth(RenderWidth), RenderHeight(RenderHeight)
{
	Objects_ = {};
};

void Render::RenderScene()
{
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
		for (auto& Object :Objects_)
		{
			Object->Update();
			Object->Render(WindowScene);
		}
		WindowScene.display();
	}
};
void Render::AddObject(const GraphicPtr& Object) noexcept
{
	Objects_.push_back(Object);
}
