#pragma once
#include <list>
class Element {
public:
	Element* Parent;
	std::list<Element*> Children;
};