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
	static TagElement* Root;
	static TagElement* CurrentElement;
	static std::stack<std::string> Tags;
	static void FoundStart(const std::string& Tag);
	static void FoundEnd(const std::string& Tag);
	static void FoundContent(const std::string& Content);
	static std::string GetTagName(const std::string& Tag);
public:
	static TagElement* StartParsing(const std::string& FileName);
};

