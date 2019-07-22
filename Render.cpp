#include "Render.h"
Render::Render(const int RenderWidth, const int RenderHeight) :RenderWidth(RenderWidth), RenderHeight(RenderHeight)
{
	Characters_ = {};
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
		for (auto& Char : Characters_)
		{
			WindowScene.draw(Char->Sprite);
		}
		for(auto& Dialog: Dialogs_)
		{
			if (!Dialog->LineDone)
			{
				Dialog->Update();
				WindowScene.draw(Dialog->Text);
			}
		}

		WindowScene.display();
	}
};
void Render::AddCharacter(const GraphicHeroPtr& Character) noexcept
{
	Characters_.push_back(Character);
}

void Render::AddDialog(const DialogPtr& Dialog) noexcept
{
	Dialogs_.push_back(Dialog);
};
