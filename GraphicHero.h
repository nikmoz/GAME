#pragma once
#include <SFML/Graphics.hpp>
#include <fstream>
#include "TagXMLParser.h"
#include <chrono>
#include <map>

enum class AnimationState
{
	None,
	Idle,
	Chosen
};

using namespace std::chrono_literals;
class GraphicHero
{
public:
	explicit GraphicHero(const std::string& FilePath);
	explicit GraphicHero(std::ifstream& GraphicFile);


	void LoadAnimation(AnimationState Animation);
	void Update();//NOTE(Nick):Google about sprite animation

	~GraphicHero()=default;


	sf::Sprite Sprite;
private:
	AnimationState CurrentAnimation_=AnimationState::None;

	std::map<AnimationState,std::string> AnimationMap_;
	//AutoIncrementer<sf::Sprite> AnimationIncrement_;
	double OldTime_=0;
	double NewTime_=0;
	//double TotalTime_=0;

	double AnimationDuration_{};
	int AnimationFrames_{};
	int SpriteSpacing_{};

	sf::Texture Texture_;

	int EndRect_{};
	sf::IntRect SpriteRect_;
};

