#pragma once
#include "Action.h"
class NameAction :public Action
{
public:
	void execute(Hero& actor) override;
	~NameAction()=default;
};

