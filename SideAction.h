#pragma once
#include "Action.h"

class SideAction :public Action
{
public:
	~SideAction()=default;
	void execute(Hero& actor) override;

};

