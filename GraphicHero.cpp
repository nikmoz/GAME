#include "GraphicHero.h"


GraphicHero::GraphicHero(const std::string& TexturePath, const sf::IntRect StartRect)
{
	this->Texture_.loadFromFile(TexturePath);
	this->Sprite.setTexture(this->Texture_);
	this->Sprite.setTextureRect(StartRect);
}
/*TODO(Nick):Animation()
{
	Problem 1: How to iterate through sprite sheet? Different sprites have different sizes, and space between two in one sprite sheet is different. 
	Problem 2: Different animation duration.
	Solution 1:
	Google this
}
*/


