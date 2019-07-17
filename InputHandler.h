#pragma once
#include "Observer.h"
#include <vector>
#include <memory>
#include <map>

#include <SFML/Window/Keyboard.hpp>

namespace HandlerDef
{
	using Subscriber=std::shared_ptr<class Observer>;
}
enum class KeyState
{
	Pressed,
	Released
};

class InputHandler
{
public:
	InputHandler();

	void Subscribe(const HandlerDef::Subscriber& Sub);
	void HandleInput();
	std::vector<HandlerDef::Subscriber> Subs={};
private:
	static std::map<sf::Keyboard::Key,KeyState> Key_;
	void Notify(sf::Keyboard::Key Key);
};

