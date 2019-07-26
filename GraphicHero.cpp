#include "GraphicHero.h"

GraphicHero::GraphicHero(const std::string& FilePath)
{
	std::ifstream GraphicFile;
	GraphicFile.open(FilePath);

	Animation_=std::make_shared<AnimationData>();

	const auto TexturePath=TagXmlParser::FindTag<std::string>(GraphicFile,"TexturePath");

	std::pair<AnimationState,std::string> IdleAnim(AnimationState::Idle,TagXmlParser::FindTag<std::string>(GraphicFile,"Idle"));
	AnimationMap_.emplace(IdleAnim);

	std::pair<AnimationState,std::string> ChosenAnim(AnimationState::Chosen,TagXmlParser::FindTag<std::string>(GraphicFile,"Chosen"));
	AnimationMap_.emplace(ChosenAnim);
	
	LoadAnimation(AnimationState::Idle);

	this->Animation_->Texture.loadFromFile(TexturePath);
	this->Sprite.setTexture(this->Animation_->Texture);


	GraphicFile.close();
}

GraphicHero::GraphicHero(std::ifstream& GraphicFile)
{
	Animation_=std::make_shared<AnimationData>();

	const auto TexturePath=TagXmlParser::FindTag<std::string>(GraphicFile,"TexturePath");

	std::pair<AnimationState,std::string> IdleAnim(AnimationState::Idle,TagXmlParser::FindTag<std::string>(GraphicFile,"Idle"));
	AnimationMap_.emplace(IdleAnim);

	std::pair<AnimationState,std::string> ChosenAnim(AnimationState::Chosen,TagXmlParser::FindTag<std::string>(GraphicFile,"Chosen"));
	AnimationMap_.emplace(ChosenAnim);

	LoadAnimation(AnimationState::Idle);

	this->Animation_->Texture.loadFromFile(TexturePath);
	this->Sprite.setTexture(this->Animation_->Texture);

	//GraphicFile.close();
}

void GraphicHero::Render(sf::RenderWindow& WindowScene)
{
	WindowScene.draw(Sprite);
}


void GraphicHero::LoadAnimation(const AnimationState Animation)
{
	if (CurrentAnimation_!=Animation)
	{
		std::ifstream AnimationFile;
		AnimationFile.open(AnimationMap_[Animation]);

		Animation_->AnimationDuration = TagXmlParser::FindTag<double>(AnimationFile, "AnimationDuration");
		Animation_->AnimationFrames = TagXmlParser::FindTag<int>(AnimationFile, "AnimationFrames");
		Animation_->SpriteSpacing = TagXmlParser::FindTag<int>(AnimationFile, "SpriteSpacing");

		const auto Left = TagXmlParser::FindTag<int>(AnimationFile, "Left");
		const auto Top = TagXmlParser::FindTag<int>(AnimationFile, "Top");
		const auto Width = TagXmlParser::FindTag<int>(AnimationFile, "Width");
		const auto Height = TagXmlParser::FindTag<int>(AnimationFile, "Height");

		SpriteRect_ = sf::IntRect(Left, Top, Width, Height);

		this->Sprite.setTextureRect(SpriteRect_);

		Animation_->EndRect = SpriteRect_.left + (SpriteRect_.width + Animation_->SpriteSpacing) * Animation_->AnimationFrames;

		CurrentAnimation_ = Animation;

		AnimationFile.close();
	}
}

void GraphicHero::Update()
{
    NewTime_=clock()/1000.0;
		
	if (NewTime_-OldTime_>=Animation_->AnimationDuration/static_cast<double>(Animation_->AnimationFrames))
	{

		OldTime_=NewTime_;
		const sf::IntRect NextRect(Sprite.getTextureRect().left + Sprite.getTextureRect().width + Animation_->SpriteSpacing,
			                     Sprite.getTextureRect().top, Sprite.getTextureRect().width,
			                     Sprite.getTextureRect().height);
		if (NextRect.left>=Animation_->EndRect)
		{
			Sprite.setTextureRect(SpriteRect_);

		}
		else
		{
			Sprite.setTextureRect(NextRect);
		}
	}
}
