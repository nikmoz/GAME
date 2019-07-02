#include "TagElement.h"
TagElement::TagElement(TagElement* parent, std::string name) :parent(parent), name(std::move(name)) {};
void TagElement::setInnerText(const std::string& InnerText) {
	this->InnerText = InnerText;
}
void TagElement::addChild(TagElement* Child) {
	this->children.push_back(Child);
}
TagElement* TagElement::getParent() const {
	return this->parent;
}
std::vector<TagElement*> TagElement::getChild() const {
	return this->children;
}
std::string TagElement::getInnerText() const {
	return this->InnerText;
}
std::string TagElement::getname() const {
	return this->name;
}