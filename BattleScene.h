#pragma once
#include "Hero.h"
#include "Scene.h"
#include "Observer.h"
#include "InputHandler.h"

#include "NextAction.h"
#include "PrevAction.h"
#include "ExecuteAction.h"

#include "TagXMLParser.h"

#include <optional>

namespace BattleSceneDef
{
	using ActionPtr=std::shared_ptr<class Action>;
}

class BattleScene final :public Scene,public Observer
{
public:
	
	BattleScene();
	~BattleScene() = default;


	void Load(std::string_view FileName) override;

	void UpdateScene() override; //Calculates scene next state
	inline void Update(sf::Keyboard::Key Key)override;//Reacts to key Input

	void Unload() override {};
	inline void Redraw() override;

	inline void AddCharacter(SceneDef::TargetPtr&& Character) noexcept;

private:
	unsigned int CurrentChar_ = 0;

	void SetupCharactersPosition() noexcept;

	std::shared_ptr<class InputHandler> TurnInputHandler_;

	BattleSceneDef::ActionPtr NextAction_=BattleSceneDef::ActionPtr(new NextAction);
	BattleSceneDef::ActionPtr PrevAction_=BattleSceneDef::ActionPtr(new PrevAction);
	BattleSceneDef::ActionPtr ExecuteAction_=BattleSceneDef::ActionPtr(new ExecuteAction);

	[[nodiscard]] std::optional<BattleSceneDef::ActionPtr> ChooseAction(sf::Keyboard::Key Key) const;

};



