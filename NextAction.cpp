#include "NextAction.h"

void NextAction::Execute(Hero& Actor)
{
	Actor.CurrentAction++;
	if (Actor.CurrentAction>=Actor.Actions.size())
	{
		Actor.CurrentAction=0;
	}
}
