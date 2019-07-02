#include "InputHandler.h"

void InputHandler::Notify(const Keyboard::Keys Key) {
	for (auto& Sub :Subs) {
		Sub->Update(Key);
	}
}

void InputHandler::Subscribe(const Subscriber& Sub) {
	Subs.push_back(Sub);
}

void InputHandler::HandleInput() {
	static auto KeyPressed = false;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if (!KeyPressed)
		{
			KeyPressed = true;
			InputHandler::Notify(Keyboard::Down);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if (!KeyPressed)
		{
			KeyPressed = true;
			InputHandler::Notify(Keyboard::Left);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if (!KeyPressed)
		{
			KeyPressed = true;
			InputHandler::Notify(Keyboard::Right);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if (!KeyPressed)
		{
			KeyPressed = true;
			InputHandler::Notify(Keyboard::Up);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{
		if (!KeyPressed)
		{
			KeyPressed = true;
			InputHandler::Notify(Keyboard::Enter);
		}
	}
	else
	{
		KeyPressed = false;
	}
}