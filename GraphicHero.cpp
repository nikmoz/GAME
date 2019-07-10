#include "GraphicHero.h"

#include  <iostream>
GraphicHero::GraphicHero(const std::string& FilePath)
{
	std::ifstream GraphicFile;
	GraphicFile.open(FilePath);

	const auto TexturePath=TagXmlParser::FindTag<std::string>(GraphicFile,"TexturePath");

	AnimationDuration_=TagXmlParser::FindTag<int>(GraphicFile,"AnimationDuration");
	AnimationFrames_=TagXmlParser::FindTag<int>(GraphicFile,"AnimationFrames");
	SpriteSpacing_=TagXmlParser::FindTag<int>(GraphicFile,"SpriteSpacing");

	const auto Left=TagXmlParser::FindTag<int>(GraphicFile,"Left");
	const auto Top=TagXmlParser::FindTag<int>(GraphicFile,"Top");
	const auto Width=TagXmlParser::FindTag<int>(GraphicFile,"Width");
	const auto Height=TagXmlParser::FindTag<int>(GraphicFile,"Height");

	StartRect_=sf::IntRect(Left, Top, Width, Height);

	this->Texture_.loadFromFile(TexturePath);
	this->Sprite.setTexture(this->Texture_);
	this->Sprite.setTextureRect(StartRect_);

	EndRect_=StartRect_.left+(StartRect_.width+SpriteSpacing_)*AnimationFrames_;

	GraphicFile.close();
}

GraphicHero::GraphicHero(std::ifstream& GraphicFile)
{
	const auto TexturePath=TagXmlParser::FindTag<std::string>(GraphicFile,"TexturePath");

	AnimationDuration_=TagXmlParser::FindTag<double>(GraphicFile,"AnimationDuration");
	AnimationFrames_=TagXmlParser::FindTag<int>(GraphicFile,"AnimationFrames");
	SpriteSpacing_=TagXmlParser::FindTag<int>(GraphicFile,"SpriteSpacing");

	const auto Left=TagXmlParser::FindTag<int>(GraphicFile,"Left");
	const auto Top=TagXmlParser::FindTag<int>(GraphicFile,"Top");
	const auto Width=TagXmlParser::FindTag<int>(GraphicFile,"Width");
	const auto Height=TagXmlParser::FindTag<int>(GraphicFile,"Height");

	StartRect_=sf::IntRect(Left, Top, Width, Height);

	this->Texture_.loadFromFile(TexturePath);
	this->Sprite.setTexture(this->Texture_);
	this->Sprite.setTextureRect(StartRect_);

	EndRect_=StartRect_.left+(StartRect_.width+SpriteSpacing_)*AnimationFrames_;

	GraphicFile.close();
}


void GraphicHero::Update()
{
    NewTime_=clock()/1000.0;
		
	if (NewTime_-OldTime_>=AnimationDuration_/static_cast<double>(AnimationFrames_))
	{

		OldTime_=NewTime_;
		const sf::IntRect NextRect(Sprite.getTextureRect().left + Sprite.getTextureRect().width + SpriteSpacing_,
			                     Sprite.getTextureRect().top, Sprite.getTextureRect().width,
			                     Sprite.getTextureRect().height);
		if (NextRect.left>=EndRect_)
		{
			Sprite.setTextureRect(StartRect_);

		}
		else
		{
			Sprite.setTextureRect(NextRect);
		}
	}
}