#pragma once
#include <SFML/Graphics.hpp>
#include <string>

namespace HeroeDefs {
	enum Side{hero,enemy};
};

class Hero
{
public:

	Hero(std::string TexturePath, sf::IntRect StartRect,HeroeDefs::Side Side);
	
	HeroeDefs::Side Side;
	void TakeTurn();

	sf::Sprite Sprite;
	~Hero() = default;
private:
	sf::Texture Texture;
};

