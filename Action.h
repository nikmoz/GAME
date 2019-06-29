#pragma once
#include "Game.h"
#include "Hero.h"
#include <iostream>

class Action
{
public:
	
	~Action()=default;

	bool IsResolved = false;
	virtual void execute(Hero& actor)=0;
};

