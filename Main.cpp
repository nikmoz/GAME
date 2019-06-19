#include "Scene.h"
#include "Hero.h"
#include <thread>
using namespace std;
int main() {
	Scene* Test=new Scene(400,400);
	shared_ptr<Hero> Uther(new Hero("res/img/sprite_base_addon_2012_12_14.png",sf::IntRect(10,10,70,70),HeroeDefs::hero));
	shared_ptr<Hero> AUther(new Hero("res/img/sprite_base_addon_2012_12_14.png", sf::IntRect(10, 10, 70, 70), HeroeDefs::enemy));

	Test->AddCharacter(move(Uther));
	Test->AddCharacter(move(AUther));
	std::thread GUI(&Scene::RenderScene, Test);
	GUI.join();


	return 0;
}