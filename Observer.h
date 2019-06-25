#pragma once
namespace Keyboard {
	enum Keys{Up,Down,Left,Right,Enter};
}
class Observer
{
public:
	virtual ~Observer() = default;
	virtual void update(Keyboard::Keys Key) = 0;
};

