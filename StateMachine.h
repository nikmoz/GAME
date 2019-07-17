#pragma once
#include  <vector>
#include "StateNode.cpp"


template <typename  SignalType, typename  ContentType>
class StateMachine
{
public:

	explicit StateMachine(ContentType StartNode);

	void AddNode(ContentType Content);
	void AddConnection(ContentType FromNode, ContentType ToNode, SignalType Signal);

	StateNode<SignalType, ContentType>* FindNode(ContentType Content);

	ContentType GetNextNode(SignalType Signal);
	ContentType GetCurrentNodeContent();
	
private:
	std::vector<StateNode<SignalType,ContentType>*> Nodes_;
	StateNode<SignalType,ContentType> CurrentNode_;
};






