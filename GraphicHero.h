#pragma once
#include <SFML/Graphics.hpp>
class GraphicHero
{
public:
	GraphicHero(std::string TexturePath, sf::IntRect StartRect);

	void Animation();//NOTE(Nick):Google about sprite animation

	~GraphicHero()=default;

	sf::Sprite Sprite;
private:
	sf::Texture Texture;
};

