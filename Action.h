#pragma once
#include "Hero.h"
class Action
{
public:
	virtual ~Action() {};
	virtual void execute(Hero& actor) = 0;
};

