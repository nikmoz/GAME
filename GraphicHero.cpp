#include "GraphicHero.h"



GraphicHero::GraphicHero(std::string TexturePath, sf::IntRect StartRect)
{
	this->Texture.loadFromFile(TexturePath);
	this->Sprite.setTexture(this->Texture);
	this->Sprite.setTextureRect(StartRect);
}


