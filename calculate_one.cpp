#include "types.hpp"

#include <span>

unsigned int
calc_dynamic_pointer_cast(std::span< value_provider_shptr > providers, unsigned iterations)
{
	unsigned int result = 0;

	for(unsigned int i = 0; i < iterations; ++i)
	{
		for(const auto & vp_shptr : providers)
		{
			const auto second_shptr = std::dynamic_pointer_cast<second_provider>(vp_shptr);
			if(second_shptr)
			{
				result += second_shptr->get_n();
			}
		}
	}

	return result;
}

