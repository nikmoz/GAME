#include "InputHandler.h"

void InputHandler::notify(Keyboard::Keys Key) {
	for (auto& Sub :Subs) {
		Sub->update(Key);
	}
}

void InputHandler::Subscribe(Subscriber Sub) {
	Subs.push_back(Sub);
}

void InputHandler::HandleInput() {
	static bool KeyPressed = false;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if (!KeyPressed)
		{
			KeyPressed = true;
			InputHandler::notify(Keyboard::Down);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if (!KeyPressed)
		{
			KeyPressed = true;
			InputHandler::notify(Keyboard::Left);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if (!KeyPressed)
		{
			KeyPressed = true;
			InputHandler::notify(Keyboard::Right);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if (!KeyPressed)
		{
			KeyPressed = true;
			InputHandler::notify(Keyboard::Up);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{
		if (!KeyPressed)
		{
			KeyPressed = true;
			InputHandler::notify(Keyboard::Enter);
		}
	}
	else
	{
		KeyPressed = false;
	}
}