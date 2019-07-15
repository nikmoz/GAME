#pragma once
#include "Action.h"
class ExecuteAction final :
	public Action
{
	void Execute(Hero& Actor) override;
};

