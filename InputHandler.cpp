#include "InputHandler.h"


void InputHandler::notify(Keyboard::Keys Key) {
	for (auto& Sub :Subs) {
		Sub->update(Key);
	}
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