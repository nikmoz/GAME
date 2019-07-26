#pragma once
#include <SFML/Graphics.hpp>
class Graphic
{
public:
	virtual ~Graphic() = default;
	virtual void Update()=0;
	virtual void Render(sf::RenderWindow& WindowScene)=0;
};

