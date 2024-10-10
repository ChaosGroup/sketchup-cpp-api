#pragma once

template<typename T>
class Makable: public RubyUtils::details::IObject
{
protected:
	using bitmask_t = T;
	bitmask_t bitmask;
	inline Makable(bitmask_t bitmask) : IObject(Qnil), bitmask(bitmask) {}
	virtual ~Makable() = default;
	virtual inline void bind(VALUE) = 0;
};
