#pragma once
#include <map>

#include <SFML/Window/Keyboard.hpp>

enum class KeyState
{
	Pressed,
	Released
};

class InputHandler
{
public:
	InputHandler();

	sf::Keyboard::Key HandleInput();
private:
	std::map<sf::Keyboard::Key,KeyState> Key_;
};

