#include "TagElement.h"
TagElement::TagElement(TagElement* Parent, std::string Name) :Parent_(Parent), Name_(std::move(Name)) {};
void TagElement::SetInnerText(const std::string& InnerText) {
	this->InnerText_ = InnerText;
}
void TagElement::AddChild(TagElement* Child) {
	this->Children_.push_back(Child);
}
TagElement* TagElement::GetParent() const {
	return this->Parent_;
}
std::vector<TagElement*> TagElement::GetChild() const {
	return this->Children_;
}
std::string TagElement::GetInnerText() const {
	return this->InnerText_;
}
std::string TagElement::GetName() const {
	return this->Name_;
}