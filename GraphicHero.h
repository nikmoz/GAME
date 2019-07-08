#pragma once
#include <SFML/Graphics.hpp>
#include <fstream>
#include "TagXMLParser.h"
#include <chrono>
#include "AutoIncrementer.h"

using namespace std::chrono_literals;
class GraphicHero
{
public:
	explicit GraphicHero(const std::string& FilePath);

	void Update();//NOTE(Nick):Google about sprite animation

	~GraphicHero()=default;

	sf::Sprite Sprite;
private:
	//AutoIncrementer<sf::Sprite> AnimationIncrement_;

	int AnimationDuration_;
	int AnimationFrames_;
	int SpriteSpacing_;

	sf::Texture Texture_;

	int EndRect_;
	sf::IntRect StartRect_;
};

