#pragma once
#include "Action.h"
class PrevAction final :
	public Action
{
	void Execute(Hero& Actor) override;
};

