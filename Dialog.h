#pragma once
#include "SFML/Graphics/Text.hpp"
#include "Graphic.h"
#include "TagXMLParser.h"
class Dialog final : public Graphic
{
public:
	explicit Dialog(std::string Text);

	void Render(sf::RenderWindow& WindowScene) override;
	void Update() override;
	sf::Text Text;

	bool LineDone=false;
private:
	double OldTime_=0;
	double NewTime_=0;

	sf::Font Font_;
	std::string Line_;
};

