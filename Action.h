#pragma once
#include "Hero.h"
#include <iostream>
#include "Game.h"
class Action
{
public:
	virtual ~Action() {};
	virtual void execute(Hero& actor)=0;
};

