#pragma once
#include <SFML/Graphics.hpp>
#include "Graphic.h"
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
class GraphicHero final :public Graphic
{
public:
	explicit GraphicHero(std::string_view FilePath);
	explicit GraphicHero(std::ifstream& GraphicFile);

	inline void Render(sf::RenderWindow& WindowScene) override;
	void LoadAnimation(AnimationState Animation);
	void Update() override;

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

