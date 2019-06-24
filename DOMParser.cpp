#include "DOMParser.h"
TagElement* DOMParser::StartParsing(std::string FileName) {
	std::string TmpS;
	std::smatch matches;
	std::regex StartTag("<[a-zA-z]+>");
	std::regex EndTag("</[a-zA-z]+>");
	std::regex Content("[0-9]+");
	std::ifstream myfile;
	myfile.open(FileName);
	getline(myfile, TmpS);
	while (getline(myfile, TmpS))
	{
		std::regex_search(TmpS, matches, StartTag);
		if (!matches.empty()) {
			FoundStart(matches[0]);
		}
		regex_search(TmpS, matches, Content);
		if (!matches.empty()) {
			FoundContent(matches[0]);
		}
		regex_search(TmpS, matches, EndTag);
		if (!matches.empty()) {
			FoundEnd(matches[0]);
		}
	}
	if (!Tags.empty()) {
		throw new ExeptionHandler("Some tags aren't closed");
	};
	myfile.close();
	return Root;
};

std::string DOMParser::GetTagName(const std::string& Tag) {
	std::smatch TagName;
	std::regex RegName("[a-zA-z]+");
	regex_search(Tag, TagName, RegName);
	return TagName[0];
};

void DOMParser::FoundStart(const std::string& Tag)
{
	std::string TagName = GetTagName(Tag);
	Tags.push(TagName);
	if (Root == nullptr) {
		Root = new TagElement(Root, TagName);
		CurrentElement = Root;
	}
	else {
		TagElement* TMP = new TagElement(CurrentElement, TagName);
		CurrentElement->addChild(TMP);
		CurrentElement = TMP;
	}
};

void DOMParser::FoundEnd(const std::string& Tag)
{
	std::string TagName = GetTagName(Tag);
	if (Tags.top() == TagName) {
		Tags.pop();
		CurrentElement = CurrentElement->getParent();
	}
	else
	{
		throw new ExeptionHandler("Wrong tag order");
	}
};

void DOMParser::FoundContent(const std::string& Content) {
	CurrentElement->setInnerText(Content);
};

