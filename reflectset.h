#pragma once
#include <type_traits>
#include <string>

namespace reflect
{
	template <class CLS, class VAL>
	bool set_value(CLS &cls, const char *argu, const VAL &val)
	{
		auto o = get_info(cls, argu);
		if (strcmp(o.type, typeid(val).name()) == 0)
		{
			using T = std::remove_const_t<VAL>;
			*((T *)(o.pointer)) = val;
			return true;
		}
		return false;
	}
}