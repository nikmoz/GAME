#pragma once
#include  <functional>

template<typename ValueType>
class AutoIncrementer
{
public:
	AutoIncrementer(ValueType& BeginValue,ValueType EndValue,ValueType Increment);
	void Update();
private:
	ValueType& CurrentValue_;
	ValueType EndValue_;
	std::function<void(ValueType&)> Increment_;
	bool IsActive_=true;
};

