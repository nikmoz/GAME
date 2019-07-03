#include "GraphicHero.h"

#include  <iostream>
GraphicHero::GraphicHero(const std::string& TexturePath, const sf::IntRect StartRect, const std::chrono::seconds AnimationDuration, const int AnimationFrames, const int SpriteSpacing)
:AnimationDuration_(AnimationDuration),AnimationFrames_(AnimationFrames),SpriteSpacing_(SpriteSpacing),StartRect_(StartRect)
{
	this->Texture_.loadFromFile(TexturePath);
	this->Sprite.setTexture(this->Texture_);
	this->Sprite.setTextureRect(StartRect);

	EndRect_=StartRect_.left+(StartRect_.width+SpriteSpacing_)*AnimationFrames_;
}
/*THEME(Nick):Animation()
{
	Problem 1: How to iterate through sprite sheet? Different sprites have different sizes, and space between two in one sprite sheet is different. 
	Problem 2: Different animation duration.
	Solution 1:
	Google this
}
*/
void GraphicHero::Update()
{
	if (Sprite.getTextureRect().left>=EndRect_)
	{
		Sprite.setTextureRect(StartRect_);
	}
	else
	{

		const sf::IntRect NextRect(Sprite.getTextureRect().left + Sprite.getTextureRect().width + SpriteSpacing_,
		                     Sprite.getTextureRect().top, Sprite.getTextureRect().width,
		                     Sprite.getTextureRect().height);
		Sprite.setTextureRect(NextRect);
	}
}



