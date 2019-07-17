#include "Hero.h"

#include "NameAction.h"
#include "SideAction.h"
#include "TargetAction.h"

Hero::Hero(const std::string& FileName)
{
	std::ifstream HeroFile;
	HeroFile.open(FileName);

	Name=TagXmlParser::FindTag<std::string>(HeroFile,"Name");

	const auto SideString=TagXmlParser::FindTag<std::string>(HeroFile,"Side");
	if (SideString=="Hero")
	{
		Side=HeroDef::Hero;
	}
	else if(SideString=="Enemy")
	{
		Side=HeroDef::Enemy;
	}

	Graphic = std::make_shared<GraphicHero>(HeroFile);

	auto Skills=TagXmlParser::FindAllTags<std::string>(HeroFile,"Action");
	for (const auto& Skill:Skills)//TODO(Nick):Create map for Actions
	{
		if(Skill=="NameAction")
		{
			Actions.push_back(HeroDef::ActionPtr(new NameAction));
		}
		else if(Skill=="SideAction")
		{
			Actions.push_back(HeroDef::ActionPtr(new SideAction));
		}
		else if(Skill=="TargetAction")
		{
			Actions.push_back(HeroDef::ActionPtr(new TargetAction));
		}
	}
	HeroFile.close();
}

