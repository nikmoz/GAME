#pragma once
#include "Action.h"

class NameAction :public Action
{
public:
	~NameAction()=default;
	void execute(Hero& actor) override;
};

