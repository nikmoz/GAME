#include "DOMParser.h"
TagElement* DomParser::Root_ = nullptr;
TagElement* DomParser::CurrentElement_ = nullptr;
std::stack<std::string> DomParser::Tags_ = {};
TagElement* DomParser::StartParsing(const std::string& FileName) {
	std::string TmpS;
	std::smatch Matches;
	std::regex StartTag("<[a-zA-z]+>");
	std::regex EndTag("</[a-zA-z]+>");
	std::regex Content("[0-9]+");
	std::ifstream MyFile;
	MyFile.open(FileName);
	getline(MyFile, TmpS);
	while (getline(MyFile, TmpS))
	{
		std::regex_search(TmpS, Matches, StartTag);
		if (!Matches.empty()) {
			FoundStart(Matches[0]);
		}
		regex_search(TmpS, Matches, Content);
		if (!Matches.empty()) {
			FoundContent(Matches[0]);
		}
		regex_search(TmpS, Matches, EndTag);
		if (!Matches.empty()) {
			FoundEnd(Matches[0]);
		}
	}
	if (!Tags_.empty()) {
		throw ExceptionHandler("Some tags aren't closed");
	};
	MyFile.close();
	return Root_;
};

std::string DomParser::GetTagName(const std::string& Tag) {
	std::smatch TagName;
	const std::regex RegName("[a-zA-z]+");
	regex_search(Tag, TagName, RegName);
	return TagName[0];
};

void DomParser::FoundStart(const std::string& Tag)
{
	const auto TagName = GetTagName(Tag);
	Tags_.push(TagName);
	if (Root_ == nullptr) {
		Root_ = new TagElement(Root_, TagName);
		CurrentElement_ = Root_;
	}
	else {
		const auto Tmp = new TagElement(CurrentElement_, TagName);
		CurrentElement_->AddChild(Tmp);
		CurrentElement_ = Tmp;
	}
};

void DomParser::FoundEnd(const std::string& Tag)
{
	const auto TagName = GetTagName(Tag);
	if (Tags_.top() == TagName) {
		Tags_.pop();
		CurrentElement_ = CurrentElement_->GetParent();
	}
	else
	{
		throw ExceptionHandler("Wrong tag order");
	}
};

void DomParser::FoundContent(const std::string& Content) {
	CurrentElement_->SetInnerText(Content);
};

