#pragma once
#include <map>

template <typename  SignalType, typename  ContentType>
class StateNode
{
public:
	ContentType Content{};

	StateNode()=default;
	explicit StateNode(ContentType Content);;

	void AddConnection(std::pair<SignalType, StateNode>&& Connection);;
	//void DeleteConnection(std::pair<SignalType,StateNode> Connection);//NOTE(Nick):Probably don't need this

	StateNode GetNextNode(SignalType Signal);;
private:
	std::map<SignalType,StateNode> Connections_;
};



