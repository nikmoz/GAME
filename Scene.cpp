#include "Scene.h"
using std::move;
using std::shared_ptr;


void Scene::AddCharacter(shared_ptr<Hero> Character) {
	this->Characters.push_back(move(Character));
};