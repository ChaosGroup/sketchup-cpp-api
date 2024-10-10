#pragma once

template<typename T>
class TypeOf
{
public:
	virtual operator T() = 0;
};
