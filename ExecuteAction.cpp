#include "ExecuteAction.h"

void ExecuteAction::Execute(Hero& Actor)
{
	Actor.Actions[Actor.CurrentAction]->Execute(Actor);
}
