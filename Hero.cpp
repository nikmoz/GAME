#include "Hero.h"



Hero::Hero(std::string TexturePath, sf::IntRect StartRect, HeroeDefs::Side Side):Side(std::move(Side))
{
	//Graphic init
	this->Texture.loadFromFile(TexturePath);
	this->Sprite.setTexture(this->Texture);
	this->Sprite.setTextureRect(StartRect);
	//Game init

}
void Hero::TakeTurn() {

}


