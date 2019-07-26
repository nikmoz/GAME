#include "Dialog.h"
#include <utility>

Dialog::Dialog(std::string Text)
{
	Line_= std::move(Text);

	Font_.loadFromFile("res/fonts/arial.ttf");
	this->Text.setFont(Font_);
	this->Text.setString(Line_[0]);
	this->Text.setCharacterSize(12);
	this->Text.setFillColor(sf::Color::White);

	this->Text.setPosition(50,150);//TODO:Create Parent-Child system for binding with Hero or Menu
}

void Dialog::Render(sf::RenderWindow& WindowScene)
{
	WindowScene.draw(Text);
}

void Dialog::Update()
{
	static auto I(0U);//TODO:Create generator

	NewTime_=clock()/1000.0;
	if (NewTime_-OldTime_>0.01){
		OldTime_=NewTime_;
		I++;
		if(I<Line_.size())
		{
			const auto NowTime=static_cast<std::string>(this->Text.getString());
			this->Text.setString(NowTime+Line_[I]);
		}
		else
		{
			//LineDone=true;
		}
	}
}
