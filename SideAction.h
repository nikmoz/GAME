#pragma once
#include "Action.h"
#include <iostream>

class SideAction final : public Action
{
public:
	~SideAction() = default;
	void Execute(Hero& Actor) override;
};
