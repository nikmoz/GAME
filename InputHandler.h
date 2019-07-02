#pragma once
#include "Observer.h"
#include <vector>
#include <memory>
#include <SFML/Window.hpp>

using Subscriber=std::shared_ptr<class Observer>;

class InputHandler
{
public:
	void Subscribe(const Subscriber& Sub);
	void HandleInput();
	std::vector<Subscriber> Subs;
private:
	void Notify(Keyboard::Keys Key);
};

