#pragma once
#include<string>
#include <iostream>
#include <fstream>
#include <regex>
#include <stack>
#include "TagElement.h"
#include "ExeptionHandler.h"
class DOMParser {
private:
	TagElement* Root = nullptr;
	TagElement* CurrentElement = nullptr;
	std::stack<std::string> Tags = {};
	void FoundStart(const std::string& Tag);
	void FoundEnd(const std::string& Tag);
	void FoundContent(const std::string& Content);
	static std::string GetTagName(const std::string& Tag);
public:
	TagElement* StartParsing(std::string FileName);
};

