#pragma once
#include "SFML/Graphics/Text.hpp"

#include "TagXMLParser.h"
class Dialog
{
public:
	explicit Dialog(std::string Text);
	void Update();
	sf::Text Text;

	bool LineDone=false;
private:
	double OldTime_=0;
	double NewTime_=0;

	sf::Font Font_;
	std::string Line_;
};

