#include "GraphicHero.h"

#include  <iostream>
GraphicHero::GraphicHero(const std::string& FilePath)
{
	std::ifstream GraphicFile;
	GraphicFile.open(FilePath);

	auto TexturePath=TagXmlParser::FindTag<std::string>(GraphicFile,"TexturePath");

	AnimationDuration_=TagXmlParser::FindTag<int>(GraphicFile,"AnimationDuration");
	AnimationFrames_=TagXmlParser::FindTag<int>(GraphicFile,"AnimationFrames");
	SpriteSpacing_=TagXmlParser::FindTag<int>(GraphicFile,"SpriteSpacing");

	auto Left=TagXmlParser::FindTag<int>(GraphicFile,"Left");
	auto Top=TagXmlParser::FindTag<int>(GraphicFile,"Top");
	auto Width=TagXmlParser::FindTag<int>(GraphicFile,"Width");
	auto Height=TagXmlParser::FindTag<int>(GraphicFile,"Height");

	StartRect_=sf::IntRect(Left, Top, Width, Height);

	this->Texture_.loadFromFile(TexturePath);
	this->Sprite.setTexture(this->Texture_);
	this->Sprite.setTextureRect(StartRect_);

	EndRect_=StartRect_.left+(StartRect_.width+SpriteSpacing_)*AnimationFrames_;

	GraphicFile.close();
}
/*THEME(Nick):Animation()
{
	Problem 1: How to iterate through sprite sheet? Different sprites have different sizes, and space between two in one sprite sheet is different. 
	Problem 2: Different animation duration.
	Solution 1:
	Google this
}
*/
void GraphicHero::Update()
{
	if (Sprite.getTextureRect().left>=EndRect_)
	{
		Sprite.setTextureRect(StartRect_);
	}
	else
	{

		const sf::IntRect NextRect(Sprite.getTextureRect().left + Sprite.getTextureRect().width + SpriteSpacing_,
		                     Sprite.getTextureRect().top, Sprite.getTextureRect().width,
		                     Sprite.getTextureRect().height);
		Sprite.setTextureRect(NextRect);
	}
}



