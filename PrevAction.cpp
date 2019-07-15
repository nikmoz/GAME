#include "PrevAction.h"

void PrevAction::Execute(Hero& Actor)
{
	Actor.CurrentAction--;
	if (Actor.CurrentAction<0)
	{
		Actor.CurrentAction=Actor.Actions.size();
	}
}
