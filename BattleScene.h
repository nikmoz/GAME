#pragma once
#include "Hero.h"
#include "Scene.h"
#include "Observer.h"

#include "TagXMLParser.h"

#include <optional>

namespace BattleSceneDef
{
	using ActionPtr=std::shared_ptr<class Action>;
}

class BattleScene final :public Scene
{
public:
	
	BattleScene();
	~BattleScene() = default;


	void Load(std::string_view FileName) override;

	void UpdateScene(sf::Keyboard::Key Key) override; //Calculates scene next state

	void Unload() override {};
	inline void Redraw() override;

	inline void AddCharacter(SceneDef::TargetPtr&& Character) noexcept;

private:

	unsigned int CurrentAction_ = 0;

	unsigned int CurrentChar_ = 0;

	void SetupCharactersPosition() noexcept;

	std::shared_ptr<class InputHandler> TurnInputHandler_;

	std::optional<unsigned int> ChooseAction(sf::Keyboard::Key Key);

};



