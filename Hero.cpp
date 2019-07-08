#include "Hero.h"


Hero::Hero(const std::string& FileName)
{
	std::ifstream HeroFile;
	HeroFile.open(FileName);

	Name=TagXmlParser::FindTag<std::string>(HeroFile,"Name");

	const auto SideString=TagXmlParser::FindTag<std::string>(HeroFile,"Side");
	if (SideString=="Hero")
	{
		Side=HeroDefinitions::Hero;
	}
	else if(SideString=="Enemy")
	{
		Side=HeroDefinitions::Enemy;
	}



	Graphic = std::make_unique<GraphicHero>(FileName);

	HeroFile.close();
}



