#pragma once
#include <SFML/Graphics.hpp>
#include "TagXMLParser.h"
#include <chrono>
#include <map>
#include "Animation.h"

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

	double OldTime_=0;
	double NewTime_=0;

	std::shared_ptr<AnimationData> Animation_;
	
	sf::IntRect SpriteRect_;
};

