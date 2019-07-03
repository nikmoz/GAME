#pragma once
#include <SFML/Graphics.hpp>
#include <chrono>
#include "AutoIncrementer.h"

using namespace std::chrono_literals;
class GraphicHero
{
public:
	GraphicHero(const std::string& TexturePath, sf::IntRect StartRect,std::chrono::seconds AnimationDuration, int AnimationFrames, int SpriteSpacing);

	void Update();//NOTE(Nick):Google about sprite animation

	~GraphicHero()=default;

	sf::Sprite Sprite;
private:
	//AutoIncrementer<sf::Sprite> AnimationIncrement_;

	std::chrono::seconds AnimationDuration_;
	int AnimationFrames_;
	int SpriteSpacing_;

	sf::Texture Texture_;

	int EndRect_;
	sf::IntRect StartRect_;
};

