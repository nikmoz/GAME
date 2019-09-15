#pragma once
#include <optional>
#include "Scene.h"
#include "Observer.h"
#include "Hero.h"
#include "TargetAction.h"

class Hero;

namespace TargetSceneDef
{
	using TargetPtr = std::shared_ptr<Hero>;	
}

class TargetScene final :
	public Scene
{
public:
	explicit TargetScene(std::vector<TargetSceneDef::TargetPtr> Targets,std::shared_ptr<class TargetAction> Action, Hero& Actor);
	TargetScene(const TargetScene& Target);
	~TargetScene()=default;


	inline void UpdateScene(sf::Keyboard::Key Key) override;
	inline void Redraw() override;
	inline void Load(std::string_view FileName) override;
	inline void Unload() override;
private:
	std::optional<int> ChooseTarget(sf::Keyboard::Key Key);

	Hero& Actor_;

	std::shared_ptr<class TargetAction> Action_;

	int CurrentTarget_ = 0;
}; 

