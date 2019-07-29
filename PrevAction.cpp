#include "PrevAction.h"

void PrevAction::Execute(Hero& Actor)
{

	if (Actor.CurrentAction==0)
	{
		Actor.CurrentAction=Actor.Actions.size();
	}
	else
	{
		Actor.CurrentAction--;
	}
}
