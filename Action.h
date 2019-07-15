#pragma once

#include "Hero.h"

class Hero;

class Action
{
public:
	virtual ~Action() = default;

	bool IsResolved = false;
	virtual void Execute(Hero& Actor) =0;
};
