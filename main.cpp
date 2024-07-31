#include "types.hpp"
#include "duration_meter.hpp"

#include <array>
#include <span>

unsigned int
calc_dynamic_pointer_cast(std::span< value_provider_shptr > providers, unsigned iterations);

unsigned int
calc_dynamic_cast(std::span< value_provider_shptr > providers, unsigned iterations);

int main()
{
	std::array< value_provider_shptr, 10 > providers{
			make_provider(),
			make_provider(),
			make_provider(),
			make_provider(),
			make_provider(),
			make_provider(),
			make_provider(),
			make_provider(),
			make_provider(),
			make_provider()
		};

	unsigned int v1 = measure( "dynamic_pointer_cast", [&providers]() {
			return calc_dynamic_pointer_cast( providers, 1'000'000 );
		} );

	unsigned int v2 = measure( "        dynamic_cast", [&providers]() {
			return calc_dynamic_cast( providers, 1'000'000 );
		} );

	std::cout << "v1: " << v1 << "\n" "v2: " << v2 << std::endl;
}

