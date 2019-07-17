#include "Game.h"

//#include <iostream>
//#include "StateMachine.cpp"
//#include <string>
int main()
{
	Game::InitScene();
	Game::StartGame();


	//StateMachine<std::string, int> IntStateMachine(1);
	//
	//IntStateMachine.AddNode(2);
	//IntStateMachine.AddConnection(1, 2, "Hm");
	//
	//std::cout << "Current Node:" << IntStateMachine.GetCurrentNodeContent() << std::endl;
	//
	//IntStateMachine.GetNextNode("Heh?");
	//std::cout << "New node(wrong signal):" << IntStateMachine.GetCurrentNodeContent() << std::endl;
	//
	//IntStateMachine.GetNextNode("Hm");
	//std::cout << "New node(normal signal):" << IntStateMachine.GetCurrentNodeContent() << std::endl;

	return 0;
}
