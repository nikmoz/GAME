#include "AutoIncrementer.h"
template<typename ValueType>
AutoIncrementer<ValueType>::AutoIncrementer(ValueType& BeginValue, ValueType EndValue, ValueType Increment
                                                        ): CurrentValue_(BeginValue),
                                                                             EndValue_(EndValue), Increment_(Increment)
{
};
template<typename ValueType>
void AutoIncrementer<ValueType>::Update()
{
	if (CurrentValue_<EndValue_)
	{
		Increment_(CurrentValue_);
	}
	else
	{
		IsActive_=false;
	}
};