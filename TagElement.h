#pragma once
#include "Element.h"
#include<string>
#include<vector>
class TagElement
{
private:
	TagElement* parent;
	std::vector<TagElement*> children;
	std::string name;
	std::string InnerText;
public:
	void setInnerText(const std::string& InnerText);
	std::string getInnerText() const;

	std::string getname() const;

	void addChild(TagElement* Child);
	std::vector<TagElement*> getChild() const;

	TagElement* getParent()const;

	TagElement(TagElement* parent,std::string name);
};

