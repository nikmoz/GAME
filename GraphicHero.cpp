#include "GraphicHero.h"


GraphicHero::GraphicHero(std::string TexturePath, sf::IntRect StartRect)
{
	this->Texture.loadFromFile(TexturePath);
	this->Sprite.setTexture(this->Texture);
	this->Sprite.setTextureRect(StartRect);
}
/*THEME(Nick):Animation()
{
	Problem 1: How to iterate through spritesheet? Different sprites have different sizes, and space bettwen two in one spritesheet is different. 
	Problem 2: Different animation duration.
	Solution 1:
	Google this
}
*/


