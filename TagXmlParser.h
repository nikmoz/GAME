#pragma once
#include <fstream>
#include <regex>
#include  <string>
#include  <vector>

namespace TagXmlParser
{
	template <typename TagContent>
	TagContent FindTag(std::ifstream& File, const std::string& TagName)
	{
		File.clear();
		File.seekg(0, std::ifstream::beg);

		std::smatch Matches;
		const std::regex Tag("<"+TagName+">");//NOTE(Nick):Check if regex is expensive to create

		std::string FileLine;
		while (getline(File, FileLine))
		{
			std::regex_search(FileLine, Matches,Tag);
			if (!Matches.empty()) {
				TagContent Tmp;
				File>>Tmp;

				return Tmp;
			}
		}

		return TagContent();
	};//Finds first tag entry 

	template <typename TagContent>
	std::vector<TagContent> FindAllTags(std::ifstream& File, const std::string& TagName)
	{
		File.clear();
		File.seekg(0, File.beg);

		std::smatch Matches;
		const std::regex Tag("<"+TagName+">");//NOTE(Nick):Check if regex is expensive to create
		std::vector<TagContent> FoundContent={};

		std::string  FileLine;
		while (getline(File, FileLine))
		{
			std::regex_search(FileLine, Matches,Tag);
			if (!Matches.empty()) {
				TagContent Tmp;
				File>>Tmp;
				FoundContent.push_back(Tmp);
			}
		}

		return FoundContent;
	};//Find all tag entries 
}


