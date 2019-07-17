#include "StateMachine.h"
template <typename SignalType, typename ContentType>
StateMachine<SignalType, ContentType>::StateMachine(ContentType StartNode)
{
	CurrentNode_=StateNode<SignalType, ContentType>(StartNode);
	Nodes_.push_back(&CurrentNode_);
}

template <typename SignalType, typename ContentType>
void StateMachine<SignalType, ContentType>::AddNode(ContentType Content)
{
	if (FindNode(Content) == nullptr)
	{
		Nodes_.push_back(new StateNode<SignalType, ContentType>(Content));
	}
}

template <typename SignalType, typename ContentType>
void StateMachine<SignalType, ContentType>::AddConnection(ContentType FromNode, ContentType ToNode, SignalType Signal)
{
	auto From = FindNode(FromNode);
	auto To = FindNode(ToNode);

	if((From!=nullptr)&&(To!=nullptr))
	{
		From->AddConnection(std::pair<SignalType, StateNode<SignalType, ContentType>>(Signal, *To));
	}
}

template <typename SignalType, typename ContentType>
StateNode<SignalType, ContentType>* StateMachine<SignalType, ContentType>::FindNode(ContentType Content)
{
	for (auto& Node : Nodes_)
	{
		if (Node->Content == Content)
		{
			return Node;
		}
	}
	return  nullptr;
}

template <typename SignalType, typename ContentType>
ContentType StateMachine<SignalType, ContentType>::GetNextNode(SignalType Signal)
{
	CurrentNode_ = CurrentNode_.GetNextNode(Signal);
	return CurrentNode_.Content;
}

template <typename SignalType, typename ContentType>
ContentType StateMachine<SignalType, ContentType>::GetCurrentNodeContent()
{
	return CurrentNode_.Content;
}
