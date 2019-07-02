#pragma once

#include "Hero.h"


class Action
{
public:

	Action() = default;
	Action(Action&) = default;

	virtual ~Action() = default;

	bool IsResolved = false;
	virtual void Execute(Hero& Actor) =0;
};
