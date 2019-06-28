#pragma once
#include "Observer.h"
#include <vector>
#include <memory>
#include <SFML/Window.hpp>
using Subscriber=std::shared_ptr<Observer>;
class InputHandler
{
public:
	static void Subscribe(Subscriber Sub);
	static void HandleInput();
private:
	static void notify(Keyboard::Keys Key);
	static std::vector<Subscriber> Subs;
};

