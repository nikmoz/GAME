#pragma once
//#include "Game.h"
#include "Hero.h"
#include <iostream>
class Action
{
public:
	virtual ~Action()=default;
	virtual void execute(Hero& actor)=0;
};

