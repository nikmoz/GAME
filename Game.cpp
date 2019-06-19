#include "Game.h"
using std::shared_ptr;
std::vector<std::shared_ptr<Hero>> Game::Characters = {};
void Game::AddCharacter(shared_ptr<Hero> Character) {
	Game::Characters.push_back(Character);
};
