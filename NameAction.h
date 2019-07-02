#pragma once
#include "Action.h"
#include <iostream>

class NameAction final : public Action
{
public:
	~NameAction() = default;
	void Execute(Hero& Actor) override;
};
