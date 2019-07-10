#include "InputHandler.h"

InputHandler::InputHandler()
{
	for (auto I=0; I<sf::Keyboard::KeyCount;I++)
	{
		Key_[static_cast<sf::Keyboard::Key>(I)]=KeyState::Released;
	}
}


void InputHandler::Notify(const sf::Keyboard::Key Key) 
{
	for (auto& Sub :Subs) {
		Sub->Update(Key);
	}
}

void InputHandler::Subscribe(const Subscriber& Sub)
{
	Subs.push_back(Sub);
}

void InputHandler::HandleInput()
{

	for(auto I=0; I<sf::Keyboard::KeyCount;I++)
	{
		auto Key=static_cast<sf::Keyboard::Key>(I);

		if (sf::Keyboard::isKeyPressed(Key))
		{
			if (Key_[Key]==KeyState::Released)
			{
				Key_[Key]=KeyState::Pressed;
				InputHandler::Notify(Key);
			}
		}
		else
		{
			Key_[Key]=KeyState::Released;
		}
	}
	
}