#pragma once
#include "SFML/Window/Keyboard.hpp"
class Observer
{
public:
	virtual ~Observer()=default;
	virtual void Update(sf::Keyboard::Key Key)=0;
};
