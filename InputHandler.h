#pragma once
#include "Observer.h"
#include <vector>
#include <SFML/Window.hpp>
class InputHandler
{
public:
	static void HandleInput();
private:
	static void notify(Keyboard::Keys Key);
	static std::vector<class Observer> Subs;
};

