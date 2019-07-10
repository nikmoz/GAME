#pragma once
#include <SFML/Graphics.hpp>
#include <fstream>
#include "TagXmlParser.h"
#include <chrono>
#include "AutoIncrementer.h"

using namespace std::chrono_literals;
class GraphicHero
{
public:
	explicit GraphicHero(const std::string& FilePath);
	explicit GraphicHero(std::ifstream& GraphicFile);

	std::shared_ptr<class Hero> Game;

	void Update();//NOTE(Nick):Google about sprite animation

	~GraphicHero()=default;

	sf::Sprite Sprite;
private:
	//AutoIncrementer<sf::Sprite> AnimationIncrement_;
	double OldTime_=0;
	double NewTime_=0;
	//double TotalTime_=0;

	double AnimationDuration_;
	int AnimationFrames_;
	int SpriteSpacing_;

	sf::Texture Texture_;

	int EndRect_;
	sf::IntRect StartRect_;
};

