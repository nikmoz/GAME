#pragma once
#include "Observer.h"
#include <vector>
#include <memory>
#include <SFML/Window.hpp>

using Subscriber=std::shared_ptr<class Observer>;

class InputHandler
{
public:
	void Subscribe(Subscriber Sub);
	void HandleInput();
	std::vector<Subscriber> Subs;
private:
	void notify(Keyboard::Keys Key);
};

