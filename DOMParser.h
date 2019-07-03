#pragma once
#include<string>
#include <iostream>
#include <fstream>
#include <regex>
#include <stack>
#include "TagElement.h"
#include "ExceptionHandler.h"
class DomParser {
private:
	static TagElement* Root_;
	static TagElement* CurrentElement_;
	static std::stack<std::string> Tags_;
	static void FoundStart(const std::string& Tag);
	static void FoundEnd(const std::string& Tag);
	static void FoundContent(const std::string& Content);
	static std::string GetTagName(const std::string& Tag);
public:
	static TagElement* StartParsing(const std::string& FileName);
};

