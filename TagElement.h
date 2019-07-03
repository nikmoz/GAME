#pragma once
#include "Element.h"
#include<string>
#include<vector>
class TagElement
{
private:
	TagElement* Parent_;
	std::vector<TagElement*> Children_;
	std::string Name_;
	std::string InnerText_;
public:
	void SetInnerText(const std::string& InnerText);
	std::string GetInnerText() const;

	std::string GetName() const;

	void AddChild(TagElement* Child);
	std::vector<TagElement*> GetChild() const;

	TagElement* GetParent()const;

	TagElement(TagElement* Parent,std::string Name);
};

