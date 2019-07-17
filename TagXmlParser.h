#pragma once
#include <fstream>
#include <regex>
#include  <string>
#include  <vector>

namespace TagXmlParser
{
	const std::regex TagRegex("<[^>]+>|\\n>");
	template <typename TagContent>
	TagContent FindTag(std::ifstream& File, const std::string& TagName)
	{
		const auto Tag="<"+TagName+">";

		File.clear();
		File.seekg(0, std::ifstream::beg);

		std::smatch Matches;

		std::string FileLine;
		while (getline(File, FileLine))
		{
			std::regex_search(FileLine, Matches,TagRegex);
			if (!Matches.empty()&& Matches[0]==Tag)
			{
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
		const auto Tag="<"+TagName+">";

		File.clear();
		File.seekg(0, File.beg);

		std::smatch Matches;
		std::vector<TagContent> FoundContent={};

		std::string  FileLine;
		while (getline(File, FileLine))
		{
			std::regex_search(FileLine, Matches,TagRegex);
			if (!Matches.empty()&& Matches[0]==Tag)
			{
				TagContent Tmp;
				File>>Tmp;
				FoundContent.push_back(Tmp);
			}
		}

		return FoundContent;
	};//Find all tag entries 
}


