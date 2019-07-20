#pragma once
#include <SFML/Graphics.hpp>
struct AnimationData
{
	double AnimationDuration{};
	int AnimationFrames{};
	int SpriteSpacing{};

	sf::Texture Texture;

	int EndRect{};
};