#include "GraphicHero.h"

GraphicHero::GraphicHero(const std::string& FilePath)
{
	std::ifstream GraphicFile;
	GraphicFile.open(FilePath);

	const auto TexturePath=TagXmlParser::FindTag<std::string>(GraphicFile,"TexturePath");

	std::pair<AnimationState,std::string> IdleAnim(AnimationState::Idle,TagXmlParser::FindTag<std::string>(GraphicFile,"Idle"));
	AnimationMap_.emplace(IdleAnim);

	std::pair<AnimationState,std::string> ChosenAnim(AnimationState::Chosen,TagXmlParser::FindTag<std::string>(GraphicFile,"Chosen"));
	AnimationMap_.emplace(ChosenAnim);
	
	LoadAnimation(AnimationState::Idle);

	this->Texture_.loadFromFile(TexturePath);
	this->Sprite.setTexture(this->Texture_);


	GraphicFile.close();
}

GraphicHero::GraphicHero(std::ifstream& GraphicFile)
{
	const auto TexturePath=TagXmlParser::FindTag<std::string>(GraphicFile,"TexturePath");

	std::pair<AnimationState,std::string> IdleAnim(AnimationState::Idle,TagXmlParser::FindTag<std::string>(GraphicFile,"Idle"));
	AnimationMap_.emplace(IdleAnim);

	std::pair<AnimationState,std::string> ChosenAnim(AnimationState::Chosen,TagXmlParser::FindTag<std::string>(GraphicFile,"Chosen"));
	AnimationMap_.emplace(ChosenAnim);

	LoadAnimation(AnimationState::Idle);

	this->Texture_.loadFromFile(TexturePath);
	this->Sprite.setTexture(this->Texture_);

	GraphicFile.close();
}


void GraphicHero::LoadAnimation(const AnimationState Animation)
{
	std::ifstream AnimationFile;
	AnimationFile.open(AnimationMap_[Animation]);

	AnimationDuration_=TagXmlParser::FindTag<double>(AnimationFile,"AnimationDuration");
	AnimationFrames_=TagXmlParser::FindTag<int>(AnimationFile,"AnimationFrames");
	SpriteSpacing_=TagXmlParser::FindTag<int>(AnimationFile,"SpriteSpacing");

	const auto Left=TagXmlParser::FindTag<int>(AnimationFile,"Left");
	const auto Top=TagXmlParser::FindTag<int>(AnimationFile,"Top");
	const auto Width=TagXmlParser::FindTag<int>(AnimationFile,"Width");
	const auto Height=TagXmlParser::FindTag<int>(AnimationFile,"Height");

	SpriteRect_=sf::IntRect(Left, Top, Width, Height);

	this->Sprite.setTextureRect(SpriteRect_);

	EndRect_=SpriteRect_.left+(SpriteRect_.width+SpriteSpacing_)*AnimationFrames_;

	CurrentAnimation_=Animation;

	AnimationFile.close();
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
			Sprite.setTextureRect(SpriteRect_);

		}
		else
		{
			Sprite.setTextureRect(NextRect);
		}
	}
}
