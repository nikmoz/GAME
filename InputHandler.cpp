#include "InputHandler.h"

InputHandler::InputHandler()
{
	for (auto I=0; I<sf::Keyboard::KeyCount;I++)
	{
		Key_[static_cast<sf::Keyboard::Key>(I)]=KeyState::Released;
	}
}

sf::Keyboard::Key InputHandler::HandleInput()
{
	for(auto I=0; I<sf::Keyboard::KeyCount;I++)
	{
		auto Key=static_cast<sf::Keyboard::Key>(I);

		if (sf::Keyboard::isKeyPressed(Key))
		{
			if (Key_[Key]==KeyState::Released)
			{
				Key_[Key]=KeyState::Pressed;
				return Key;
			}
		}
		else
		{
			Key_[Key]=KeyState::Released;
		}
	}
	return sf::Keyboard::Unknown;
}