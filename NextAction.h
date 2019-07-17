#pragma once
#include "Action.h"
class NextAction final :
	public Action
{
	void Execute(Hero& Actor) override;
};

