#include "StateNode.h"
template <typename SignalType, typename ContentType>
StateNode<SignalType, ContentType>::StateNode(ContentType Content): Content(Content)
{
}

template <typename SignalType, typename ContentType>
void StateNode<SignalType, ContentType>::AddConnection(std::pair<SignalType, StateNode>&& Connection)
{
	Connections_.emplace(std::move(Connection));
}

template <typename SignalType, typename ContentType>
StateNode<SignalType, ContentType> StateNode<SignalType, ContentType>::GetNextNode(SignalType Signal)
{
	if (Connections_.find(Signal)!= Connections_.end())
	{
		return Connections_[Signal];
	}
	return *this;
}
